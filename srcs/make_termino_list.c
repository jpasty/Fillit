/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:05:13 by jpasty            #+#    #+#             */
/*   Updated: 2019/07/24 16:27:02 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

void		create_last(t_etris **current)
{
	t_etris *new_elem;
	int		n;

	n = -1;
	new_elem = (t_etris *)malloc(sizeof(t_etris));
	while (n++ < 3)
	{
		new_elem->point[n].x = 0;
		new_elem->point[n].y = 0;
	}
	new_elem->next = NULL;
	(*current)->next = new_elem;
	*current = new_elem;
}
char		*start_position(char *str)
{
    int		i;
    int		x;
    int		y;
	int		x_min;
	int		y_min;

    i = 0;
    y = 0;
    x_min = 0;
    while (str[i])
    {
		while (str[i] != '\n' && (str[i] == BLOCK || str[i] == SPACE))
		{
			if (str[i] == BLOCK && y == 0 && x_min == 0)
			{
				y_min = i / 5;
				x_min = i % 5;
				x = x_min;
				y = -1;
			}
			if (str[i] == BLOCK)
			{
				x = i % 5;
				if (x < x_min)
					x_min = x;
			}
			i++;
		}
		i++;
    }
	return (&str[y_min*5 + x_min]);
}

void			make_termino_list(t_etris **curr, char *str)
{
	int 		i;
	int 		n;
	char 		*ptr;

	i = 0;
	n = 0;
	ptr = start_position(str);
	while (ptr[i])
	{
		if (ptr[i] == BLOCK)
		{
			(*curr)->point[n].x = i % 5;
			(*curr)->point[n].y = i / 5;
			n++;

		}
		i++;
	}
	n  = 0;
//	while (n != 4)
//	{
//		printf("x = %d, y = %d;\n", (*curr)->point[n].x, (*curr)->point[n].y);
//		n++;
//	}
	create_last(curr);
}