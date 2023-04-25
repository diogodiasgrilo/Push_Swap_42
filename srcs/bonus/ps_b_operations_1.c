/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:09:41 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 13:28:03 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

void	pb(int *stack_a, int *stack_b, int prnt)
{
	int	j;

	j = 0;
	while (stack_b[j] != MAX_SORT)
		j++;
	stack_b[j + 1] = MAX_SORT;
	while (j >= 0)
	{
		stack_b[j] = stack_b[j - 1];
		j--;
	}
	stack_b[0] = stack_a[0];
	stack_a[0] = 0;
	j = 0;
	while (stack_a[++j] != MAX_SORT)
		stack_a[j - 1] = stack_a[j];
	stack_a[j - 1] = MAX_SORT;
	if (prnt)
		write(1, "pb\n", 3);
}

void	pa(int *stack_a, int *stack_b, int prnt)
{
	int	j;

	j = 0;
	while (stack_a[j] != MAX_SORT)
		j++;
	stack_a[j + 1] = MAX_SORT;
	while (j > 0)
	{
		stack_a[j] = stack_a[j - 1];
		j--;
	}
	stack_a[0] = stack_b[0];
	stack_b[0] = MAX_SORT;
	j = 0;
	while (stack_b[++j] != MAX_SORT)
		stack_b[j - 1] = stack_b[j];
	stack_b[j - 1] = MAX_SORT;
	if (prnt)
		write(1, "pa\n", 3);
}

void	sb(int *stack_b, int prnt)
{
	int	temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	if (prnt)
		write(1, "sb\n", 3);
}

void	sa(int *stack_a, int prnt)
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	if (prnt)
		write(1, "sa\n", 3);
}

void	ss(int *stack_a, int *stack_b, int prnt)
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	if (prnt)
		write(1, "ss\n", 3);
}
