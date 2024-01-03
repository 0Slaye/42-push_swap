/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:38:26 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/03 15:43:09 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/commons.h"
#include "../../includes/imports.h"

void	sa(t_list *stack_a)
{
	t_list	*holder;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	holder = stack_a;
	stack_a = stack_a->next;
	stack_a = holder;
}
