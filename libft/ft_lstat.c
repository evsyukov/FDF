/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:36:29 by smanta            #+#    #+#             */
/*   Updated: 2019/09/20 22:08:27 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, size_t n)
{
	size_t	index;

	if (lst == NULL)
		return (NULL);
	index = 0;
	while (lst != NULL && index < n)
	{
		lst = lst->next;
		index++;
	}
	return (lst);
}
