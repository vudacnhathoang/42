/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:23:34 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/03 14:25:00 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <string.h>
typedef struct stack
{
int 			value;
int				id;
int				cost;
int				a_median;
int				cheapest;

struct stack	*target;
struct stack	*prev;
struct stack	*next;
}t_stack;


t_stack	*find_biggest(t_stack * stack)
{
	t_stack *max;

	max = stack;
	while  (stack->next!= NULL)
	{
		if (max->value < stack->next->value)
			max = stack->next;
		stack = stack->next;
	} 
	return max;			
}


void swap_stack(t_stack ** stack, char c)
{
	t_stack *a;
	t_stack *b;
	
	if(!(*stack) || !stack || !(*stack)->next)
		return;

	a = *stack;
	b = (*stack)->next;
	a->next = b->next;
	b->next = a;
	b->prev = NULL;
	a->prev = b;
	*stack = b;
	if (c =='f')
		return;
	//ft_printf("s%c\n", c);
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
//	ft_printf("p%c\n", c);
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
	//ft_printf("r%c\n", c);
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
	//ft_printf("rr%c", c);	
 }

void sort_three(t_stack **stack)
{
	t_stack *biggest;

	biggest = find_biggest(*stack);
	if (*stack == biggest)
		rotate_stack(stack, 'a');
	else if ((*stack)->next == biggest)
		reverser_stack(stack, 'a');
	if ((*stack)->value > (*stack)->next->value)
		swap_stack(stack, 'a');
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

//CHECK IF ITS OUT OF RANGE INT MAX INT MIN
t_stack*	innit_stack(char **nums)
{
	int		num;
	t_stack	*head;
	t_stack	*current;
	t_stack  *new;
	
	head = NULL;
	current = NULL;
	while (*nums)
	{
		num = ft_atoi(*nums);
		new = (t_stack*)malloc(sizeof(t_stack));
		new->value = num;
		new->prev = NULL;
		new->next = current;
		if (head == NULL)
			head = new;
		else
			current->prev = new;
		current = new;
		nums++;
	}
	return current;
}


void print_stack(t_stack *p, t_stack *g)
{
	ft_printf("a   b\n");
	ft_printf("-----\n");
	while (p!= NULL || g != NULL)
	{
		if (p != NULL)
		{
			ft_printf("%d   ", p->value);
				p = p->next;
		}
		else 
			ft_printf("    ");
		if (g != NULL)
		{	
			ft_printf("%d",g->value);
				g = g->next;
		}
		ft_printf("\n");
	}

}


int		stack_len(t_stack *a)
{
	int len;

	len = 0;
	while(a != NULL)
	{
		len++;
		a = a->next;
	}
	return len;
}

int	stack_sorted(t_stack *a)
{
	while(a->next != NULL)
	{
		if (a->next->value < a->value )
			return (0);
		a = a->next;
	}
	return (1);
} 

void push_swap(t_stack **a, t_stack **b)
 {
	int	size_a;

	size_a = stack_len(*a);
	if (size_a-- > 3 && !stack_sorted(*a))
		push_stack(a, b, 'b');
	if (size_a-- > 3 && !stack_sorted(*a))
		push_stack(a, b, 'b');
	while (size_a-- > 3 && !stack_sorted(*a))
	{
		

	}	

	
 }

int main(int ac, char **ag)
{

t_stack *a;
t_stack *b;

a = NULL;
b = NULL;

if (ac < 2)
{
	ft_printf("please input numbers\n");
	return (1);
}
if (ac > 2)
{
	if(!check_input(ag, 1))
		return (1);
	a = innit_stack(&ag[1]);
}
if (ac == 2)
	{
	ag = ft_split(ag[1], ' ');
	if (!check_input(ag, 0))
		return (1);
	a = innit_stack(ag);
	}
	print_stack(a,b);
}

