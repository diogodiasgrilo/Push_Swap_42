/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:09:41 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/21 11:47:09 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int *stack_a, int *stack_b, int *counter)
{
	int j;

	j = 0;
	while (stack_b[j])
		j++;
	stack_b[j + 1] = 0;
	while (j >= 0)
	{
		stack_b[j] = stack_b[j - 1];
		j--;
	}
	stack_b[0] = stack_a[0];
	stack_a[0] = 0;
	j = 0;
	while(stack_a[++j])
		stack_a[j - 1] = stack_a[j];
	stack_a[j - 1] = 0;
	if (counter)
		*counter += 1;
	write(1, "pb\n", 3);
}

void	pa(int *stack_a, int *stack_b, int *counter)
{
	int j;

	j = 0;
	while (stack_a[j])
		j++;
	stack_a[j + 1] = 0;
	while (j > 0)
	{
		stack_a[j] = stack_a[j - 1];
		j--;
	}
	stack_a[0] = stack_b[0];
	stack_b[0] = 0;
	j = 0;
	while(stack_b[++j])
		stack_b[j - 1] = stack_b[j];
	stack_b[j - 1] = 0;
	if (counter)
		*counter += 1;
	write(1, "pa\n", 3);
}

void	sb(int *stack_b)
{
	int temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	write(1, "sb\n", 3);
}

void	sa(int *stack_a)
{
	int temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	write(1, "sa\n", 3);
}

void	ra(int *stack_a)
{
	int i;
	int temp;

	i = -1;
	temp = stack_a[0];
	while (stack_a[++i])
		stack_a[i] = stack_a[i + 1];
	stack_a[i - 1] = temp;
	write(1, "ra\n", 3);
}

void	rra(int *stack_a)
{
	int	i;
	int	temp;

	i = 0;
	while (stack_a[i])
		i++;
	temp = stack_a[i - 1];
	i--;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	write(1, "rra\n", 4);
}
