/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:05:19 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/14 13:05:39 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free(char **map)
{
	int		i;
	int		j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			map[j][i++] = '\0';
		j++;
	}
	free(map);
	map = NULL;
}

int			main(int ac, char **av)
{
	t_etris	*figure;
	char	**map;
	char	letter;
	int		side;

	letter = 'A';
	figure = NULL;
	map = NULL;
	if (ac != 2)
		return (1);
	if (!(figure = valid_or_not(open(av[1], O_RDONLY), figure)))
	{
		ft_putstr("error");
		return (1);
	}
	side = min_board_side(figure);
	map = gen_map(map, side);
	while (!just_do_it(map, figure, letter))
	{
		ft_free(map);
		map = gen_map(map, side++);
	}
	print_map(map);
	return (0);
}
