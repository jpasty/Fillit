/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetrimino_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:24:02 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/14 13:24:41 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	create_last(t_etris **current)
{
	t_etris	*new_elem;

	if (*current)
	{
		if (!(new_elem = (t_etris *)ft_memalloc(sizeof(t_etris))))
			return (0);
		(*current)->next = new_elem;
		*current = new_elem;
		return (1);
	}
	if (!(*current = (t_etris *)ft_memalloc(sizeof(t_etris))))
		return (0);
	(*current)->next = NULL;
	return (1);
}

static char	*start_position(char *str, int x_min, int y_min)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] != '\n' && (str[i] == BLOCK || str[i] == DOT))
		{
			if (str[i] == BLOCK && y-- == 0)
			{
				y_min = i / 5;
				x_min = i % 5;
			}
			if (str[i] == BLOCK)
				x = i % 5;
			if (x < x_min)
				x_min = x;
		}
		i++;
	}
	return (&str[y_min * 5 + x_min]);
}

int			make_tetrimino_list(t_etris **curr, char *str)
{
	int		i;
	int		n;
	char	*ptr;

	i = 0;
	n = 0;
	ptr = start_position(str, 0, 0);
	if (!create_last(curr))
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == BLOCK)
		{
			(*curr)->pos[n].x = i % 5;
			(*curr)->pos[n].y = i / 5;
			n++;
		}
		i++;
	}
	return (1);
}
