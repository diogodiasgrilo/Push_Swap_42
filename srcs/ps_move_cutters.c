/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_cutters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 07:16:00 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/26 18:54:22 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	prep_middle(int *stack_a, int magic_x2, int *middle, int *sorted)
{
	if (magic_x2 / 2 > 1 && count_all(stack_a) > magic_x2 / 2)
		*middle = insert_sort(stack_a, magic_x2 / 2, sorted);
	else
		*middle = insert_sort(stack_a, 2, sorted);
}

int	split_moves(int *stack_a, int *stack_b, int magic_x2, int *sorted)
{
	pb(stack_a, stack_b, 1);
	if (stack_b[0] < sorted[count_all(sorted) / magic_x2] && (magic_x2 > 2
			|| count_all(stack_b) > 99))
		rb(stack_b, 1);
	return (1);
}

int	checker_for_end(int *stack_a, int middle)
{
	int	checker;

	checker = 0;
	while (stack_a[checker] >= middle && stack_a[checker] != MAX_SORT)
		checker++;
	if (stack_a[checker] == MAX_SORT)
		return (1);
	return (0);
}
