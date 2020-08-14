/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:24:46 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 17:09:05 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow10(int p)
{
	int	res;

	res = 1;
	while (p--)
		res *= 10;
	return (res);
}

static int	ft_getlen(int n)
{
	int	len;

	len = 1;
	while ((n / 10) != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void		ft_putnbr(int n)
{
	int		len;
	int		pow_10;
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		n = -n;
	}
	len = ft_getlen(n);
	while (len--)
	{
		pow_10 = ft_pow10(len);
		c = 48 + n / pow_10;
		write(1, &c, 1);
		n = n % pow_10;
	}
}
