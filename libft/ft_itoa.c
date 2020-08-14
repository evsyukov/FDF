/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:37:30 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 18:02:22 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(int n)
{
	size_t	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		*ft_itoa_min_int(void)
{
	char	*arr;
	char	*str;
	size_t	index;

	arr = "-2147483648";
	if ((str = (char *)malloc(sizeof(char) * (12))) == NULL)
		return (NULL);
	index = 0;
	while (index < 12)
	{
		str[index] = arr[index];
		index++;
	}
	return (str);
}

static char		*ft_itoa_neg(int n)
{
	char	*str;
	size_t	len;
	size_t	index;

	if (n == -2147483648)
	{
		str = ft_itoa_min_int();
		return (str);
	}
	n = -n;
	len = ft_getlen(n);
	if (!(len + 2)
			|| (str = (char *)malloc(sizeof(char) * (len + 2))) == NULL)
		return (NULL);
	str[0] = '-';
	str[len + 1] = '\0';
	index = 0;
	while (index < len)
	{
		str[len - index - 1 + 1] = 48 + n % 10;
		n = n / 10;
		index++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	index;

	if (n < 0)
		return (ft_itoa_neg(n));
	len = ft_getlen(n);
	if (!(len + 1)
			|| (str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	index = 0;
	while (index < len)
	{
		str[len - index - 1] = 48 + n % 10;
		n = n / 10;
		index++;
	}
	return (str);
}
