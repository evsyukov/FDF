/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:36:47 by smanta            #+#    #+#             */
/*   Updated: 2019/09/21 15:27:23 by smanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	size_t				index;
	int					sign;

	res = 0;
	sign = 1;
	index = 0;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == '\v'
			|| str[index] == '\f' || str[index] == '\r' || str[index] == ' ')
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] > 47 && str[index] < 58)
		res = res * 10 + (str[index++] - 48);
	if (sign == 1 && res > 9223372036854775807)
		return (-1);
	if (sign == -1 && res > 9223372036854775807)
		return (0);
	return ((int)(res * sign));
}
