/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:57 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/25 17:19:51 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_num(long n)
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

static char	*ft_itoa(int n)
{
	long	nb;
	char	*res;
	int		len;

	nb = n;
	len = len_num(nb);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb != 0)
	{
		res[len - 1] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (res);
}

int	ft_putnbr(int nbr)
{
	char	*s;
	int		i;

	s = ft_itoa(nbr);
	i = ft_putstr(s);
	free(s);
	return (i);
}
