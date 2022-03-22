/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:14:32 by hrolle            #+#    #+#             */
/*   Updated: 2022/03/11 20:18:42 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*s2;
	unsigned int	i;
	unsigned int	f_len;

	if (!s)
		return (0);
	f_len = ft_strlen(s);
	if (start >= f_len)
		return (ft_strldup("", 0));
	if (len > f_len - start)
		len = f_len - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

int	read_file(char **line, int fd)
{
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	if (!*line)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (!i)
			return (0);
		*line = ft_strldup(buf, i);
		if (!*line || !i)
			return (0);
	}
	while (!ft_strchr(*line, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (!i)
			return (0);
		tmp = *line;
		*line = ft_strljoin(tmp, buf, i);
		free(tmp);
		if (!*line)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;
	char		*ret_str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!read_file(&line, fd))
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	ret_str = ft_substr(line, 0, i);
	if (!ret_str)
		return (NULL);
	tmp = line;
	line = ft_strldup(tmp + i, ft_strlen(tmp + i));
	free(tmp);
	if (!line)
		return (NULL);
	return (ret_str);
}
