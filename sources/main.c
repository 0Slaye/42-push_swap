/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:44:46 by uwywijas          #+#    #+#             */
/*   Updated: 2023/12/15 15:26:20 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"

int	main(int argc, char **argv)
{
	char	**numbers;
	int		i;
	int		j;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		i = 0;
		while (++i < argc)
		{
			j = -1;
			while (++j < (int) ft_strlen(argv[i]))
			{
				if (!ft_isdigit(argv[i][j]))
					return (ft_putstr_fd("Error\n", 2), 1);
			}
		}
	}
	return (0);
}
