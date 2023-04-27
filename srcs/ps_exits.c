/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:14:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 10:38:23 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	free_and_exit(int *stack, int gate)
{
	if (stack)
		stack_free(stack);
	if (gate)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}
