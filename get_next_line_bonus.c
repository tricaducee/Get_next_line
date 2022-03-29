/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:24:36 by hrolle            #+#    #+#             */
/*   Updated: 2022/03/29 14:25:36 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(char **line, int fd)
{
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	i = 1;
	while (!ft_strchr(line[fd], '\n') && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i && !line[fd])
			line[fd] = ft_strldup(buf, i);
		else if (i)
		{
			tmp = line[fd];
			line[fd] = ft_strljoin(tmp, buf, i);
			free(tmp);
		}
		if (!line[fd] || (!line[fd][0] && !i))
		{
			free(line[fd]);
			line[fd] = NULL;
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*lines[1024];
	char		*tmp;
	char		*ret_str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!read_file(lines, fd))
		return (NULL);
	i = 0;
	while (lines[fd][i] && lines[fd][i] != '\n')
		i++;
	if (lines[fd][i])
		i++;
	ret_str = ft_strldup(lines[fd], i);
	if (!ret_str)
		return (NULL);
	tmp = lines[fd];
	lines[fd] = ft_strldup(tmp + i, ft_strlen(tmp + i));
	free(tmp);
	if (!lines[fd])
		return (NULL);
	return (ret_str);
}
