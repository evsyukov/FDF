/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:15:54 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 17:53:21 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	index;
	char	*dest;

	if (s == NULL || f == NULL)
		return (NULL);
	len = 0;
	while (*(s + len) != '\0')
		len++;
	if (!(len + 1)
			|| (dest = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		*(dest + index) = f(*(s + index));
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
