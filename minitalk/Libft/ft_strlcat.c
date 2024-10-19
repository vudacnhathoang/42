/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:10:09 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/08 12:36:18 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (size <= dlen)
		return (size + slen);
	i = 0;
	while (src[i] && (i + dlen) < (size - 1))
	{
		dest[i + dlen] = src[i];
		i++;
	}
	if ((i + dlen) < size)
		dest[i + dlen] = '\0';
	return (dlen + slen);
}
