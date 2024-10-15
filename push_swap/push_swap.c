/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:23:34 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 18:11:31 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handle_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
	
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
	return current;
}


int	main(int ac, char *ag[])
{
	t_stack	*a;
	t_stack	*b;
	char **array;

	a = NULL;
	b = NULL;
	array = NULL;
	if (ac < 2)
		handle_error("Please input numbers");
	if (ac > 2)
	{
		if(!check_input(ag, 1))
			handle_error("Not valid input");
		a = innit_stack(&ag[1]);
	}
	if (ac == 2)
	{
		array = ft_split(ag[1], ' ');
		if (!check_input(array, 0))
			handle_error("Not valid input");
		a = innit_stack(array);
	}
	push_swap(&a, &b);
	free_stack(a, array);
}
