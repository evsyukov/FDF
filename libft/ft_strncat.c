/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:49:37 by smanta            #+#    #+#             */
/*   Updated: 2019/09/16 12:50:44 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	index;
	size_t	index_src;

	index = 0;
	while (dst[index] != '\0')
		index++;
	index_src = 0;
	while (src[index_src] != '\0' && index_src < n)
	{
		dst[index + index_src] = src[index_src];
		index_src++;
	}
	dst[index + index_src] = '\0';
	return (dst);
}
