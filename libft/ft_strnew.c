/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:47:39 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 17:52:13 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	if (!(size + 1)
			|| (str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	index = 0;
	while (index <= size)
		*(str + index++) = '\0';
	return (str);
}
