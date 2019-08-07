/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:43:07 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/05 20:51:23 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>


int			main(int ac, char **av)
{
	int 	fd;
	t_etris *figure;
	char 	**map;
	char	letter;
	int 	side;

	letter = 'A';
	figure = NULL;
//	if (ac != 2)
//		put_some_error
	figure = valid_or_not(fd = open(av[1], O_RDONLY), figure);
	side = min_board_side(figure);
	map = gen_map(side);
	while (!just_do_it(map, figure, letter))
	{
		free(map);
		gen_map(side++);
	}
	print_map(map);
	return (0);
}

