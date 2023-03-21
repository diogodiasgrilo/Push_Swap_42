/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/21 11:26:27 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_count = 0;

int	push_swap(int *stack_a, int *stack_b, int middle, int size)
{
	int half;
	int	checker;
	int counter;
	int	ra_counter;

	counter = 0;
	checker = 0;
	ra_counter = 0;
	half = count_half(stack_a);
	printf("middle: %d\n", middle);
	while (counter < half)
	{
		if (stack_a[0] < middle)
		{
			if (stack_a[1] < middle && stack_a[0] > stack_a[1])
			{
				sa(stack_a);
				operation_count++;
			}
			pb(stack_a, stack_b, &counter);
			operation_count++;
			if (*(stack_b + 1) && stack_b[0] < stack_b[1])
			{
				sb(stack_b);
				operation_count++;
			}
		}
		else
		{
			size = count_all(stack_a);
			// printf("size: %d\n", size);
			while (stack_a[size] < middle && counter < half && !ft_is_sorted_a(stack_a))
			{
				rra(stack_a);
				operation_count++;
				if (stack_a[0] < middle && stack_a[1] < middle && stack_a[0] > stack_a[1])
				{
					sa(stack_a);
					operation_count++;
				}
				pb(stack_a, stack_b, &counter);
				operation_count++;
				if (*(stack_b + 1) && stack_b[0] < stack_b[1])
				{
					sb(stack_b);
					operation_count++;
				}
				size = count_all(stack_a);
			}
			while (!ft_is_sorted_a(stack_a))
			{
				if (stack_a[0] < middle)
				{
					if (stack_a[1] < middle && stack_a[0] > stack_a[1])
					{
						sa(stack_a);
						operation_count++;
					}
					pb(stack_a, stack_b, &counter);
					operation_count++;
					if (*(stack_b + 1) && stack_b[0] < stack_b[1])
					{
						sb(stack_b);
						operation_count++;
					}
				}
				else if (++ra_counter)
				{
					ra(stack_a);
					counter++;
					operation_count++;
				}
				checker = 0;
				while (stack_a[checker] >= middle)
					checker++;
				if (!stack_a[checker])
					break;
			}
			break;
		}
	}
	return (ra_counter);
}

int	*the_big_caller(int *stack_a, int argc, int gate)
{
	int	i;
	int	middle_one;
	int	*stack_b;
	int	*stack_final;

	stack_b = (int *)malloc(sizeof(int) * argc);
	i = 0;
	while (i < argc)
		stack_b[i++] = 0;
	middle_one  = insert_sort(stack_a, argc);
	while (!ft_is_sorted_a(stack_a))
	{
		i = push_swap(stack_a, stack_b, insert_sort(stack_a, argc), count_all(stack_a));
		if (gate > 0)
		{
			while (--i >= 0)
			{
				rra(stack_a);
				operation_count++;
			}
		}
	}
	if (count_all(stack_b) == 1)
	{
		if (!ft_is_sorted_b(stack_b))
		{
			sb(stack_b);
			operation_count++;
		}
		while(*stack_b)
		{
			pa(stack_a, stack_b, 0);
			operation_count++;
		}
	}
	while (*stack_b)
	{
		if (stack_b[0] < stack_b[1])
		{
			sb(stack_b);
			operation_count++;
		}
		else if (*stack_b)
		{
			pa(stack_a, stack_b, 0);
			operation_count++;
		}
	}
	if (ft_is_sorted_a(stack_a))
	{
		free(stack_b);
		return (stack_a);
	}
	printf("\nstack_a\n");
	stack_printer(stack_a, stack_b);
	printf("\nend\n");
	////////
	i = 0;
	while (stack_a[i] != middle_one)
		i++;
	stack_final = (int *)malloc(sizeof(int) * i);
	stack_final[i] = '\0';
	while (stack_a[--i] >= 0)
		stack_final[i] = stack_a[i];

	free(stack_b);
	return (stack_final);
}

int	main(int argc, char **argv)
{
	int	i;
	int j;
	int	gate;
	int	*stack_a;
	int *receiver;
	int	*tester;

	// t_chunk	*chunks;
	i = -1;
	gate = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	tester = (int *)malloc(sizeof(int) * argc - 1);
	while (++i < argc - 1)
		stack_a[i] = ft_atoi(argv[argc - i - 1]);
	if (find_duplicates(stack_a))
		return (0);
	while(!ft_is_sorted_a(stack_a))
	{
		receiver = the_big_caller(stack_a, count_all(stack_a) + 1, gate);
		if (ft_is_sorted_a(receiver))
			break;
		j = -1;
		i = count_all(receiver);
		while (stack_a[++i])
			tester[++j] = stack_a[i];
		tester[j] = 0;
		if (!ft_is_sorted_a(tester))
			continue;
		i = -1;
		while (receiver[++i])
			stack_a[i] = receiver[i];
		while (i < argc - 1)
			stack_a[i++] = 0;
		free(receiver);
		gate++;
	}
	printf("\nstack_a\n");
	one_stack_printer(stack_a);
	printf("\nend\n");
	printf("operations: %d\n", operation_count);
	free(stack_a);
	free(tester);
	return (0);
}
