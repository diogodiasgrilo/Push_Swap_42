/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 05:45:14 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/09 05:45:44 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_a(int *stack_a)
{
	int	i;

	i = 0;
	while (*stack_a && stack_a[i + 1])
	{
		if (*stack_a && stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sorted_b(int *stack_b)
{
	int	i;

	i = 0;
	while (stack_b && stack_b[i + 1])
	{
		if (stack_b && stack_b[i] < stack_b[i + 1])
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
	while (sorted[++i])
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
	sorted[i] = '\0';
	temp = sorted[i / divide];
	return (temp);
}
