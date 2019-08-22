/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:05:19 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/22 18:44:04 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_etris	*figure;
	char	**map;
	char	letter;
	int		side;
	int		fd;

	figure = NULL;
	map = NULL;
	letter = 'A';
	if (ac != 2)
		delete_and_exit(figure, -21);
	fd = open(av[1], O_RDONLY);
	figure = valid_or_not(fd, figure);
	side = min_board_side(figure);
	map = gen_map(map, side);
	while (map && !just_do_it(map, figure, letter))
	{
		ft_free(map);
		map = gen_map(map, side++);
	}
	print_map(map, figure, fd);
	close(fd);
	return (0);
}
