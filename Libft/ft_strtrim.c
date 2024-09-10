/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:17:54 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/10 11:45:11 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int	bg;
	int	end;

	bg = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[bg]) && bg <= end)
		bg++;
	while (ft_strchr(set, s1[end]) && bg <= end)
		end--;
	return (ft_substr(s1, bg, end - bg + 1));
}
