/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:08:45 by smanta            #+#    #+#             */
/*   Updated: 2019/09/20 19:14:47 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c_char;
	size_t			index;

	str = (unsigned char *)s;
	c_char = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (str[index] == c_char)
			return ((void *)(str + index));
		index++;
	}
	return (NULL);
}
