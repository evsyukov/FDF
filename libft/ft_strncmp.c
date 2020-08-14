/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:40:35 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 18:31:44 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*str_s1;
	unsigned char	*str_s2;

	if (n == 0)
		return (0);
	str_s1 = (unsigned char *)s1;
	str_s2 = (unsigned char *)s2;
	index = 0;
	while (str_s1[index] == str_s2[index]
			&& str_s2[index] != '\0'
			&& index < n - 1)
		index++;
	return (str_s1[index] - str_s2[index]);
}
