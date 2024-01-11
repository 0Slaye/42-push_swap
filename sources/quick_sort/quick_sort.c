/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:59 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/11 17:10:04 by uwywijas         ###   ########.fr       */
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

t_list	*get_max_n1(t_list **stack)
{
	t_list	*holder;
	t_list	*result;
	t_list	*saver;
	int		counter;

	holder = get_max(stack);
	saver = *stack;
	counter = INT_MIN;
	while (*stack)
	{
		if ((*stack)->content > counter && *stack != holder)
		{
			counter = (*stack)->content;
			result = *stack;
		}
		*stack = (*stack)->next;
	}
	*stack = saver;
	return (result);
}

void	sorter(t_list **stack_a, t_list **stack_b, t_list *max, t_list *max2)
{
	int	is_reversed;
	int	is_double;

	is_double = 0;
	is_reversed = get_app_pos(stack_b, max);
	if (is_reversed)
	{
		while (*stack_b != max)
		{
			if (*stack_b == max2)
			{
				pa(stack_a, stack_b);
				is_double = 1;
			}
			else
				rrb(stack_b);
		}
	}
	else
	{
		while (*stack_b != max)
		{
			if (*stack_b == max2)
			{
				pa(stack_a, stack_b);
				is_double = 1;
			}
			else
				rb(stack_b);
		}
	}
	pa(stack_a, stack_b);
	if (is_double)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			ss(stack_a, stack_b);
		else
			sa(stack_a);
		//sa(stack_a);
	}
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*holder;
	int		stepper;
	int		starter;

	stepper = get_step(stack_a, 10); // 100 = 6 / 500 = 10 / 5 = 1
	starter = get_min(stack_a)->content + stepper;
	holder = get_max(stack_a);
	if (is_sorted(stack_a))
		return ;
	while (counter(stack_a) != 1)
	{
		while (lst_huv(stack_a, holder, starter) && counter(stack_a) != 1)
		{
			if ((*stack_a)->content <= starter && *stack_a != holder)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->content < starter - (stepper / 2) && (*stack_b)->next)
				{
					if ((*stack_a)->next && !((*stack_a)->content <= starter && *stack_a != holder))
						rr(stack_a, stack_b);
					else
						rb(stack_b);
				}
			}
			else
				ra(stack_a);
		}
		starter += stepper;
	}
	while (*stack_b)
	{
		holder = get_max(stack_b);
		sorter(stack_a, stack_b, holder, get_max_n1(stack_b));
	}
}
