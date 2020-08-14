/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:31:02 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 19:09:53 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*str;

	if ((ptr = (void *)malloc(size)) == NULL)
		return (NULL);
	str = (char *)ptr;
	while (size--)
		*(str++) = '\0';
	return (ptr);
}
