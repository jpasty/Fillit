/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:31:02 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/05 21:24:45 by jpasty           ###   ########.fr       */
/*                                                                            */
/* *********************************************************************/

#include "fillit.h"

static void	razpihni(char **map, t_etris *figure, int i, int j)
{
	int		n;

	n = 0;
	while (n++ < 4)
		map[i + figure->point[n].y][j + figure->point[n].x] = DOT;
}

static void	vzapihni(char **map, t_etris *figure, int i, int j, char c)

{
	int		n;

	n = 0;
	while ( n < 4)
	{
		map[i + figure->point[n].y][j + figure->point[n].x] = c;
		n++;
	}
}

int		check_paste(char **map, t_etris *figure, char c)
{
	int		i;
	int		j;
	int		n;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			n = 0;
			while (n < 4)
			{
				if (map[j + figure->point[n].y][i + figure->point[n].x] != DOT)
					break;
				n++;
			}
			if (n == 4)
			{
				vzapihni(map, figure, i, j, c);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	 		just_do_it(char **map, t_etris *figure, char c)
{
	int		x;
	int		y;

	if (!figure)
		return (1);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_paste(map, figure, c))
			{
				if (just_do_it(map, figure->next, c + 1))
					return (1);
			}
			else
				return (0);
			razpihni(map, figure, y, x);
			x++;
		}
		y++;
	}
	return (1);
}