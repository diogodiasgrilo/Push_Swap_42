/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_erros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:17:13 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 15:35:11 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

int	ft_bonus_atoi(const char *str, int *stack_a, int *stack_b)
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
	if (total > INT_MAX || total < INT_MIN || str[i])
		free_both_exit(stack_a, stack_b, 1);
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
				&& argv[i][j] != '-' && argv[i][j] != '+')
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
			if (ft_bonus_atoi(argv[i], 0, 0) == ft_bonus_atoi(argv[j], 0, 0))
				return (1);
		}
	}
	return (0);
}

int	check_possible(int *stack_a, int *stack_b, int option)
{
	if (option == 0 && stack_a[0] != MAX_SORT && stack_a[1] != MAX_SORT)
		return (1);
	else if (option == 1 && stack_b[0] != MAX_SORT && stack_b[1] != MAX_SORT)
		return (1);
	else if (option == 2 && stack_a[0] != MAX_SORT && stack_b[0] != MAX_SORT)
		return (1);
	else if (option == 3 && stack_b[0] != MAX_SORT)
		return (1);
	else if (option == 4 && stack_a[0] != MAX_SORT)
		return (1);
	else if (option == 5 && stack_a[0] != MAX_SORT && stack_a[1] != MAX_SORT)
		return (1);
	return (0);
}
