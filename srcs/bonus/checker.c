/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:41:40 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 13:39:45 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	int		*stack_a;
	int		*stack_b;

	if (argc < 2)
		return (0);
	i = 0;
	stack_a = (int *)malloc(sizeof(int) * argc + 1);
	stack_b = (int *)malloc(sizeof(int) * argc + 1);
	if (!stack_a || !stack_b)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_bonus_atoi(argv[i], stack_a, stack_b);
	stack_a[i - 1] = MAX_SORT;
	stack_b[i - 1] = MAX_SORT;
	if (find_duplicates(stack_a) || find_non_letters(argv))
		free_both_exit(stack_a, stack_b, 1);
	while (1)
		if (!action_taker(stack_a, stack_b))
			break ;
	if (!*stack_b && ft_is_sorted_a(stack_a))
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
	free_both_exit(stack_a, stack_b, 0);
}
