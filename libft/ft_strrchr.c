/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:33:02 by jpasty            #+#    #+#             */
/*   Updated: 2019/04/23 21:46:10 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!ft_strchr(s, c))
		return (NULL);
	while (*str)
		str++;
	while (*str != (char)c)
		str--;
	return (str);
}
