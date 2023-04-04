/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/04 10:58:14 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b, int middle, int size)
{
	int half;
	int	checker;
	int counter;
	int	ra_counter;

	counter = 0;
	checker = 0;
	ra_counter = 0;
	half = count_half(stack_a);
	// printf("middle: %d\n", middle);
	while (counter < half)
	{
		if (stack_a[0] < middle)
			pb(stack_a, stack_b, &counter);
		else
		{
			size = count_all(stack_a);
			while (stack_a[size] < middle && counter < half && !ft_is_sorted_a(stack_a))
			{
				rra(stack_a);
				pb(stack_a, stack_b, &counter);
				size = count_all(stack_a);
			}
			while (!ft_is_sorted_a(stack_a))
			{
				if (stack_a[0] < middle)
					pb(stack_a, stack_b, &counter);
				else
				{
					ra(stack_a);
					counter++;
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
}

int	*the_big_caller(int *stack_a, int argc, int *borders)
{
	int	i;
	int	*stack_b;

	stack_b = (int *)malloc(sizeof(int) * argc);
	if (!stack_b)
		return (0);
	i = -1;
	while (count_all(stack_a) > 6)
	{
		push_swap(stack_a, stack_b, insert_sort(stack_a, (count_all(stack_a) + 1), 6), count_all(stack_a) / 3);
		borders[++i] = stack_b[0];
	}
	while (count_all(stack_a) > 1)
	{
		push_swap(stack_a, stack_b, insert_sort(stack_a, count_all(stack_a) + 1, 2), count_all(stack_a));
		borders[++i] = stack_b[0];
	}
	borders[i] = '\0';
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a);
	return (stack_b);
}

int		direction_teller(int *stack_b, int *borders, int index)
{
	int i;

	i = -1;
	if (!borders)
	{
		while (++i != count_all(stack_b) - index + 1)
			if (stack_b[i] == find_biggest_in_array(stack_b))
				return (1);
	}
	else
	{
		while (stack_b[++i] != borders[index])
		if (stack_b[i] == find_biggest_in_array(stack_b))
			return (1);
	}
	return (0);
}

void	final_chapter(int *stack_a, int *stack_b, int *borders)
{
	int	rb_counter;
	int	biggest_index;

	rb_counter = 0;
	// MAKE SMALLEST GO to BOTTOM OF A TO CUT STEPS
	while (stack_b[0] != borders[0] || rb_counter > 0)
	{
		if (stack_b[0] == find_biggest_in_array(stack_b))
			pa(stack_a, stack_b, 0);
		else if (direction_teller(stack_b, borders, 0))
		{
			while (stack_b[0] != find_biggest_in_array(stack_b))
			{
				rb(stack_b);
				rb_counter++;
			}
			pa(stack_a, stack_b, 0);
		}
		else if (rb_counter)
		{
			while (stack_b[0] != find_biggest_in_array(stack_b))
			{
				rrb(stack_b);
				rb_counter--;
			}
			pa(stack_a, stack_b, 0);
		}

	}
	// final_chapter = the_big_caller_for_b(stack_b, count_all(stack_b) + 1);
	while (*stack_b)
	{
		biggest_index = find_biggest_index(stack_b);
		if (biggest_index < count_all(stack_b) / 2)
		{
			while (stack_b[0] != find_biggest_in_array(stack_b))
			{
				if (stack_b[0] == find_smallest_in_array(stack_b))
				{
					pa(stack_a, stack_b, 0);
					ra(stack_a);
				}
				rb(stack_b);
			}
			pa(stack_a, stack_b, 0);
		}
		else
		{
			while (stack_b[0] != find_biggest_in_array(stack_b))
			{
				if (stack_b[0] == find_smallest_in_array(stack_b))
					{
						pa(stack_a, stack_b, 0);
						ra(stack_a);
					}
				rrb(stack_b);
			}
			pa(stack_a, stack_b, 0);
		}
	}
	while (stack_a[count_all(stack_a)] != find_biggest_in_array(stack_a))
		rra(stack_a);
}

int	main(int argc, char **argv)
{
	int	i;
	int	gate;
	int	*stack_a;
	int *stack_b;
	int	*borders;

	// t_chunk	*chunks;
	i = 0;
	gate = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	borders = (int *)malloc(sizeof(int) * argc - 1);
	// printf("region-stack_a: %p\n", stack_a);
	// printf("region-tester: %p\n", tester);
	if (!stack_a || !borders)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i]);
	if (find_duplicates(stack_a))
	{
		free(stack_a);
		free(borders);
		return (0);
	}
	if (count_all(stack_a) == 1)
		if (!ft_is_sorted_a(stack_a))
			sa(stack_a);
	stack_b = the_big_caller(stack_a, count_all(stack_a) + 1, borders);
	final_chapter(stack_a, stack_b, borders);
	// printf("one: %d, two:%d, three:%d\n", borders[0], borders[1], borders[2]);
	// one_stack_printer(stack_a);
	// printf("operations: %d\n", operation_count);
	free(stack_a);
	free(stack_b);
	return (0);
}
