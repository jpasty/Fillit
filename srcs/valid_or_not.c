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

t_map       *initialize()
{
    t_map   *new;

    if (!(new = (t_map *)malloc(sizeof(t_map))))
        return (NULL);
    if (!(new->line = (char *)malloc(sizeof(char) * BYTEREAD)))
    {
        free(new);
        return (NULL);
    }
    new->nbr_of_block = 1;
    return (new);
}

char    **make_map(char *str)
{
    char **map;

    if (!(map = (char **)malloc(sizeof(char *) * 4)))
        return (NULL);

}

int         check_block(char *str)
{
    int i;

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
    int ret;
    int retprev;

    if (fd == -1)
        ft_putstr("Can't open file\n");
    t_map *buf;
    buf = initialize();
    retprev = 0;
    while ((ret = read(fd, buf->line, BYTEREAD)) >= 20)  //
    {
        if (check_input(buf->line, ret) != 0)
            return (0);
        printf("%s", buf->line);
        buf->nbr_of_block++;
        retprev = ret;
    }
   if (retprev != 20)
   {
       return (0);
   }
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