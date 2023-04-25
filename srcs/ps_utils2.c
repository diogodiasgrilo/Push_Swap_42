/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:02:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 13:02:51 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_free(int *stack)
{
	int	i;

	i = -1;
	while (stack[++i] != MAX_SORT)
		stack[i] = 0;
	stack[i] = '\0';
}

int	is_done(int *stack_a, int *stack_b)
{
	if (ft_is_sorted_a(stack_a) && *stack_b == MAX_SORT)
		return (1);
	return (0);
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
	while (stack_a[i] != MAX_SORT || stack_b[j] != MAX_SORT)
	{
		if (stack_a[i] != MAX_SORT)
			printf("%d", stack_a[i++]);
		printf("\t");
		if (stack_b[j] != MAX_SORT)
			printf("%d", stack_b[j++]);
		printf("\n");
	}
	printf("\n");
}
