/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:44:41 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 18:45:40 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	index_first;
	size_t	index_second;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (len - ft_strlen(s1) - ft_strlen(s2) != 0 || !(len + 1)
			|| (dest = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	index_first = 0;
	while (*(s1 + index_first) != '\0')
	{
		*(dest + index_first) = *(s1 + index_first);
		index_first++;
	}
	index_second = 0;
	while (*(s2 + index_second) != '\0')
	{
		*(dest + index_first + index_second) = *(s2 + index_second);
		index_second++;
	}
	*(dest + index_first + index_second) = '\0';
	return (dest);
}
