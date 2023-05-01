/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 10:55:01 by diogpere         ###   ########.fr       */
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
	while (stack_a[count_all(stack_a)] < middle && !checker_for_end(stack_a, \
			middle) && !is_done(stack_a, stack_b))
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
	sorted[0] = MAX_SORT;
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

void	first_call(int argc, char **argv, int start, int sub)
{
	int		*stack_a;

	if (find_duplicates(argv) || find_non_letters(argv))
		free_and_exit(0, 1);
	if ((argc == 2 && ft_atoi(argv[1], 0)) || (argc == 3 && \
		ft_atoi(argv[1], 0) < ft_atoi(argv[2], 0)))
		exit (0);
	stack_a = (int *)malloc(sizeof(int) * (argc - start));
	if (!stack_a)
		exit (0);
	while (++start < argc)
		stack_a[start - sub] = ft_atoi(argv[start], stack_a);
	stack_a[start - sub] = MAX_SORT;
	if (argc == 4 && sub == 1)
		small_call(stack_a);
	if (!ft_is_sorted_a(stack_a))
		the_big_caller(stack_a, count_all(stack_a) + 1);
	stack_free(stack_a);
}

int	main(int argc, char **argv)
{
	char	**split;

	split = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && count_strings(argv[1], ' ') > 1)
	{
		split = ft_split(argv[1], ' ');
		first_call(str_arg(split), split, -1, 0);
	}
	else
		first_call(argc, argv, 0, 1);
	return (0);
}
