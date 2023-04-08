/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_final_chapter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:30:03 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/08 12:54:04 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cut_smaller(int *stack_a, int *stack_b, int *gate, int mod)
{
	pa(stack_a, stack_b, 0);
	ra(stack_a);
	*gate = mod;
}

void	cut_moves(int *stack_a, int *stack_b, int *gate, int second_big, int magic_number)
{
	if (magic_number > 1 && *gate == 0 && stack_b[0] == second_big)
	{
		pa(stack_a, stack_b, 0);
		*gate = 1;
	}
	// if (stack_b[0] == find_smallest_in_array(stack_b))
	// 	cut_smaller(stack_a, stack_b, gate, -1);
}

void	cutter(int *stack_a, int *stack_b, int *gate, int second_big, int magic_number)
{
	cut_moves(stack_a, stack_b, gate, second_big, magic_number);
	if (find_biggest_index(stack_b) < count_all(stack_b) / 2 && stack_b[0] != find_biggest_in_array(stack_b))
		rb(stack_b);
	else
		rrb(stack_b);
}

void	final_chapter(int *stack_a, int *stack_b, int magic_number)
{
	int	first_big;
	int	second_big;
	int	gate;

	while (*stack_b)
	{
		if (gate != -1)
			gate = 0;
		first_big = find_biggest_in_array(stack_b);
		second_big = find_second_biggest_in_array(stack_b, first_big);
		if (find_biggest_index(stack_b) < count_all(stack_b) / 2)
			while (stack_b[0] != first_big)
				cutter(stack_a, stack_b, &gate, second_big, magic_number);
		else
			while (stack_b[0] != first_big)
				cutter(stack_a, stack_b, &gate, second_big, magic_number);
		pa(stack_a, stack_b, 0);
		if (gate == 1 || stack_a[0] > stack_a[1])
			sa(stack_a);
	}
	while (stack_a[count_all(stack_a)] != find_biggest_in_array(stack_a))
		rra(stack_a);
}
