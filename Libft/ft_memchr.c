/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:46:25 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/10 15:29:03 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	g;
	size_t	i;

	str = (char *)s;
	g = (char) c;
	i = 0;
	if (c == 0 && n == 0)
		return (NULL);
	while (i < n)
	{
		if (str[i] == g)
			return ((char *)s + i);
		i++;
	}
	if (g == '\0')
		return (NULL);
	return (NULL);
}
