/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:32:59 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/08 18:43:10 by uwywijas         ###   ########.fr       */
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

void	small_sorter(t_list **stack_a, t_list **stack_b, t_list *pivot)
{
	while (*stack_a != pivot)
	{
		if ((*stack_a)->content <= pivot->content)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	big_sorter(t_list **stack_a, t_list **stack_b, t_list *max)
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
	t_list	*pivot;
	t_list	*max;

	while (*stack_a)
	{
		pivot = ft_lstlast(*stack_a);
		small_sorter(stack_a, stack_b, pivot);
	}
	while (*stack_b)
	{
		max = get_max(stack_b);
		big_sorter(stack_a, stack_b, max);
	}
}
