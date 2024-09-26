/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:20:43 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/25 18:06:59 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_len(long long n)
{
	int	ct;

	ct = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		ct++;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		ct++;
	}
	return (ct);
}

static char	*itoa_unsigned(unsigned int nbr)
{
	long long	n;
	char		*res;
	int			len;

	n = nbr;
	len = unsigned_len(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (res);
}

int	ft_putunsigned(unsigned int nbr)
{
	char	*s;
	int		i;

	s = itoa_unsigned(nbr);
	i = ft_putstr(s);
	free(s);
	return (i);
}
