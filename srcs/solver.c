/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 14:37:34 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/14 14:42:34 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	razpihni(char **map, t_etris *figure, int *x_y)
{
	int		n;

	n = 0;
	while (n <= 3)
	{
		map[x_y[1] + figure->pos[n].y][x_y[0] + figure->pos[n].x] = DOT;
		n++;
	}
}

static void	vzapihni(char **map, t_etris *figure, int *x_y, int c)
{
	int		n;

	n = 0;
	while (n < 4)
	{
		map[x_y[1] + figure->pos[n].y][x_y[0] + figure->pos[n].x] = c;
		n++;
	}
}

static int	in_area(char **m, t_etris *f, int *x_y, int n)
{
	int		size;

	size = ft_strlen(*m) - 1;
	if ((x_y[1] + f->pos[n].y) > size || (x_y[0] + f->pos[n].x) > size)
		return (0);
	return (1);
}

int			check_paste(char **m, t_etris *f, int *x_y, char c)
{
	int		n;

	while (m[x_y[1]])
	{
		while (m[x_y[1]][x_y[0]])
		{
			n = 0;
			while (n < 4)
			{
				if (!in_area(m, f, x_y, n) ||
					m[x_y[1] + f->pos[n].y][x_y[0] + f->pos[n].x] != DOT)
					break ;
				n++;
			}
			if (n == 4)
			{
				vzapihni(m, f, x_y, c);
				return (1);
			}
			(x_y[0])++;
		}
		(x_y[1])++;
		x_y[0] = 0;
	}
	return (0);
}

int			just_do_it(char **map, t_etris *figure, char c)
{
	int		x_y[2];

	x_y[1] = 0;
	if (!figure)
		return (1);
	while (map[x_y[1]])
	{
		x_y[0] = 0;
		while (map[x_y[1]][x_y[0]])
		{
			if (check_paste(map, figure, x_y, c))
			{
				if (just_do_it(map, figure->next, c + 1))
					return (1);
			}
			else
				return (0);
			razpihni(map, figure, x_y);
			(x_y[0])++;
		}
		(x_y[1])++;
	}
	return (0);
}
