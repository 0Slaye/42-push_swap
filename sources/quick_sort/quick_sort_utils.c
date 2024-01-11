/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:43 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/11 14:47:50 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"
#include "../includes/commons.h"
#include "../includes/operations.h"

int	get_app_pos(t_list **stack, t_list *item)
{
	t_list	*saver;
	int		counter;
	int		place;

	saver = *stack;
	counter = 0;
	place = 0;
	while (*stack)
	{
		if ((*stack) == item)
			place = counter;
		*stack = (*stack)->next;
		counter++;
	}
	*stack = saver;
	if (place > counter / 2)
		return (1);
	return (0);
}

int	lst_huv(t_list **stack, int value)
{
	t_list	*saver;

	saver = *stack;
	while (*stack)
	{
		if ((*stack)->content <= value && *stack != get_max(stack))
			return (*stack = saver, 1);
		*stack = (*stack)->next;
	}
	*stack = saver;
	return (0);
}

t_list	*get_min(t_list **stack)
{
	t_list	*result;
	t_list	*saver;
	int		counter;

	saver = *stack;
	counter = INT_MAX;
	while (*stack)
	{
		if ((*stack)->content < counter)
		{
			counter = (*stack)->content;
			result = *stack;
		}
		*stack = (*stack)->next;
	}
	*stack = saver;
	return (result);
}

t_list	*get_max(t_list **stack)
{
	t_list	*result;
	t_list	*saver;
	int		counter;

	saver = *stack;
	counter = INT_MIN;
	while (*stack)
	{
		if ((*stack)->content > counter)
		{
			counter = (*stack)->content;
			result = *stack;
		}
		*stack = (*stack)->next;
	}
	*stack = saver;
	return (result);
}

int	counter(t_list **stack)
{
	t_list	*saver;
	int		counter;

	counter = 0;
	saver = *stack;
	while (*stack)
	{
		*stack = (*stack)->next;
		counter++;
	}
	*stack = saver;
	return (counter);
}

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
