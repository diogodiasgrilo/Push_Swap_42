/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_counters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:32:02 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/09 02:45:12 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_half(int *stack)
{
	int	i;

	i = 0;
	while (stack && stack[i])
		i++;
	return (i / 2);
}

int	count_all(int *stack)
{
	int	i;

	i = 0;
	while (stack && stack[i])
		i++;
	return (i - 1);
}

int	find_non_letters(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				if (argv[i][j] != 32)
					return (1);
		}
	}
	return (0);
}

int	find_duplicates(int *stack)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (stack && stack[++i])
	{
		j = i;
		while (stack[++j])
			if (stack[i] == stack[j])
				return (1);
	}
	return (0);
}
