/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:14:46 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 15:13:19 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_free(int *stack)
{
	int	i;

	i = 0;
	while (stack && stack[i] != MAX_SORT)
		i++;
	if (stack[i])
		stack[i + 1] = '\0';
	if (stack)
	{
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
