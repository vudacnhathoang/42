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

void handle_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);	
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

void check_duplicate(t_stack *a)
{
	t_stack *p;
	t_stack *q;

	p = a;
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (p->value == q->value)
			{
				handle_error("Duplicate input");
				free_stack(a, NULL);
			}
			q = q->next;
		}
		p = p->next;
	}

}
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
	check_duplicate(current);
	return current;
}