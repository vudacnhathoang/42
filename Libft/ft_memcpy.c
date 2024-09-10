/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:23:37 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/08 13:48:45 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		n--;
	}
	return (dest);
}
