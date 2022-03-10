/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:36:02 by hrolle            #+#    #+#             */
/*   Updated: 2022/01/04 19:25:54 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	(void)argc;
	int	i = atoi(argv[2]);
	int	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		printf("Le fichier n'as pas pu être ouvert\n");
		return 0;
	}
	while (i > 0)
	{
		printf("%s\n", get_next_line(fd));
		i--;
	}
	close(fd);
	return 0;
}
		
