/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:25 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/16 18:47:25 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_half(int *stack)
{
	int i;

	i = 0;
	while (stack[i])
		i++;
	return (i / 2);
}

int		ft_is_sorted_a(int *stack_a)
{
	int i;

	i = 0;
	while (stack_a[i + 1])
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_sorted_b(int *stack_b)
{
	int i;

	i = 0;
	while (stack_b[i + 1])
	{
		if (stack_b[i] < stack_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	stack_printer(int *stack_a, int *stack_b)
{
	int i;

	i = 0;
	while (stack_a[i] || stack_b[i])
	{
		if (stack_a[i])
			ft_printf("%d\t", stack_a[i]);
		else
			ft_printf("\t");
		if (stack_b[i])
			ft_printf("%d", stack_b[i]);
		ft_printf("\n");
		i++;
	}
}

void	int_array_copy(int *stack_a, int *sorted)
{
	int i;

	i = -1;
	while (stack_a[++i])
		sorted[i] = stack_a[i];
}
