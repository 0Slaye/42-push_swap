/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:59 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/11 15:00:49 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"
#include "../includes/commons.h"
#include "../includes/operations.h"

int	get_step(t_list **stack, int stacks)
{
	if (get_min(stack)->content < 0)
		return ((get_max(stack)->content + (get_min(stack)->content * -1)) / stacks);
	return ((get_max(stack)->content + get_min(stack)->content) / stacks);
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
	t_list	*holder;
	int		stepper;
	int		starter;

	stepper = get_step(stack_a, 6); // 100 = 6 / 500 = 14 / 5 = 1
	starter = get_min(stack_a)->content + stepper;
	holder = get_max(stack_a);
	if (is_sorted(stack_a))
		return ;
	while (counter(stack_a) != 1)
	{
		while (lst_huv(stack_a, holder, starter) && counter(stack_a) != 1)
		{
			if ((*stack_a)->content <= starter && *stack_a != holder)
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
