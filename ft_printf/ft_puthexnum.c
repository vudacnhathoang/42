/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:23:45 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/25 18:20:57 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexlen(long int n)
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
		n = n / 16;
		ct++;
	}
	return (ct);
}

static char	*itoa_hex(long int n, const char cases)
{
	char	*res;
	int		len;
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	len = hexlen(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (n != 0)
	{
		if (cases == 'x')
			res[len - 1] = lower[n % 16];
		else
			res[len - 1] = upper[n % 16];
		n = n / 16;
		len --;
	}
	return (res);
}

int	ft_puthexnum(long int num, char c)
{
	char	*s;
	int		i;

	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	s = itoa_hex(num, c);
	i = ft_putstr(s);
	free(s);
	return (i);
}
