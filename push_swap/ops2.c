/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:26:07 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 18:12:41 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rr (t_stack **a, t_stack **b,t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
	{
		rotate_stack(a, 'r');
		rotate_stack(b, 'r');
		ft_printf("rr\n");
	}
	while (*a != cheapest)
		rotate_stack(a, 'a');
	while (*b != cheapest->target)
		rotate_stack(b, 'b');
}

void rrr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
	{
		reverser_stack(a, 'r');
		reverser_stack(b, 'r');
		ft_printf("rrr\n");
	}
	while (*a != cheapest)
		reverser_stack(a, 'a');
	while (*b != cheapest->target)
		reverser_stack(b, 'b');
	
}

void rotate_sep(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->a_median)
		while (*a != cheapest)
			rotate_stack(a, 'h');
	else
		while (*a != cheapest)
			reverser_stack(a, 'h');
	if (cheapest->target->a_median)
		while (*b != cheapest->target)
			rotate_stack(b, 'h');
	else
		while (*b != cheapest->target)
			reverser_stack(b, 'h');
}

void	finish_sort(t_stack **a)
{
	t_stack *smallest;
	smallest = find_smallest(*a);
	if (*a != smallest)
	{ 
		if (smallest->a_median)
			while (*a != smallest)
				rotate_stack(a, 'a');
		else
			while (*a != smallest)
				reverser_stack(a, 'a');
	}
}

t_stack	*find_cheapest(t_stack *a)
{
	t_stack *curr_a;
	t_stack *cheapest;

	curr_a = a;
	cheapest = a;
	while(curr_a)
	{
		if (curr_a->cost < cheapest->cost)
			cheapest = curr_a;
		curr_a = curr_a->next;
	}
	return cheapest;
}