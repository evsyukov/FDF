/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:45:27 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 14:41:52 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			index;

	if ((dst == NULL && src == NULL) || n == 0)
		return (dst);
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		*(s1 + index) = *(s2 + index);
		index++;
	}
	return (dst);
}
