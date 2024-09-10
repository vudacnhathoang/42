/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:13:14 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/25 18:21:25 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_argument(va_list args, const char *conversion, int *len)
{
	if (*conversion == 'd' || *conversion == 'i')
		*len += ft_putnbr(va_arg(args, int));
	else if (*conversion == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (*conversion == 's')
		*len += ft_putstr(va_arg(args, char *));
	else if (*conversion == 'p')
		*len += ft_putptr(va_arg(args, unsigned long));
	else if (*conversion == 'u')
		*len += ft_putunsigned(va_arg(args, unsigned int));
	else if (*conversion == 'x' || *conversion == 'X')
		*len += ft_puthexnum(va_arg(args, unsigned int), *conversion);
	else if (*conversion == '%')
		*len += ft_putchar('%');
	else
		*len = write(1, conversion, 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			print_argument(args, format, &count);
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
