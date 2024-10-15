/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:50:48 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/10/15 17:42:52 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <unistd.h>

typedef struct stack
{
	int				value;
	int				id;
	int				cost;
	int				a_median;
	int				cheapest;

	struct stack	*target;
	struct stack	*prev;
	struct stack	*next;
}	t_stack;

t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
void	swap_stack(t_stack **stack, char c);
void	push_stack(t_stack **src, t_stack **dest, char c);
void	rotate_stack(t_stack **stack, char c);
void	reverser_stack(t_stack **stack, char c);
void	sort_three(t_stack **stack);
int		ft_isnumber(char *s);
int		check_input(char **nums, int x);
t_stack	*innit_stack(char **nums);
void	print_stack(t_stack *p, t_stack *g);
int		stack_len(t_stack *a);
int		stack_sorted(t_stack *a);
void	indexing(t_stack *a);
void	target_for_a(t_stack *a, t_stack *b);
void	cost_calculate(t_stack *a, t_stack *b);
void	updating_a(t_stack *a, t_stack *b);
t_stack	*find_cheapest(t_stack *a);
void	rr(t_stack **a, t_stack **b, t_stack *cheapest);
void	rrr(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_sep(t_stack **a, t_stack **b, t_stack *cheapest);
void	push_cheapest(t_stack **a, t_stack **b);
void	target_for_b(t_stack *a, t_stack *b);
void	updating_b(t_stack *a, t_stack *b);
void	push_cheapest_b(t_stack **a, t_stack **b);
void	finish_sort(t_stack **a);
void	push_swap(t_stack **a, t_stack **b);
void	free_stack(t_stack *a, char **array);
void	handle_error(char *msg);
void	check_duplicate(t_stack *a, char **array);
#endif
