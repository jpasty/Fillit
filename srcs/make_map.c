/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:06:20 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/05 20:51:03 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/* Печать карты. */
void        print_map(char **map)
{
	int     i;
	int     j;

	j = 0;
	while (map[j])
		ft_putstr(map[j++]);
}

int 		min_board_side(t_etris *figure)
{
	int 	cnt;
	int 	min_side;
	t_etris	*tmp;

	cnt  = 1;
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

/* Инициализация и заполнение карты. */

char		**gen_map(int side)
{
	char	**map;
	int		i;
	int 	j;

	if(!(map = (char **)ft_memalloc(sizeof(char*) * (side + 1))))
		return (NULL);
	j = 0;
	while (j < side)
	{
		i = 0;
		if(!(map[j] = (char*)ft_memalloc(sizeof(char) * (side + 1))))
			return (NULL);
		while (i < side)
			map[j][i++] = DOT;
		j++;
	}
	return (map);
}