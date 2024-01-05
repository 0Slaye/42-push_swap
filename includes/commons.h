/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:50:45 by uwywijas          #+#    #+#             */
/*   Updated: 2024/01/05 15:16:19 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMONS_H
# define COMMONS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "imports.h"

int		get_tab_length(char **tab);
int		is_tab_valid(char **tab, int length);
void	quick_sort(t_list **stack_a, t_list **stack_b);

#endif