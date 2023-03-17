/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:09:41 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/16 20:47:05 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int *stack_a, int *stack_b, int index, int *counter)
{
	int j;

	j = 0;
	while (stack_b[j])
		j++;
	while (j > 0)
	{
		stack_b[j] = stack_b[j - 1];
		j--;
	}
	stack_b[0] = stack_a[index];
	stack_a[index] = 0;
	j = index + 1;
	while(stack_a[j])
	{
		stack_a[j - 1] = stack_a[j];
		j++;
	}
	stack_a[j - 1] = 0;
	if (counter)
		*counter += 1;
	ft_printf("pb\n");
}

int	pa(int *stack_a, int *stack_b, int index, int *counter)
{
	int j;

	j = 0;
	while (stack_a[j])
		j++;
	while (j > 0)
	{
		stack_a[j] = stack_a[j - 1];
		j--;
	}
	stack_a[0] = stack_b[index];
	stack_b[index] = 0;
	j = index + 1;
	while(stack_b[j])
	{
		stack_b[j - 1] = stack_b[j];
		j++;
	}
	stack_b[j - 1] = 0;
	if (counter)
		*counter += 1;
	ft_printf("pa\n");
	return j - 2;
}

void	sa(int *stack_a)
{
	int temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	ft_printf("sa\n");
}

void	ra(int *stack_a)
{
	int i;
	int temp;

	i = 0;
	temp = stack_a[0];
	while (stack_a[i])
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i - 1] = temp;
	ft_printf("ra\n");
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
	ft_printf("rra\n");
}
