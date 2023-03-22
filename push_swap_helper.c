/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:45:25 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/21 19:56:45 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sorted_a(int *stack_a)
{
	int i;

	i = 0;
	while (stack_a && stack_a[i + 1])
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
		if (stack_b && stack_b[i] < stack_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}
void	one_stack_printer(int *stack_a)
{
	int i;

	i = -1;
	printf("\n");
	while (stack_a[++i])
	{
		if (stack_a[i])
			printf("%d\t", stack_a[i]);
		else
			printf("\t");
		printf("\n");
	}
}

void	stack_printer(int *stack_a, int *stack_b)
{
	int i;
	int gate;

	i = 0;
	gate = 1;
	printf("\n");
	while (stack_a[i] || stack_b[i])
	{
		if (stack_a[i])
			printf("%d\t", stack_a[i]);
		else
			printf("\t");
		if (stack_b[i] && gate)
			printf("%d", stack_b[i]);
		else
			gate = 0;
		if (stack_a[i])
			printf("\n");
		i++;
	}
}

void	int_array_copy(int *stack_a, int *sorted)
{
	int i;

	i = -1;
	while (stack_a && sorted && stack_a[++i])
		sorted[i] = stack_a[i];
}

int	insert_sort(int *stack_a, int argc)
{
	int i;
	int j;
	int temp;
	int	*sorted;

	sorted = (int *)malloc(sizeof(int) * argc);
	if (!sorted)
		return (0);
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
	temp = sorted[i / 2];
	free(sorted);
	return (temp);
}
