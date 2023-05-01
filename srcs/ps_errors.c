/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:36:43 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 15:28:20 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *str, int *stack_a)
{
	long int	i;
	long int	total;
	int			sign;

	total = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = (str[i] != '-') - (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += str[i++] - 48;
	}
	total *= sign;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((total > INT_MAX || total < INT_MIN || str[i]))
		free_and_exit(stack_a, 1);
	return (total);
}

int	find_non_letters(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) \
				&& argv[i][j] != '-' && argv[i][j] != '+' \
				&& argv[i][j] != ' ')
				return (1);
		}
	}
	return (0);
}

int	find_duplicates(char **argv)
{	
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_atoi(argv[i], 0) == ft_atoi(argv[j], 0))
				return (1);
		}
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
