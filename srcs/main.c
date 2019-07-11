/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:43:07 by jpasty            #+#    #+#             */
/*   Updated: 2019/06/22 14:41:54 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

int         valid_or_not(int fd);

int			main(int ac, char **av)
{
	int		fd;
//	char	line[200];
//	int		i;
//	char	res[30];

	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(EXIT_FAILURE);
	}
//	if((fd = open("/Users/jpasty/42_course/fillit/not_valid_sample.fillit", O_RDONLY)) == -1)
//	{
//		printf("Can't open file\n");
//		exit(EXIT_FAILURE);
//	}
	if (valid_or_not(fd = open(av[1], O_RDONLY)) != 1)
	{
        ft_putstr("Error!\n");
    }
	else
	    ft_putstr("All right\n");

	//printf("%s", line);
//	while (line[i])
//    {
//		res[i] = line[i];
//		if (line[i] == '\n' && (line[i + 1] == '\n'))
//		{
//			res[i] = '\0';
//			ft_putstr(res);
//			break;
//		}
//		i++;
//	}
//ft_putnbr(fd);
	return (0);
}

