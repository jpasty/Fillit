/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 12:24:11 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/22 18:30:51 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(char **map)
{
	int	i;
	int j;

	j = 0;
	if (map)
	{
		while (map[j])
		{
			i = 0;
			while (map[j][i])
				map[j][i++] = '\0';
			free(map[j]);
			j++;
		}
	}
	free(map);
}

void	delete_list(t_etris *head)
{
	int	n;

	n = 0;
	if (!head)
		return ;
	delete_list(head->next);
	while (n < 4)
	{
		head->pos[n].x = 0;
		head->pos[n].y = 0;
		n++;
	}
	free(head);
}

void	delete_and_exit(t_etris *head, int fd)
{
	if (head)
		delete_list(head);
	if (fd == -21)
		ft_putstr("usage: ./fillit source_file\n");
	else
	{
		ft_putstr("error\n");
		close(fd);
	}
	exit(EXIT_FAILURE);
}
