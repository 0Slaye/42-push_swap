/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:15:27 by uwywijas          #+#    #+#             */
/*   Updated: 2023/12/19 16:45:15 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*holder;

	if (lst == NULL)
		return ((void) NULL);
	while (*lst)
	{
		holder = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = holder;
	}
	*lst = NULL;
}
