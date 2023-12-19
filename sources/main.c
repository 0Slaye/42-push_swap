/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:44:46 by uwywijas          #+#    #+#             */
/*   Updated: 2023/12/19 16:46:56 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imports.h"
#include "../includes/commons.h"

void	push_swap(char **tab, int length)
{
	int		i;
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = malloc(sizeof(t_list **));
	stack_b = malloc(sizeof(t_list **));
	if (stack_a == NULL)
		exit(EXIT_FAILURE);
	if (stack_b == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < length)
	{
		stack_a[i] = ft_lstnew(ft_atoi(tab[i]));
		printf("| %d |\n", stack_a[i]->content);
		if (stack_a[i] == NULL)
			return (ft_lstclear(stack_a), free(stack_a));
	}
	//quick_sort(stack_a, stack_b);
}

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
		push_swap(numbers, get_tab_length(numbers));
	}
	else if (argc > 2)
	{
		if (!is_tab_valid(&argv[1], argc - 1))
			return (ft_putstr_fd("Error\n", 2), 1);
		push_swap(&argv[1], argc - 1);
	}
	return (0);
}
