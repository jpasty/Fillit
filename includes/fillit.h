/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:12:04 by jpasty            #+#    #+#             */
/*   Updated: 2019/08/22 18:41:22 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BYTEREAD 21
# define BLOCK '#'
# define DOT '.'

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_etris
{
	t_pos			pos[4];
	struct s_etris	*next;
}					t_etris;

t_etris				*valid_or_not(int fd, t_etris *head);
int					make_tetrimino_list(t_etris **figure, char *str);
int					min_board_side(t_etris *figure);
char				**gen_map(char **map, int side);
int					just_do_it(char **map, t_etris *figure, char c);
void				print_map(char **map, t_etris *figure, int fd);
void				delete_and_exit(t_etris *head, int fd);
void				ft_free(char **map);
void				delete_list(t_etris *head);

#endif
