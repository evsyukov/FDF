/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:36:54 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 17:12:02 by smanta           ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		pow_10;
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n = -n;
	}
	len = ft_getlen(n);
	while (len--)
	{
		pow_10 = ft_pow10(len);
		c = 48 + n / pow_10;
		write(fd, &c, 1);
		n = n % pow_10;
	}
}
