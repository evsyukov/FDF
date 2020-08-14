/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:09:29 by smanta            #+#    #+#             */
/*   Updated: 2019/09/19 14:33:43 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	index = 0;
	while (*(s1 + index) == *(s2 + index)
			&& *(s1 + index) != '\0'
			&& *(s2 + index) != '\0'
			&& index < n - 1)
		index++;
	return (*(s1 + index) - *(s2 + index) == 0 ? 1 : 0);
}
