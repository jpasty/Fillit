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

//int			valid_or_not(int fd) {
//    char buf[BYTEREAD + 1];
//    char *map;
//    int ret;
//    int i;
//    int p;
//    int string;
//
//    string = 0;
//    p = 0;
//    ret = read(fd, buf, BYTEREAD);
//    buf[ret] = '\0';
//    map = ft_strdup(buf);
//    while (*map != '\0')
//    {
//        i = 0;
//
//        string++;
//        while (map[i] != '\n')
//            i++;
//        if (string % 4 == 0 &&  (map[i + 1] != '\n' && map[i + 1] != '\0'))
//        {
//            printf("Not a valid figure\n");
//            exit(EXIT_FAILURE);
//        }
//        if (map[i] =='\n' && map[i + 1] == '\n')
//            map++;
//
//        if (i != 4 && map[0] == '\n'){
//            printf("Not a valid figure\n");
//            exit(EXIT_FAILURE);
//        }
//
//        map += 5;
//    }
//    printf("This is the valid map\n");
//        return(1);
//}

//int         validmap(int fd, char **map)
//{
//    char buf[BYTEREAD + 1];
//    int     ret;
//    int     i;
//    int     j;
//
//    ret = 0;
//    i = 0;
//    j = 0;
//    while ((ret = read(fd, buf, BYTEREAD)) != 0)
//    {
//        buf[ret] = '\0';
//        while (*buf != '\0')
//        {
//            while (*buf != '\n')
//            {
//              map[j][i] = *buf;
//              j++;
//            }
//            i++;
//        }
//
//    }
//
//}
//
//int         valid_or_not(int fd, char **map)
//{
//    char *buf[BYTEREAD + 1];
//    while (ret )
//    validmap(buf, map);
//
//    return (0);
//
//
//}

//int         valid_or_not(int fd, char   **map)
//{
//
//
//}

//t_etris		*making_position(char *str)
//{
//    int		i;
//    char *start;
//    t_pos	pos;
//
//
//    i = 0;
//    x_min = 0;
//    y_min  = 0;
//    while (str[i])
//    {
//		while (str[i++] != '\n')
//		{
//			if (str[i] == BLOCK && y_min == 0)
//				y_min = i / 5;
//		}
//		i++;
//		while (str[i++] != '\n')
//		{
//			if (str[i] == BLOCK && x_min == 0)
//				x_min = i % 5;
//		}
//		start = &str[y_min + x_min];
//	}
//
//
//}

t_etris       *initialize(void)
{
    t_etris   *head;

    if (!(head = (t_etris *)malloc(sizeof(t_etris))))
        return (NULL);
    head->next = NULL;
    return (head);
}

//char    **make_map(char *str)
//{
//    char **map;
//
//    if (!(map = (char **)malloc(sizeof(char *) * 4)))
//        return (NULL);
//
//}

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
int			valid_or_not(int fd)
{
    int		ret;
    int		retprev;
	char	buf[21];
    t_etris	*head;
    t_etris	*curr;
	int		i;

	i = 0;
//    if (!head)
//    	curr = head;

//    if (!( head = initialize() ))
//		return (0);
    curr = head;
    if (fd == -1)
        ft_putstr("Can't open file\n");
    retprev = 0;
    while ((ret = read(fd, buf, BYTEREAD)) >= 20)  //
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
    printf("success validation\n");
    return (1);
//    char buf[BYTEREAD + 1];
//    char *map;
//    int string;
//    int ret;
//    int i;
//
//
//    ret = read(fd, buf, BYTEREAD);
//    if (ret == 0)
//        return (0);
//    buf[ret] = '\0';
//    string = 4;
//    map = ft_strdup(buf);
//    while (string--) {
//        i = 0;
//        while ((map[i] == '.' || map[i] == '#') && i != 4)
//            i++;
//        if (i == 4 && map[i] != '\n')
//            return (0);
//        if (i != 4)
//            return (0);
//        map += 5;
//    }
//    if (buf[20] == '\0' || buf[20] == '\n')
//        return(1);
//    return (0);
}