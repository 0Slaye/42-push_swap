/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:46:14 by uwywijas          #+#    #+#             */
/*   Updated: 2023/12/15 16:18:51 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/imports.h"

int	get_tab_length(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int is_tab_unique(char **tab, int length)
{
	int	i;
	int	j;

	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < length)
		{
			if (j != i && ft_strncmp(tab[i], tab[j], ft_strlen(tab[i])) == 0)
				return (0);
		}
	}
	return (1);
}

int is_tab_valid(char **tab, int length)
{
	int		i;
	int		j;

	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < (int) ft_strlen(tab[i]))
		{
			if (!ft_isdigit(tab[i][j]))
				return (0);
		}
	}
	if (!is_tab_unique(tab, length))
		return (0);
	return (1);
}
