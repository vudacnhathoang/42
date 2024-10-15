/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:22:23 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 17:25:11 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_stack(t_stack **stack, char c)
{
	t_stack *a;
	t_stack *b;
	
	if(!(*stack) || !stack || !(*stack)->next)
		return;

	a = *stack;
	b = (*stack)->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	b->next = a;
	b->prev = NULL;
	a->prev = b;
	*stack = b;
	if (c != 'r')
		ft_printf("s%c\n", c);
}

void push_stack(t_stack **src,t_stack **dest,char c)
{
	t_stack	*top;
	 
 	if(!src|| !(*src))
		return;
	top = *src;
	*src = top->next;
	if(*src)
		(*src)->prev = NULL;
	top->next = *dest;
	if(*dest)
		(*dest)->prev = top;
	*dest = top;
	if (c == 's')
		return;
	ft_printf("p%c\n", c);
}

void rotate_stack(t_stack **stack, char c)
{
	t_stack	*first;
	t_stack	*last;
	
	if(!stack|| !(*stack)|| (*stack)->next == NULL)
		return;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (c == 'r')
		return;
	ft_printf("r%c\n", c);
}
void reverser_stack(t_stack **stack, char c)
{
	t_stack	*bottom;
	
	if(!stack|| !(*stack)|| (*stack)->next == NULL)
		return;
	bottom = *stack;
	while(bottom->next != NULL)
		bottom = bottom->next;
	(*stack)->prev = bottom;
	bottom->prev->next = NULL;
	bottom->next =*stack;
	*stack = bottom;
	if (c == 'r')
		return;
	ft_printf("rr%c\n", c);	
}

void sort_three(t_stack **stack)
{
	t_stack *biggest;

	biggest = find_biggest(*stack);
	if (*stack == biggest)
		rotate_stack(stack, 'a');
	else if ((*stack)->next == biggest)
	{
		reverser_stack(stack, 'a');
	}
	if ((*stack)->value > (*stack)->next->value)
		swap_stack(stack, 'a');
}