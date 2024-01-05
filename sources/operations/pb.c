/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:51:06 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/05 16:31:00 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commons.h"
#include "../../includes/operations.h"
#include "../../includes/imports.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list *holder;

	if (*stack_a == NULL)
		return ;
	holder = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = holder;
}
