/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:57:19 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 16:47:08 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_getword(char const *s, size_t *index, char c)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (s == NULL)
		return (NULL);
	start = *index;
	while (s[start] == c)
		start++;
	if (s[start] == '\0')
		return (NULL);
	end = start;
	while (s[end] != c && s[end] != '\0')
		end++;
	if ((str = ft_strsub(s, start, end - start)) == NULL)
		return (NULL);
	*index = end;
	return (str);
}

static size_t	ft_getcountwords(char const *s, char c)
{
	size_t	words;
	size_t	index;

	words = 0;
	index = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] == '\0')
			return (words);
		while (s[index] != c && s[index] != '\0')
			index++;
		words++;
	}
	return (words);
}

static void		ft_free_arr_str(char **arrstr, size_t index_word)
{
	size_t	index;

	index = 0;
	while (index < index_word)
	{
		free(arrstr[index]);
		index++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**arrstr;
	size_t	index_word;
	size_t	index;

	if (s == NULL)
		return (NULL);
	words = ft_getcountwords(s, c);
	if (!(words + 1)
			|| (arrstr = (char **)malloc(sizeof(char *) * (words + 1))) == NULL)
		return (NULL);
	index_word = 0;
	index = 0;
	while (index_word < words)
	{
		arrstr[index_word] = ft_getword(s, &index, c);
		if (arrstr[index_word++] == NULL)
		{
			ft_free_arr_str(arrstr, index_word);
			free(arrstr);
			return (NULL);
		}
	}
	arrstr[words] = NULL;
	return (arrstr);
}
