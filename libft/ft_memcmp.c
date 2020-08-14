/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:16:25 by smanta            #+#    #+#             */
/*   Updated: 2019/09/20 12:47:41 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*str_s1;
	unsigned char	*str_s2;

	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	str_s1 = (unsigned char *)s1;
	str_s2 = (unsigned char *)s2;
	index = 0;
	while (str_s1[index] == str_s2[index] && index < n - 1)
		index++;
	return (str_s1[index] - str_s2[index]);
}
