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

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct s_etris
{
	t_point				point[4];
	struct s_etris		*next;
}						t_etris;

t_etris		*list_last(t_etris *current)
{
	t_etris *new_list;

	new_list = (t_etris *)malloc(sizeof(t_etris));
	new_list->next = NULL;
	current = new_list;

}
char		*start_position(char *str)
{
    int		i;
    int		x;
	int		x_min;
	int		y_min;

    i = 0;
    x_min = 0;
    y_min  = 0;
    while (str[i])
    {
		while (str[i] != '\n')
		{
			if (str[i] == '#' && y_min == 0 && x_min == 0)
			{
				y_min = i / 5;
				x_min = i % 5;
				x = x_min;
			}
			if (str[i] == '#')
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

t_etris			make_termino_list(t_etris *curr, char *str)
{
	int 		i;
	int 		n;
	char 		*ptr;

	i = 0;
	n = 0;
	ptr = start_position(str);
	while (ptr[i])
	{
		if (ptr[i] == '#')
		{
			curr.point[n].x = i % 5;
			curr.point[n].y = i / 5;
			n++;
		}
		i++;
	}
	list_last(curr);

	return (0);
}