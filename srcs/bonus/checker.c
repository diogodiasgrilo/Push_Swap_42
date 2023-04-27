/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:41:40 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 10:54:49 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

void	grand_finale(int *stack_a, int *stack_b)
{
	while (1)
		if (!action_taker(stack_a, stack_b))
			break ;
	if (*stack_b == MAX_SORT && ft_is_sorted_a(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_both_exit(stack_a, stack_b, 0);
}

void	first_call(int argc, char **argv, int start, int sub)
{
	int		*stack_a;
	int		*stack_b;

	if (find_duplicates(argv, start) || find_non_letters(argv, start))
		free_both_exit(0, 0, 1);
	stack_a = (int *)malloc(sizeof(int) * (argc - start));
	stack_b = (int *)malloc(sizeof(int) * (argc - start));
	if (!stack_a)
		exit (0);
	if (!stack_b)
		free_both_exit(stack_a, 0, 0);
	stack_a[argc - sub] = MAX_SORT;
	stack_b[0] = MAX_SORT;
	while (++start < argc)
	{
		stack_a[start - sub] = ft_bonus_atoi(argv[start], stack_a, stack_b);
		stack_b[start - sub] = MAX_SORT;
	}
	grand_finale(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**split;

	if (argc < 2)
		return (0);
	if (argc == 2 && count_strings(argv[1], ' ') > 1)
	{
		split = ft_split(argv[1], ' ');
		first_call(str_arg(split), split, -1, 0);
	}
	else
		first_call(argc, argv, 0, 1);
	return (0);
}
