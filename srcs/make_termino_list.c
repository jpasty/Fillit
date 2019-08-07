/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_termino_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:05:13 by jpasty            #+#    #+#             */
/*   Updated: 2019/07/24 16:27:02 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"


/* Создает и помещает ноду в конец связанного списка. */
void		create_last(t_etris **current)
{
	t_etris *new_elem;

	if (*current)
	{
		new_elem = (t_etris *)ft_memalloc(sizeof(t_etris));
		(*current)->next = new_elem;
		*current = new_elem;
		return;
	}
	*current = (t_etris *)ft_memalloc(sizeof(t_etris));
	(*current)->next = NULL;
}

/* Поиск точки начала координат. Возвращает указатель на точку отсчета. */

char		*start_position(char *str)
{
    int		i;
    int		x;
    int		y;
	int		x_min;
	int		y_min;

    i = 0;
    y = 0;
    while (str[i])
    {
		while (str[i] != '\n' && (str[i] == BLOCK || str[i] == DOT))
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
			i++;
		}
		i++;
    }
	return (&str[y_min*5 + x_min]);
}

/* Функция добавляет новый элемент списка, сохраняет координаты блока. */

void			make_termino_list(t_etris **curr, char *str)
{
	int 		i;
	int 		n;
	char 		*ptr;

	i = 0;
	n = 0;
	ptr = start_position(str);
	create_last(curr);
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
}