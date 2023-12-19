/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:50:45 by uwywijas          #+#    #+#             */
/*   Updated: 2023/12/19 16:32:37 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

int		get_tab_length(char **tab);
int		is_tab_valid(char **tab, int length);
void	quick_sort(t_list **stack_a, t_list **stack_b);

#endif