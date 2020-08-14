/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:45:28 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 15:09:39 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	size_t			index;
	unsigned char	c_char;
	unsigned char	*src;

	c_char = (unsigned char)c;
	src = (unsigned char *)s1;
	index = 0;
	while (src[index] != '\0')
	{
		if (src[index] == c_char)
			return ((char *)src + index);
		index++;
	}
	if (src[index] == c_char)
		return ((char *)src + index);
	return (NULL);
}
