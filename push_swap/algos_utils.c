/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:18:45 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 17:20:10 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack *a)
{
	int	i;
	int	med;

	i = 0;
	if (!a)
		return ;
	med = stack_len(a) / 2;
	while (a)
	{
		a->id = i;
		if (i <= med)
			a->a_median = 1;
		else
			a->a_median = 0;
		a = a->next;
		i++;
	}
}

void	target_for_a(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*n_target;
	int		matching;

	while (a)
	{
		matching = INT_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > matching)
			{
				matching = curr_b->value;
				n_target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (matching == INT_MIN)
			a->target = find_biggest(b);
		else
			a->target = n_target;
		a = a->next;
	}
}

void	target_for_b(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*n_target;
	int		matching;

	while (b)
	{
		matching = INT_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < matching)
			{
				matching = curr_a->value;
				n_target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (matching == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = n_target;
		b = b->next;
	}
}

void	cost_calculate(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	int		len_a;
	int		len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	curr_a = a;
	while (curr_a)
	{
		curr_a->cost = 0;
		if (curr_a->a_median == 1)
			curr_a->cost = curr_a->id;
		else
			curr_a->cost = len_a - curr_a->id;
		if (curr_a->target->a_median == 1)
			curr_a->cost += curr_a->target->id;
		else
			curr_a->cost += len_b - curr_a->target->id;
		curr_a = curr_a->next;
	}
}
