/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 05:45:14 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/24 15:44:53 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	free_and_exit(int *stack, int gate)
{
	if (!gate && !ft_is_sorted_a(stack))
		sa(stack, 1);
	free(stack);
	if (gate)
		exit(1);
	exit(0);
}

int	count_all(int *stack)
{
	int	i;

	i = 0;
	while (stack && stack[i])
		i++;
	return (i - 1);
}

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

int	ft_atoi(const char *str, int *stack_a)
{
	long int	i;
	long int	total;
	int			sign;

	total = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = (str[i] != '-') - (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += str[i++] - 48;
	}
	total *= sign;
	if (total > INT_MAX || total < INT_MIN)
	{
		write(1, "Error\n", 6);
		free_and_exit(stack_a, 1);
	}
	return (total);
}