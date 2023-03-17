/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/16 20:47:46 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(int *stack_a, int *stack_b, int middle, int size)
{
	int i;
	int half;
	int counter;

	i = 0;
	counter = 0;
	half = count_half(stack_a);
	printf("middle: %d\n", middle);
	while (i <= size && counter <= half)
	{
		if (stack_a[0] < middle)
			pb(stack_a, stack_b, i, &counter);
		else
		{
			size = (count_half(stack_a) * 2) - 1;
			printf("size: %d\n", size);
			while (stack_a[size] < middle && counter <= half)
			{
				rra(stack_a);
				pb(stack_a, stack_b, 0, &counter);
				size = (count_half(stack_a) * 2) - 1;
			}
			while (counter < half)
			{
				if (stack_a[0] < middle)
					pb(stack_a, stack_b, 0, &counter);
				else
					ra(stack_a);
			}
			break;
		}
		i++;
	}
	stack_printer(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	int	*stack_b;

	i = -1;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	stack_b = (int *)malloc(sizeof(int) * argc - 1);
	while (++i < argc - 1)
		stack_a[i] = ft_atoi(argv[argc - i - 1]);
	stack_printer(stack_a, stack_b);
	if(ft_is_sorted_a(stack_a))
		return (0);
	while (*(stack_a + 2))
		push_swap(stack_a, stack_b, insert_sort(stack_a, argc - 1), argc - 2);
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a);
	// ft_printf("Is sorted?: %d\n", ft_is_sorted(stack_a));
	while (*stack_a)
		pb(stack_a, stack_b, 0, 0);
	stack_printer(stack_a, stack_b);
	if (ft_is_sorted_b(stack_b))
	{
		while(*stack_b)
			pa(stack_a, stack_b, 0, 0);
		stack_printer(stack_a, stack_b);
	}
	return (0);
}
