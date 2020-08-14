/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:46:37 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 15:19:24 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c_char;
	unsigned char	*src;
	size_t			len;
	size_t			index;

	c_char = (unsigned char)c;
	src = (unsigned char *)s;
	len = 0;
	while (src[len] != '\0')
		len++;
	index = 0;
	while (index < len + 1)
	{
		if (src[len - index] == c_char)
			return ((char *)src + len - index);
		index++;
	}
	return (NULL);
}
