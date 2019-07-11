/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:10:30 by jpasty            #+#    #+#             */
/*   Updated: 2019/04/11 15:24:28 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*res;
	const unsigned char	*str;

	res = (unsigned char *)dst;
	str = (const unsigned char *)src;
	while (n--)
	{
		if ((*res++ = *str++) == (unsigned char)c)
			return (res);
	}
	return (NULL);
}
