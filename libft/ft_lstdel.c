/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:40:03 by smanta            #+#    #+#             */
/*   Updated: 2019/09/20 21:33:50 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmpptr;

	if (alst == NULL || del == NULL)
		return ;
	if (*alst == NULL)
		return ;
	lst = *alst;
	while (lst != NULL)
	{
		del(lst->content, lst->content_size);
		tmpptr = lst;
		lst = lst->next;
		free(tmpptr);
	}
	*alst = NULL;
}
