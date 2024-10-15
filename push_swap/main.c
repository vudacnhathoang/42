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


#define INT_MIN -2147483648
#define INT_MAX 2147483647

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

t_stack	*find_smallest(t_stack * stack)
{
	t_stack *min;

	min = stack;
	while  (stack->next!= NULL)
	{
		if (min->value > stack->next->value)
			min= stack->next;
		stack = stack->next;
	} 
	return min;			
}

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
		ft_printf("         \n");
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

void indexing(t_stack *a)
{
	int i;
	int med;

	i = 0;
	if(!a)
		return;
	med = stack_len(a) / 2;
	while(a)
	{
		a->id =i;
		if(i <= med)
			a->a_median = 1;
		else
			a->a_median = 0;
		a= a->next;
		i++;
	}
}

void target_for_a(t_stack *a, t_stack *b)
{
	t_stack *curr_b;
	t_stack *n_target;
	int		matching;

	while(a)
	{
		matching = INT_MIN;
		curr_b = b;
		while(curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > matching)
			{
				matching = curr_b->value;
				n_target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if(matching == INT_MIN)
			a->target = find_biggest(b);
		else
			a->target = n_target;
		a = a->next;
	}
}


void cost_calculate(t_stack *a, t_stack *b)
{
	t_stack *curr_a;
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	curr_a = a;
	while (curr_a)
	{
		curr_a->cost = 0;
		if (curr_a->a_median == 1 )
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
void updating_a(t_stack *a, t_stack *b)
{
	indexing(a);
	indexing(b);
	target_for_a(a,b);
	cost_calculate(a,b);
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

void target_for_b(t_stack *a, t_stack *b)
{
	t_stack *curr_a;
	t_stack *n_target;
	int		matching;

	while(b)
	{
		matching = INT_MAX;
		curr_a = a;
		while(curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < matching)
			{
				matching = curr_a->value;
				n_target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if(matching == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = n_target;
		b = b->next;
		
	}
}

void updating_b(t_stack *a, t_stack *b)
{
	indexing(a);
	indexing(b);
	target_for_b(a,b);
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

void	finish_sort(t_stack **a)
{
	t_stack *smallest;
	smallest = find_smallest(*a);
	if (smallest->a_median)
		while (*a != smallest)
			rotate_stack(a, 'a');
	else
		while (*a != smallest)
			reverser_stack(a, 'a');
}

void push_swap(t_stack **a, t_stack **b)
 {
	int	size_a;

	size_a = stack_len(*a);
	if (size_a-- > 3)
		push_stack(a, b, 'b');
	//print_stack(*a, *b);
	if (size_a-- > 3 )
		push_stack(a, b, 'b');
	//print_stack(*a, *b);
	while (size_a-- > 3)
	{
		updating_a(*a, *b);
		push_cheapest(a, b);
		//print_stack(*a, *b);
	}	
	sort_three(a);
	while (*b != NULL)
	{
		updating_b(*a, *b);
		push_cheapest_b(a, b);
		//print_stack(*a, *b);
	}
	finish_sort(a);
	print_stack(*a, *b);
 }

void free_stack(t_stack *a)
{
	t_stack *tmp;

	while(a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
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
	push_swap(&a,&b);
	free_stack(a);
}
