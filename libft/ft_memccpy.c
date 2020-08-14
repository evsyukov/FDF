/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:33:39 by smanta            #+#    #+#             */
/*   Updated: 2019/09/20 19:11:17 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			index;
	unsigned char	c_char;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	index = 0;
	c_char = (unsigned char)c;
	while (index < n)
	{
		s1[index] = s2[index];
		if (s2[index] == c_char)
			return ((void *)(s1 + index + 1));
		index++;
	}
	return (NULL);
}
