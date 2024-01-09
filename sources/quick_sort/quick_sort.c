/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:59 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/09 17:50:35 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"
#include "../includes/commons.h"
#include "../includes/operations.h"

int	get_step(t_list **stack, int stacks)
{
	return ((get_max(stack)->content + (get_min(stack)->content * -1)) / stacks);
}

void	sorter(t_list **stack_a, t_list **stack_b, t_list *max)
{
	int	is_reversed;

	is_reversed = get_app_pos(stack_b, max);
	if (is_reversed)
	{
		while (*stack_b != max)
			rrb(stack_b);
	}
	else
	{
		while (*stack_b != max)
			rb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *holder;
	int		stepper;
	int		starter;

	stepper = get_step(stack_a, 6);
	starter = get_min(stack_a)->content + stepper;
	while (*stack_a)
	{
		holder = ft_lstlast(*stack_a);
		while (*stack_a && *stack_a != holder)
		{
			if ((*stack_a)->content <= starter)
				pb(stack_a, stack_b);
			if (*stack_a == ft_lstlast(*stack_a))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		starter += stepper;
	}
	while (*stack_b)
	{
		holder = get_max(stack_b);
		sorter(stack_a, stack_b, holder);
	}
}
