/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_or_not.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:37:30 by jpasty            #+#    #+#             */
/*   Updated: 2019/06/19 18:20:22 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/* Проверка тетремино по количеству связей между элемнтами */

int         check_block(char *str)
{
    int     i;

    i = 0;
    while (*str)
    {
        if (*str == BLOCK)
        {
            if (*(str + 1) == BLOCK)
                i++;
            if (*(str - 1) == BLOCK)
                i++;
            if (*(str + 5) == BLOCK)
                i++;
            if (*(str - 5) == BLOCK)
                i++;
        }
        str++;
    }
    ft_putnbr(i);
    ft_putchar('\n');
    return (i == 6 || i == 8);
}

/* Проверка на валидность блока (корректность символов, кол-во '#', размер блока,
 * кол-во переносов, расположение переносов)  */

int         check_input(char *str, int ret)
{
    int     i;
    int     block;
    i = 0;
    block = 0;

    while (i < 20)
    {
        if (i % 5 < 4)
        {
            if (!(str[i] == BLOCK || str[i] == SPACE))
                return (1);
            if (str[i] == BLOCK && ++block > 4)
                return (2);
        }
        else if (str[i] != '\n')
            return (3);
        i++;
    }
    if (ret == 21 && str[20] != '\n')
        return (4);
    if(!(check_block(str)))
        return (5);
    return (0);
}

/* Функция считывает по 21 байт, отправляет на валидацию и затем создает связанный список
 * из отдельных блоков. Возвращает указатель на первый элемент списка.*/

t_etris			*valid_or_not(int fd)
{
    int		ret;
    int		retprev;
	char	buf[21];
    t_etris	*head;
    t_etris	*curr;
	int i = 0;

	head = NULL;
    curr = head;
    if (fd == -1)
        ft_putstr("Can't open file\n");
    retprev = 0;
    while ((ret = read(fd, buf, BYTEREAD)) >= 20)
    {
    	buf[ret] = '\0';
        if (check_input(buf, ret) != 0)
        	return (0);
        make_termino_list(&curr, buf);
        if (!head)
        	head = curr;
        printf("%s", buf);
        retprev = ret;
    }
	while (head)
	{
		i = 0;
		while (i != 4)
		{
			printf("x = %d, y = %d;\n", head->point[i].x, head->point[i].y);
			i++;
		}
		printf("-------------\n");
		head = head->next;
	}
    if (retprev != 20)
    	return (0);
    return (head);
}