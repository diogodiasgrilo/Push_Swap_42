/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 05:45:14 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 10:18:24 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_done(int *stack_a, int *stack_b)
{
	if (ft_is_sorted_a(stack_a) && *stack_b == MAX_SORT)
		return (1);
	return (0);
}

void	small_call(int *stack_a)
{
	if (stack_a[0] > stack_a[1])
		sa(stack_a, 1);
	if (stack_a[1] > stack_a[2] && stack_a[2] != MAX_SORT)
		rra(stack_a, 1);
	if (stack_a[0] > stack_a[2] && stack_a[2] != MAX_SORT)
		ra(stack_a, 1);
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a, 1);
	free_and_exit(stack_a, 0);
}

int	ft_is_sorted_a(int *stack_a)
{
	int	i;

	i = 0;
	while (*stack_a != MAX_SORT && stack_a[i + 1] != MAX_SORT)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	insert_sort(int *stack_a, int divide, int *sorted)
{
	int	i;
	int	j;
	int	temp;

	int_array_copy(stack_a, sorted);
	i = -1;
	while (sorted[++i] != MAX_SORT)
	{
		j = i;
		while (j > 0 && sorted[j - 1] > sorted[j])
		{
			temp = sorted[j];
			sorted[j] = sorted[j - 1];
			sorted[j - 1] = temp;
			j--;
		}
	}
	sorted[i] = MAX_SORT;
	temp = sorted[i / divide];
	return (temp);
}

int	str_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
		i++;
	return (i);
}
