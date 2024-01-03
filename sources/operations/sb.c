/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:38:26 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/03 15:43:37 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commons.h"
#include "../../includes/imports.h"

void	sb(t_list *stack_b)
{
	t_list	*holder;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	holder = stack_b;
	stack_b = stack_b->next;
	stack_b = holder;
}
