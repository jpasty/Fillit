/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_or_not.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:14:30 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/22 18:34:14 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_block(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == BLOCK)
		{
			if (str[i + 1] == BLOCK)
				n++;
			if (str[i - 1] == BLOCK)
				n++;
			if (str[i + 5] == BLOCK)
				n++;
			if (str[i - 5] == BLOCK)
				n++;
		}
		i++;
	}
	return (n == 6 || n == 8);
}

int			check_input(char *str, int ret)
{
	int		i;
	int		block;

	i = 0;
	block = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == BLOCK || str[i] == DOT))
				return (1);
			if (str[i] == BLOCK && ++block > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (ret == 21 && str[20] != '\n')
		return (1);
	if (!(check_block(str)))
		return (1);
	return (0);
}

t_etris		*valid_or_not(int fd, t_etris *head)
{
	int		ret;
	int		retprev;
	char	buf[22];
	t_etris	*curr;
	int		count;

	if (fd == -1)
		delete_and_exit(head, fd);
	count = 1;
	curr = head;
	retprev = 0;
	ft_bzero(buf, 22);
	while ((ret = read(fd, buf, BYTEREAD)) >= 20)
	{
		if (check_input(buf, ret) != 0 || count++ > 26)
			delete_and_exit(head, fd);
		if (!make_tetrimino_list(&curr, buf))
			delete_and_exit(head, fd);
		if (!head)
			head = curr;
		retprev = ret;
	}
	if (retprev != 20)
		delete_and_exit(head, fd);
	return (head);
}
