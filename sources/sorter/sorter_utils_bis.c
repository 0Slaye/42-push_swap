/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:43 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/15 15:58:17 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/imports.h"
#include "../../includes/commons.h"
#include "../../includes/operations.h"

int	is_sorted(t_list **stack)
{
	t_list	*saver;

	saver = *stack;
	while ((*stack)->next)
	{
		if ((*stack)->content > (*stack)->next->content)
			return (*stack = saver, 0);
		*stack = (*stack)->next;
	}
	*stack = saver;
	return (1);
}

void	triple_sorter(t_list **stack_a)
{
	if (*stack_a == get_min(stack_a))
		return (sa(stack_a), ra(stack_a));
	else if (*stack_a != get_max(stack_a))
	{
		if ((*stack_a)->next == get_max(stack_a))
			return (rra(stack_a));
		else
			return (sa(stack_a));
	}
	else
	{
		if ((*stack_a)->next != get_min(stack_a) \
		&& (*stack_a)->next != get_max(stack_a))
			return (sa(stack_a), rra(stack_a));
		else
			return (ra(stack_a));
	}
}

int	get_stacks(t_list **stack_a)
{
	if (counter(stack_a) == 5)
		return (2);
	if (counter(stack_a) < 25)
		return (1);
	else if (counter(stack_a) < 50)
		return (2);
	else if (counter(stack_a) == 100)
		return (6);
	else if (counter(stack_a) == 500)
		return (10);
	else
		return (counter(stack_a) / 20);
}
