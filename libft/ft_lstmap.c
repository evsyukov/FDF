/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:43:32 by smanta            #+#    #+#             */
/*   Updated: 2019/09/20 21:53:59 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freelst(t_list **alst)
{
	t_list	*tmp;
	t_list	*lst;

	lst = *alst;
	while (lst != NULL)
	{
		tmp = lst;
		free(lst->content);
		lst = lst->next;
		free(tmp);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*begin;
	t_list	*prev;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((begin = f(lst)) == NULL)
		return (NULL);
	lst = lst->next;
	prev = begin;
	while (lst != NULL)
	{
		if ((new_lst = f(lst)) == NULL)
		{
			ft_freelst(&begin);
			return (NULL);
		}
		prev->next = new_lst;
		prev = new_lst;
		lst = lst->next;
	}
	return (begin);
}
