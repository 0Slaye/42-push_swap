/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:59 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/06 16:26:39 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"
#include "../includes/commons.h"
#include "../includes/operations.h"

t_list	*get_min(t_list **stack)
{
	t_list	*start;
	t_list	*result;
	int		holder;

	start = *stack;
	result = *stack;
	holder = (*stack)->content;
	*stack = (*stack)->next;
	while (*stack)
	{
		if ((*stack)->content < holder)
		{
			result = *stack;
			holder = (*stack)->content;
		}
		*stack = (*stack)->next;
	}
	*stack = start;
	return (result);
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*holder;

	holder = get_min(stack_a);
	while (*stack_a != holder)
		ra(stack_a);
	pb(stack_a, stack_b);
}
