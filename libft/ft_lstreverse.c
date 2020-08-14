/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:09:11 by smanta            #+#    #+#             */
/*   Updated: 2019/09/18 18:36:24 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **alst)
{
	t_list	*new_rev;
	t_list	*begin_current;
	t_list	*next_current;

	if (alst == NULL || *alst == NULL)
		return ;
	new_rev = NULL;
	begin_current = *alst;
	while (begin_current != NULL)
	{
		next_current = begin_current->next;
		begin_current->next = new_rev;
		new_rev = begin_current;
		begin_current = next_current;
	}
	*alst = new_rev;
}
