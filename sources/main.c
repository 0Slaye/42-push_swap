/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:44:46 by uwywijas          #+#    #+#             */
/*   Updated: 2023/12/15 16:05:04 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"
#include "../includes/commons.h"

int	main(int argc, char **argv)
{
	char	**numbers;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (ft_putstr_fd("Error\n", 2), 1);
		if (!is_tab_valid(numbers, get_tab_length(numbers)))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else if (argc > 2)
	{
		if (!is_tab_valid(&argv[1], argc - 1))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	return (0);
}
