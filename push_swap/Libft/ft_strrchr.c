/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:40:03 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/05 15:00:06 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		g;
	const char	*fin;

	fin = NULL;
	g = (char) c;
	while (*s)
	{
		if (*s == g)
			fin = s;
		s++;
	}
	if (g == '\0')
		return ((char *)s);
	return ((char *)fin);
}
