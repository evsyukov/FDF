/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:41:20 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 17:53:54 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	index;
	char			*dest;

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
		*(dest + index) = f(index, *(s + index));
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
