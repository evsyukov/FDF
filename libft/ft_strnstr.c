/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:43:50 by smanta            #+#    #+#             */
/*   Updated: 2019/09/17 15:54:02 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	index_s1;
	size_t	index_s2;
	size_t	len_s2;

	if (*s2 == '\0')
		return ((char *)s1);
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	index_s1 = 0;
	while (s1[index_s1] != '\0' && index_s1 < len)
	{
		if (len - index_s1 < len_s2)
			return (NULL);
		index_s2 = 0;
		while (s1[index_s1 + index_s2] == s2[index_s2]
				&& s2[index_s2] != '\0')
			index_s2++;
		if (s2[index_s2] == '\0')
			return ((char *)s1 + index_s1);
		index_s1++;
	}
	return (NULL);
}
