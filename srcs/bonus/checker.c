/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:41:40 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 14:31:41 by diogpere         ###   ########.fr       */
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

void	first_call(int argc, char **argv)
{
	int		i;
	int		*stack_a;
	int		*stack_b;

	i = -1;
	if (find_duplicates(argv) || find_non_letters(argv))
		free_both_exit(0, 0, 1);
	stack_a = (int *)malloc(sizeof(int) * (argc + 2));
	if (!stack_a)
		exit (0);
	stack_b = (int *)malloc(sizeof(int) * (argc + 2));
	if (!stack_b)
		free_both_exit(stack_a, 0, 0);
	while (++i < argc)
	{
		stack_a[i] = ft_bonus_atoi(argv[i], stack_a, stack_b);
		stack_b[i] = MAX_SORT;
	}
	stack_a[i] = MAX_SORT;
	stack_b[i] = MAX_SORT;
	grand_finale(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split;

	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2 && count_strings(argv[1], ' ') > 1)
	{
		split = ft_split(argv[1], ' ');
		first_call(str_arg(split), split);
	}
	else
	{
		while (argv[++i])
			argv[i - 1] = argv[i];
		argv[i - 1] = 0;
		first_call(argc - 1, argv);
	}
	return (0);
}
