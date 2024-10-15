/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:15:04 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 18:08:04 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
 {
	int	size_a;

	size_a = stack_len(*a);
	if (size_a-- > 3)
		push_stack(a, b, 'b');
	if (size_a-- > 3 )
		push_stack(a, b, 'b');
	while (size_a-- > 3)
	{
		updating_a(*a, *b);
		push_cheapest(a, b);
	}	
		sort_three(a);
	while (*b != NULL)
	{
		updating_b(*a, *b);
		push_cheapest_b(a, b);
	}
	finish_sort(a);
 }
 
void	updating_a(t_stack *a, t_stack *b)
{
	indexing(a);
	indexing(b);
	target_for_a(a,b);
	cost_calculate(a,b);
}

void	updating_b(t_stack *a, t_stack *b)
{
	indexing(a);
	indexing(b);
	target_for_b(a,b);
}

void push_cheapest(t_stack **a, t_stack **b)
{
	t_stack *cheapest;

	cheapest = find_cheapest(*a);
	if (cheapest->a_median && cheapest->target->a_median)
		rr(a,b, cheapest);
	if(!cheapest->a_median && !cheapest->target->a_median)
		rrr(a,b, cheapest);
	else 
		rotate_sep(a,b, cheapest);
	push_stack(a,b  ,'b');
}

void push_cheapest_b(t_stack **a, t_stack **b)
{
	if ((*b)->target->a_median)
		while (*a != (*b)->target)
			rotate_stack(a, 'a');
	else
		while (*a != (*b)->target)
			reverser_stack(a, 'a');
	push_stack(b,a, 'a');
}