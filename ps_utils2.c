/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:02:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/23 19:08:55 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
