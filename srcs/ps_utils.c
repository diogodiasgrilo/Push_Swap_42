/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:25 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/24 14:18:34 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	int_array_copy(int *stack_a, int *sorted)
{
	int	i;

	i = -1;
	while (stack_a && sorted && stack_a[++i])
		sorted[i] = stack_a[i];
	sorted[i] = '\0';
}

int	find_smallest_in_array(int *stack_a)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = stack_a[0];
	while (stack_a[i])
	{
		if (stack_a[i] < smallest)
			smallest = stack_a[i];
		i++;
	}
	return (smallest);
}

int	find_biggest_index(int *stack)
{
	int	i;
	int	biggest;
	int	biggest_index;

	i = 0;
	biggest = stack[0];
	biggest_index = 0;
	while (stack[i])
	{
		if (stack[i] > biggest)
		{
			biggest = stack[i];
			biggest_index = i;
		}
		i++;
	}
	return (biggest_index);
}

int	find_biggest_in_array(int *stack_a)
{
	int	i;
	int	biggest;

	i = 0;
	biggest = stack_a[0];
	while (stack_a[i])
	{
		if (stack_a[i] > biggest)
			biggest = stack_a[i];
		i++;
	}
	return (biggest);
}

int	find_second_biggest_in_array(int *stack, int first_big)
{
	int	i;
	int	second_biggest;

	i = 0;
	second_biggest = stack[0];
	while (stack[i])
	{
		if (stack[i] != first_big && stack[i] > second_biggest)
			second_biggest = stack[i];
		i++;
	}
	return (second_biggest);
}
