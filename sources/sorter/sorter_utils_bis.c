/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:03:43 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/11 18:16:43 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"
#include "../includes/commons.h"
#include "../includes/operations.h"

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
