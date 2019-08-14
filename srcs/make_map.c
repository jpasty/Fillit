/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:31:47 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/14 14:54:49 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(char **map)
{
	int		j;

	j = 0;
	while (map[j])
	{
		ft_putstr(map[j++]);
		ft_putchar('\n');
	}
	free(map);
	map = NULL;
}

int			min_board_side(t_etris *figure)
{
	int		cnt;
	int		min_side;
	t_etris	*tmp;

	cnt = 0;
	min_side = 2;
	tmp = figure;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	while (min_side * min_side < cnt * 4)
		min_side++;
	return (min_side);
}

char		**gen_map(char **map, int side)
{
	int		i;
	int		j;

	if (!(map = (char **)ft_memalloc(sizeof(char*) * (side + 1))))
		return (NULL);
	j = 0;
	while (j < side)
	{
		i = 0;
		if (!(map[j] = (char*)ft_memalloc(sizeof(char) * (side + 1))))
			return (NULL);
		while (i < side)
			map[j][i++] = DOT;
		j++;
	}
	map[j] = NULL;
	return (map);
}
