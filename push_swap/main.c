/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:23:34 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/09/26 16:07:41 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdlib.h>
#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"


typedef struct stack
{
int 			value;
struct stack	*prev;
struct stack	*next;
}t_stack;

/*
void swap_stack(t_stack ** stack, char c)
{
	//swap 
}

void push_stack(t_stack **src,t_stack **dest,cahr c)
{
	//push	
}
void rotate_stack(t_stack **stack, char c)
{
	//rotate
}

void reverser_stack(t_stack **stack, char c)
{
	//reverse rotate	
}


*/
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


void print_stack(t_stack *p)
{
	while (p!= NULL)
	{
		ft_printf("%d\n", p->value);
		p = p->next;
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
	print_stack(a);
}
