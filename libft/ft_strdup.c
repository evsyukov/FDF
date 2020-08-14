/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:55:21 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 18:20:40 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	index;
	char	*dst;
	char	*src;

	src = (char *)s1;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (!(len + 1) || (dst = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}
