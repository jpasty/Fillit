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

int     valid_or_not(int fd);

typedef struct	    s_map
{
	char		    *line;
	int             nbr_of_block;

}				    t_map;

typedef struct	s_mino
{
	char		let;
	int			*loc;
}				t_mino;

void			fillopen(int fd, char **mino);

#endif
