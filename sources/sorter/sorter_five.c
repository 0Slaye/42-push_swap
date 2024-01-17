/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:31:29 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/17 17:06:19 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/imports.h"
#include "../../includes/commons.h"
#include "../../includes/operations.h"

t_list	*get_max_n2(t_list **stack)
{
	t_list	*holder;
	t_list	*holder2;
	t_list	*result;
	t_list	*saver;
	int		counter;

	holder = get_max_n1(stack);
	holder2 = get_max(stack);
	saver = *stack;
	counter = INT_MIN;
	while (*stack)
	{
		if ((*stack)->content >= counter && *stack != holder2 \
		&& *stack != holder)
		{
			counter = (*stack)->content;
			result = *stack;
		}
		*stack = (*stack)->next;
	}
	*stack = saver;
	return (result);
}

void	sorter_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	t_list	*max2;
	t_list	*max3;

	max = get_max(stack_a);
	max2 = get_max_n1(stack_a);
	max3 = get_max_n2(stack_a);
	while (counter(stack_a) != 3)
	{
		if (*stack_a != max && *stack_a != max2 && *stack_a != max3)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (!is_sorted(stack_a))
		triple_sorter(stack_a);
	if (get_max(stack_b) != *stack_b)
		rb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
