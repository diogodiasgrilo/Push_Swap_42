/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:41:40 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/24 15:40:47 by diogpere         ###   ########.fr       */
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
	stack_b = (int *)ft_calloc(argc - 1, 4);
	if (!stack_a || !stack_b)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_bonus_atoi(argv[i], stack_a, stack_b);
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

// void	stack_printer(int *stack_a, int *stack_b)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (stack_a[i] || stack_b[j])
// 	{
// 		if (stack_a[i] == 0 || stack_a[i])
// 			printf("%d\t", stack_a[i]);
// 		else
// 			printf("\t");
// 		if (stack_a[i] == 0 || stack_a[i])
// 			printf("%d", stack_b[j]);
// 		printf("\n");
// 		i++;
// 		j++;
// 	}
// }
