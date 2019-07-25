/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:12:04 by jpasty            #+#    #+#             */
/*   Updated: 2019/06/21 13:25:34 by jpasty           ###   ########.fr       */
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
# define SPACE '.'

typedef struct	    s_map
{
	char		    *line;
	int             nbr_of_block;

}				    t_map;

typedef struct      s_pos
{
    int             x;
    int             y;
}                   t_pos;

typedef struct		s_etris
{
    t_pos	 		point[4];
	struct s_etris	*next;
}					t_etris;

void				fillopen(int , char **);
int     			valid_or_not(int);
t_etris				*initialize(void);
void				make_termino_list(t_etris **, char *);

#endif
