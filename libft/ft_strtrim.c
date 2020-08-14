/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:19:05 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 16:42:24 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_make_empty_string(void)
{
	char	*dst;

	if ((dst = (char *)malloc(sizeof(char))) == NULL)
		return (NULL);
	dst[0] = '\0';
	return (dst);
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	size_t	l;
	size_t	m;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	l = 0;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && l < len)
		l++;
	if (len == 0 || l == len)
	{
		dst = ft_make_empty_string();
		return (dst);
	}
	m = len - 1;
	while (s[m] == ' ' || s[m] == '\n' || s[m] == '\t')
		if (m-- == 0)
			break ;
	dst = ft_strsub(s, l, m - l + 1);
	return (dst);
}
