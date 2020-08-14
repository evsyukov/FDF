/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:42:46 by smanta            #+#    #+#             */
/*   Updated: 2019/09/20 19:37:59 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	index_s1;
	size_t	index_s2;

	if (*s2 == '\0')
		return ((char *)s1);
	index_s1 = 0;
	while (s1[index_s1] != '\0')
	{
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
