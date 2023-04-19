/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:41:40 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/19 17:57:22 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_and_return(int *stack, int gate)
{
	if (gate)
		sa(stack);
	free(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;

	i = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i]);
	if (find_duplicates(stack_a) || find_non_letters(argv)
		|| ft_is_sorted_a(stack_a))
		return (free_and_return(stack_a, 0));
	
	
	return (free_and_return(stack_a, 0));
}