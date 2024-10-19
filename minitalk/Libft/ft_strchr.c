/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:30:04 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/05 14:48:51 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	g;

	g = (char) c;
	while (*s)
	{
		if (*s == g)
			return ((char *)s);
		s++;
	}
	if (g == '\0')
		return ((char *)s);
	return (NULL);
}
