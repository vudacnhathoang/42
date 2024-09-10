/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:27:30 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/25 18:29:55 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointerlen(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*itoa_pointer(unsigned long num)
{
	char	*res;
	int		len;
	char	*digits;

	digits = "0123456789abcdef";
	len = pointerlen(num);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > 0)
	{
		res[len - 1] = digits[num % 16];
		num /= 16;
		len--;
	}
	return (res);
}

int	ft_putptr(unsigned long num)
{
	int		i;
	char	*s;

	i = 0;
	if (!num)
		i = write(1, "(nil)", 5);
	else
	{
		i += write(1, "0x", 2);
		s = itoa_pointer(num);
		if (s)
		{
			i += ft_putstr(s);
			free(s);
		}
	}
	return (i);
}
