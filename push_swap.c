/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/20 17:07:18 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int *stack_a, int *stack_b, int middle, int size)
{
	int half;
	int counter;
	int	ra_counter;

	counter = 0;
	ra_counter = 0;
	half = count_half(stack_a);
	// printf("middle: %d\n", middle);
	while (counter < half)
	{
		if (stack_a[0] < middle && stack_a[1] < middle && stack_a[0] > stack_a[1])
			sa(stack_a);
		if (stack_a[0] < middle)
			pb(stack_a, stack_b, &counter);
		else
		{
			size = count_all(stack_a);
			// printf("size: %d\n", size);
			while (stack_a[size] < middle && counter < half)
			{
				rra(stack_a);
				if (stack_a[0] < middle && stack_a[1] < middle && stack_a[0] > stack_a[1])
					sa(stack_a);
				pb(stack_a, stack_b, &counter);
				if (*(stack_b + 1) && stack_b[0] < stack_b[1])
					sb(stack_b);
				size = count_all(stack_a);
			}
			while (counter < half && count_all(stack_a) >= 3)
			{
				if (stack_a[0] < middle && stack_a[1] < middle && stack_a[0] > stack_a[1])
					sa(stack_a);
				if (stack_a[0] < middle)
					pb(stack_a, stack_b, &counter);
				else
				{
					ra(stack_a);
					ra_counter++;
				}
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
	if(ft_is_sorted_a(stack_a))
	{
		free(stack_b);
		return (stack_a);
	}
	while (!ft_is_sorted_a(stack_a))
	{
		i = push_swap(stack_a, stack_b, insert_sort(stack_a, argc), count_all(stack_a));
		if (gate > 0)
		{
			while (--i >= 0)
				rra(stack_a);
		}
	}
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a);
	if (count_all(stack_b) == 1)
	{
		if (!ft_is_sorted_b(stack_b))
			sb(stack_b);
		while(*stack_b)
			pa(stack_a, stack_b, 0);
	}
	while (*stack_b)
	{
		if (stack_b[0] < stack_b[1])
			sb(stack_b);
		else if (*stack_b)
			pa(stack_a, stack_b, 0);
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
	int	gate;
	int	*stack_a;
	int *receiver;

	// t_chunk	*chunks;
	i = -1;
	gate = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	while (++i < argc - 1)
		stack_a[i] = ft_atoi(argv[argc - i - 1]);
	while(!ft_is_sorted_a(stack_a))
	{
		receiver = the_big_caller(stack_a, count_all(stack_a) + 1, gate);
		if (ft_is_sorted_a(receiver))
			break;
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
	return (0);
}
