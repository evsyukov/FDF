/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:16:16 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 17:54:36 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	index;

	if (s == NULL)
		return (NULL);
	if (!(len + 1)
			|| (dest = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		*(dest + index) = *(s + start + index);
		index++;
	}
	*(dest + index) = '\0';
	return (dest);
}
