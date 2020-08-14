/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:05:37 by smanta            #+#    #+#             */
/*   Updated: 2019/09/17 14:04:02 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	if ((dst == NULL && src == NULL) || len == 0)
		return (dst);
	str_dst = (unsigned char *)dst;
	str_src = (unsigned char *)src;
	index = 0;
	if (src >= dst)
		while (index < len)
		{
			str_dst[index] = str_src[index];
			index++;
		}
	else
		while (index < len)
		{
			str_dst[len - index - 1] = str_src[len - index - 1];
			index++;
		}
	return (dst);
}
