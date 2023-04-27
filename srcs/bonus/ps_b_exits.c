/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_exits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:17:26 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 10:54:28 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

void	stack_free(int *stack)
{
	int	i;

	i = -1;
	while (stack && stack[++i] != MAX_SORT)
		stack[i] = 1;
	if (stack)
	{
		stack[i] = '\0';
		if (stack[0])
			free(stack);
	}	
}

int	free_both_exit(int *stack_a, int *stack_b, int gate)
{
	if (stack_a)
		stack_free(stack_a);
	if (stack_b)
		stack_free(stack_b);
	if (gate)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}
