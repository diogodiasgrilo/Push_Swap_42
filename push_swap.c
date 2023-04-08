/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/08 13:15:23 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b, int middle, int magic_x2, int *sorted)
{
	int half;
	int	checker;
	int counter;

	counter = 0;
	checker = 0;
	half = count_half(stack_a);
	while (counter < half)
	{
		if (stack_a[0] < middle)
		{
			pb(stack_a, stack_b, &counter);
			if (stack_b[0] < sorted[count_all(sorted) / magic_x2] && (magic_x2 > 2 || count_all(stack_b) > 99))
				rb(stack_b);
		}
		else
		{
			while (stack_a[count_all(stack_a)] < middle && counter < half && !ft_is_sorted_a(stack_a))
			{
				rra(stack_a);
				pb(stack_a, stack_b, &counter);
				if (stack_b[0] < sorted[count_all(sorted) / magic_x2] && (magic_x2 > 2 || count_all(stack_b) > 99))
					rb(stack_b);
			}
			while (!ft_is_sorted_a(stack_a))
			{
				if (stack_a[0] < middle)
				{
					pb(stack_a, stack_b, &counter);
					if (stack_b[0] < sorted[count_all(sorted) / magic_x2] && (magic_x2 > 2 || count_all(stack_b) > 99))
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

// if (stack_b[0] < sorted[count_all(sorted) / magic_x2] && (magic_x2 > 2 || count_all(stack_b) > 99))

void	the_big_caller(int *stack_a, int count)
{
	int	magic_number;
	int	magic_x2;
	int	*sorted;
	int	*stack_b;

	stack_b = (int *)malloc(sizeof(int) * count);
	sorted = (int *)malloc(sizeof(int) * count);
	if (!stack_b || !sorted)
		return ;
	magic_number = (count / 100) + 1;
	magic_x2 = magic_number * 2;
	while (magic_number > 1 && count_all(stack_a) > magic_number)
		push_swap(stack_a, stack_b, insert_sort(stack_a, magic_number, sorted), magic_x2, sorted);
	while (count_all(stack_a) > 1)
		push_swap(stack_a, stack_b, insert_sort(stack_a, 2, sorted), magic_x2, sorted);
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a);
	final_chapter(stack_a, stack_b, magic_number);
	free(sorted);
	free(stack_b);
}

int	free_and_return(int *stack, int gate)
{
	if (gate)
		sa(stack);
	free(stack);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;

	i = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i]);
	if (find_duplicates(stack_a) || find_non_letters(argv))
		return free_and_return(stack_a, 0);
	if (count_all(stack_a) == 1)
		if (!ft_is_sorted_a(stack_a))
			return free_and_return(stack_a, 1);
	the_big_caller(stack_a, count_all(stack_a) + 1);
	return free_and_return(stack_a, 0);
}
