/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_counters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:32:02 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/17 13:32:07 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_half(int *stack)
{
	int i;

	i = 0;
	while (stack[i])
		i++;
	return (i / 2);
}

int		count_all(int *stack)
{
	int i;

	i = 0;
	while (stack[i])
		i++;
	return (i - 1);
}
