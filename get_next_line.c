/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:14:32 by hrolle            #+#    #+#             */
/*   Updated: 2022/01/03 23:01:24 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strljoin(const char *s1, const char *s2, int len)
{
	char	*str;
	char	*ret;

	if (!(s1 && s2))
		return (0);
	str = malloc((ft_strlen(s1) + len + 1) * sizeof(char));
	ret = str;
	if (!str)
		return (0);
	while (*s1)
		*(str++) = *(s1++);
	while (len > 0)
	{
		*(str++) = *(s2++);
		len--;
	}
	*str = 0;
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	unsigned int	f_len;

	if (!s)
		return (0);
	f_len = ft_strlen(s);
	if (start >= f_len)
		return (ft_strdup(""));
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

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;
	char		*ret_str;
	char		buf[BUFFER_SIZE + 1];
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	   return (NULL);	
	if (!line || !ft_strchr(line, '\n'))
	{
		while (i > 0)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (!line)
				line = ft_strdup(buf);
				if (!line)
					return (NULL);
			else
			{
				tmp = line;
				line = ft_strljoin(tmp, buf, i);
				free(tmp);
				if (!line)
					return (NULL);
			}
			if (ft_strchr(buf, '\n'))
				break;
		}
	}
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	ret_str = ft_substr(line, 0, i);
	if (!ret_str)
		return (NULL);
	tmp = line;
	line = ft_strdup(tmp + i + 1);
	free(tmp);
	if (!line)
		return (NULL);
	return (ret_str);
}
