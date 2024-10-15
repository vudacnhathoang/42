/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:03:56 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 17:12:27 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_input(char **nums, int x)
{
	while (nums[x] != NULL)
	{
		if(!ft_isnumber(nums[x]))
			return (0);
		x++;
	}
	return (1);
}

int ft_isnumber(char *s)
{
	int	i;
	int pre;

	i = 0;
	pre = 0;
	while(s[i]!= '\0')
	{
		if((s[i] == '-'|| s[i] == '+') && pre == 0)
		{
			i++;
			pre = 1;
		}
		else if (ft_isdigit(s[i]))
			i++;
		else
		{	
			ft_printf("Invalid input\n");
			return (0);
		}
	}
	return (1);
}