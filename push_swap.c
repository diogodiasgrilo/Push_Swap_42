/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/04 17:23:17 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b, int middle, int size, int *sorted)
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
		{
			pb(stack_a, stack_b, &counter);
			if (stack_b[0] < sorted[count_all(sorted) / 12])
				rb(stack_b);
		}
		else
		{
			size = count_all(stack_a);
			while (stack_a[size] < middle && counter < half && !ft_is_sorted_a(stack_a))
			{
				rra(stack_a);
				pb(stack_a, stack_b, &counter);
				if (stack_b[0] < sorted[count_all(sorted) / 12])
					rb(stack_b);
				size = count_all(stack_a);
			}
			while (!ft_is_sorted_a(stack_a))
			{
				if (stack_a[0] < middle)
				{
					pb(stack_a, stack_b, &counter);
					if (stack_b[0] < sorted[count_all(sorted) / 12])
						rb(stack_b);
				}
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

void	the_big_caller(int *stack_a, int argc)
{
	int	all;
	int	*stack_b;
	int	times;
	int	*sorted;

	stack_b = (int *)malloc(sizeof(int) * argc);
	sorted = (int *)malloc(sizeof(int) * argc);
	if (!stack_b)
		return ;
	all = count_all(stack_a);
	times = 0;
	while (count_all(stack_a) > 6)
	{
		push_swap(stack_a, stack_b, insert_sort(stack_a, 6, sorted), count_all(stack_a), sorted);
		times++;
	}

	while (count_all(stack_a) > 1)
		push_swap(stack_a, stack_b, insert_sort(stack_a, 2, sorted), count_all(stack_a), sorted);
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a);
	final_chapter(stack_a, stack_b);
	// printf("times: %d\n", times);
	free(stack_b);
}

void	final_chapter(int *stack_a, int *stack_b)
{
	int	biggest_index;

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

	// t_chunk	*chunks;
	i = 0;
	gate = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i]);
	if (find_duplicates(stack_a))
	{
		free(stack_a);
		return (0);
	}
	if (count_all(stack_a) == 1)
		if (!ft_is_sorted_a(stack_a))
		{
			sa(stack_a);
			free(stack_a);
			return (0);
		}
	the_big_caller(stack_a, count_all(stack_a) + 1);
	free(stack_a);
	return (0);
}
