/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:34:16 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/25 18:21:10 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_puthexnum(long int num, char c);
int	ft_putnbr(int nbr);
int	ft_putptr(unsigned long num);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putunsigned(unsigned int nbr);

#endif