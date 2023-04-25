/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 14:20:51 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(int *stack_a, int *stack_b, int magic_x2, int *sorted)
{
	int	middle;

	prep_middle(stack_a, magic_x2, &middle, sorted);
	while (!checker_for_end(stack_a, middle) && stack_a[0] < middle && \
			!is_done(stack_a, stack_b))
		split_moves(stack_a, stack_b, magic_x2, sorted);
	while (stack_a[count_all(stack_a)] < middle && count_all(stack_a) > 10 && \
			!checker_for_end(stack_a, middle) && !is_done(stack_a, stack_b))
	{
		rra(stack_a, 1);
		if (is_done(stack_a, stack_b))
			break ;
		split_moves(stack_a, stack_b, magic_x2, sorted);
	}
	while (!checker_for_end(stack_a, middle) && !is_done(stack_a, stack_b))
	{
		if (stack_a[0] < middle)
			split_moves(stack_a, stack_b, magic_x2, sorted);
		else
			ra(stack_a, 1);
	}
}

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
	stack_b[0] = MAX_SORT;
	magic_number = (count / 100) + 1;
	magic_x2 = magic_number * 2;
	while (!is_done(stack_a, stack_b) && magic_number > 1 && \
			count_all(stack_a) > magic_number)
		push_swap(stack_a, stack_b, magic_x2, sorted);
	while (!is_done(stack_a, stack_b) && count_all(stack_a) > 1)
		push_swap(stack_a, stack_b, magic_x2, sorted);
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a, 1);
	final_chapter(stack_a, stack_b);
	stack_free(sorted);
	stack_free(stack_b);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;

	i = 0;
	if (argc < 2)
		return (0);
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i], stack_a);
	stack_a[i - 1] = MAX_SORT;
	if (count_all(stack_a) == 1)
		free_and_exit(stack_a, 0);
	if (count_all(stack_a) == 2)
		small_call(stack_a);
	if (find_duplicates(stack_a) || find_non_letters(argv))
	{
		write(1, "Error\n", 6);
		free_and_exit(stack_a, 1);
	}
	if (!ft_is_sorted_a(stack_a))
		the_big_caller(stack_a, count_all(stack_a) + 1);
	stack_free(stack_a);
	return (0);
}
