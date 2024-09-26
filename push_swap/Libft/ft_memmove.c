/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:39:00 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/08 14:01:02 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char		*d;
	const unsigned char	*c;

	c = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d <= c)
	{
		while (n--)
		{
			*d++ = *c++;
		}
	}
	else
	{
		d = d + n - 1;
		c = c + n - 1;
		while (n --)
		{
			*d-- = *c--;
		}
	}
	return (dest);
}
