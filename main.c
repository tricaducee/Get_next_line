/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:36:02 by hrolle            #+#    #+#             */
/*   Updated: 2022/03/14 19:45:29 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
/*
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
*/
int main()
{
	int i = 0;
	int j = 1;
	int k = 0;
	int l = 1;
	int fd[101] = {0};
	char fichier[101] = {0};
	while (j == 1)
	{
		printf("Tapez 1 pour ouvrir un nouveau fichier ou 2 pour continuer: ");
		scanf("%d", &j);
		if (j == 1)
		{
			while (l == 1)
			{
				printf("Tapez le nom de votre fichier: "); 
				scanf("%s", fichier);
				fd[i] = open(fichier, O_RDONLY);
				if (fd[i] < 1)
				{
					printf("\nLe fichier n'as pas pu être ouvert.\n");
					l = 1;
				}
				else
					l = 0;
			}
			while (fichier[k])
			{
				fichier[k] = 0;
				k++;
			}
			k = 0;
		}
	}
	i = 0;
	j = 1;
	while (j)
	{
		printf("\nTapez\n0. Pour quitter");
		while (fd[i])
		{
			printf("\n%d. Pour le fichier %d", i + 1, i + 1);
			i++;
		}
		i = 0;
		printf("\nVotre choix: ");
		scanf("%d", &j);
		if (j)
		{
			printf("\nCombiens voulez-vous de lignes: "); 
			scanf("%d", &k);
			while (k)
			{
				printf("%s\n", get_next_line(fd[j - 1]));
				k--;
			}
		}
	}
	i = 0;
	while (fd[i])
	{
		close(fd[i]);
		i++;
	}
	return (0);
}
