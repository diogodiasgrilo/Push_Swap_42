/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:33:01 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 11:27:26 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(int *stack_a, int prnt)
{
	int	i;
	int	temp;

	i = -1;
	temp = stack_a[0];
	while (stack_a[++i] != MAX_SORT)
		stack_a[i] = stack_a[i + 1];
	stack_a[i - 1] = temp;
	stack_a[i] = MAX_SORT;
	if (prnt)
		write(1, "ra\n", 3);
}

void	rra(int *stack_a, int prnt)
{
	int	i;
	int	temp;

	i = 0;
	while (stack_a[i] != MAX_SORT)
		i++;
	temp = stack_a[i - 1];
	i--;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	if (prnt)
		write(1, "rra\n", 4);
}

void	rb(int *stack_b, int prnt)
{
	int	i;
	int	temp;

	i = -1;
	temp = stack_b[0];
	while (stack_b[++i] != MAX_SORT)
		stack_b[i] = stack_b[i + 1];
	stack_b[i - 1] = temp;
	stack_b[i] = MAX_SORT;
	if (prnt)
		write(1, "rb\n", 3);
}

void	rrb(int *stack_b, int prnt)
{
	int	i;
	int	temp;

	i = 0;
	while (stack_b[i] != MAX_SORT)
		i++;
	temp = stack_b[i - 1];
	i--;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = temp;
	if (prnt)
		write(1, "rrb\n", 4);
}
