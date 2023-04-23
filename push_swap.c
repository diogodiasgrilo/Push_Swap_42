/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:40:23 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/23 11:59:07 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b, int magic_x2, int *sorted)
{
	int	half;
	int	middle;
	int	counter;

	prep_middle(stack_a, magic_x2, &middle, sorted);
	counter = 0;
	half = count_half(stack_a);
	while (counter < half && stack_a[0] < middle)
		counter += split_moves(stack_a, stack_b, magic_x2, sorted);
	while (stack_a[count_all(stack_a)] < middle && counter < half)
	{
		rra(stack_a, 1);
		counter += split_moves(stack_a, stack_b, magic_x2, sorted);
	}
	while (!checker_for_end(stack_a, middle))
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
	magic_number = (count / 100) + 1;
	magic_x2 = magic_number * 2;
	while (magic_number > 1 && count_all(stack_a) > magic_number)
		push_swap(stack_a, stack_b, magic_x2, sorted);
	while (count_all(stack_a) > 1)
		push_swap(stack_a, stack_b, magic_x2, sorted);
	if (!ft_is_sorted_a(stack_a))
		sa(stack_a, 1);
	final_chapter(stack_a, stack_b);
	free(sorted);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*stack_a;

	if (argc == 1)
		return (0);
	i = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i]);
	if (find_duplicates(stack_a) || find_non_letters(argv)
		|| ft_is_sorted_a(stack_a))
		return (free_and_return(stack_a, 0));
	if (count_all(stack_a) == 1)
		if (!ft_is_sorted_a(stack_a))
			return (free_and_return(stack_a, 1));
	the_big_caller(stack_a, count_all(stack_a) + 1);
	return (free_and_return(stack_a, 0));
}
