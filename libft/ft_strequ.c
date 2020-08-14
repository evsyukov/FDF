/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:50:13 by smanta            #+#    #+#             */
/*   Updated: 2019/09/17 20:35:28 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	while (*(s1 + index) == *(s2 + index)
			&& *(s1 + index) != '\0'
			&& *(s2 + index) != '\0')
		index++;
	return (*(s1 + index) - *(s2 + index) == 0 ? 1 : 0);
}
