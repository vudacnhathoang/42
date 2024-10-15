/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:27:18 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 17:45:01 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack->next != NULL)
	{
		if (max->value < stack->next->value)
			max = stack->next;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack->next != NULL)
	{
		if (min->value > stack->next->value)
			min = stack->next;
		stack = stack->next;
	}
	return (min);
}

int	stack_len(t_stack *a)
{
	int	len;

	len = 0;
	while (a != NULL)
	{
		len++;
		a = a->next;
	}
	return (len);
}

int	stack_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->next->value < a->values)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack *a, char **array)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (array != NULL)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	free(array);
}
