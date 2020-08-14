/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:48:27 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 14:56:24 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	index;
	size_t	index_src;

	index = 0;
	while (dst[index] != '\0')
		index++;
	index_src = 0;
	while (src[index_src] != '\0')
	{
		dst[index + index_src] = src[index_src];
		index_src++;
	}
	dst[index + index_src] = '\0';
	return (dst);
}
