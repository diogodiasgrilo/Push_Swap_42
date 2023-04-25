/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:56:54 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 13:37:01 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

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
				if (argv[i][j] != 32 && argv[i][j] != '-')
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
	while (stack[++i] != MAX_SORT)
	{
		j = i;
		while (stack[++j] != MAX_SORT)
			if (stack[i] == stack[j])
				return (1);
	}
	return (0);
}

void	stack_printer(int *stack_a, int *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack_a[i] || stack_b[j])
	{
		if (stack_a[i] == 0 || stack_a[i])
			printf("%d\t", stack_a[i]);
		else
			printf("\t");
		if (stack_a[i] == 0 || stack_a[i])
			printf("%d", stack_b[j]);
		printf("\n");
		i++;
		j++;
	}
}
