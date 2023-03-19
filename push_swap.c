/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/18 08:32:22 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b, int middle, int size)
{
	int half;
	int counter;

	counter = 0;
	half = count_half(stack_a);
	// printf("middle: %d\n", middle);
	while (counter < half)
	{
		if (stack_a[0] < middle)
			pb(stack_a, stack_b, 0, &counter);
		else
		{
			size = count_all(stack_a);
			// printf("size: %d\n", size);
			while (stack_a[size] < middle && counter < half)
			{
				rra(stack_a);
				pb(stack_a, stack_b, 0, &counter);
				size = count_all(stack_a);
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
	}
}

int	*the_big_caller(int *stack_a, int argc)
{
	int	i;
	int	middle_one;
	int	*stack_b;
	int	*stack_final;

	stack_b = (int *)malloc(sizeof(int) * argc);
	middle_one  = insert_sort(stack_a, argc);
	if(ft_is_sorted_a(stack_a))
	{
		free(stack_b);
		return (0);
	}
	i = -1;
	while (*(stack_a + 2) && !ft_is_sorted_a(stack_a))
		push_swap(stack_a, stack_b, insert_sort(stack_a, argc), count_all(stack_a));
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a);
	if (count_all(stack_b) == 1)
	{
		if (!ft_is_sorted_b(stack_b))
			sa(stack_b);
		while(*stack_b)
			pa(stack_a, stack_b, 0, 0);
	}
	while (*stack_b)
	{
		if (stack_b[0] < stack_b[1])
			sa(stack_b);
		pa(stack_a, stack_b, 0, 0);
		if (*stack_b)
			pa(stack_a, stack_b, 0, 0);
	}
	if (!ft_is_sorted_a(stack_a) && stack_a[0] > stack_a[1])
		sa(stack_a);
	if (ft_is_sorted_a(stack_a))
	{
		free(stack_b);
		return (stack_a);
	}
	////////
	i = 0;
	while (stack_a[i] != middle_one)
		i++;
	stack_final = (int *)malloc(sizeof(int) * i);
	while (--i >= 0)
		stack_final[i] = stack_a[i];
	i = 0;
	while(stack_b[i])
		stack_b[i++] = '\0';
	free(stack_b);
	return (stack_final);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	int	*receiver;

	// t_chunk	*chunks;
	i = -1;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	while (++i < argc - 1)
		stack_a[i] = ft_atoi(argv[argc - i - 1]);
	receiver = the_big_caller(stack_a, count_all(stack_a) + 1);
	i = -1;
	while (++i < count_all(receiver) + 1)
		stack_a[i] = receiver[i];
	while (i < argc - 1)
		stack_a[i++] = '\0';
	receiver = the_big_caller(stack_a, count_all(stack_a) + 1);
	return (0);
}
