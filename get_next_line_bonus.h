/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:22:03 by hrolle            #+#    #+#             */
/*   Updated: 2022/03/29 14:22:23 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1000
# endif

size_t	ft_strlen(const char *s);
char	*ft_strljoin(const char *s1, const char *s2, int len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strldup(const char *s1, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		read_file(char **line, int fd);
char	*get_next_line(int fd);

#endif
