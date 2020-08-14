/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:55:56 by smanta            #+#    #+#             */
/*   Updated: 2019/09/18 12:53:53 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	index_src;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	len_dst = 0;
	while (dst[len_dst] != '\0')
		len_dst++;
	index_src = 0;
	while (src[index_src] != 0 && len_dst + index_src + 1 < size)
	{
		dst[len_dst + index_src] = src[index_src];
		index_src++;
	}
	dst[len_dst + index_src] = '\0';
	if (size > len_dst)
		return (len_dst + len_src);
	return (size + len_src);
}
