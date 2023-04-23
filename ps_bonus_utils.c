/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:20:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/23 19:11:45 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

int	ft_bonus_atoi(const char *str, int *stack_a, int *stack_b)
{
	int	i;
	int	j;
	int	total;
	int	sign;

	total = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = (str[i] != '-') - (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = i;
		while (--j >= 0)
			if (str[i] == str[j])
				free_both_exit(stack_a, stack_b);
		total *= 10;
		total += str[i++] - 48;
	}
	if (str[i])
		free_both_exit(stack_a, stack_b);
	return (total * sign);
}

int	check_action(char *line)
{
	int		i;
	char	**comds;

	comds = (char *[]){"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", "rra",
		"rrb", "rrr"};
	i = -1;
	while (comds[++i])
		if (!fstrncmp(line, comds[i], ft_strlen(line)))
			return (1);
	return (0);
}

void	command(char *line, int *stack_a, int *stack_b)
{
	if (!fstrncmp(line, "sa", 2) && stack_a[0] && stack_a[1])
		sa(stack_a, 0);
	else if (!fstrncmp(line, "sb", 2) && stack_b[0] && stack_b[1])
		sb(stack_b, 0);
	else if (!fstrncmp(line, "ss", 2) && stack_a[0] && stack_b[0])
		ss(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "pa", 2) && stack_b[0])
		pa(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "pb", 2) && stack_a[0])
		pb(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "ra", 2) && stack_a[0] && stack_a[1])
		ra(stack_a, 0);
	else if (!fstrncmp(line, "rb", 2) && stack_b[0] && stack_b[1])
		rb(stack_b, 0);
	else if (!fstrncmp(line, "rra", 3) && stack_a[0] && stack_a[1])
		rra(stack_a, 0);
	else if (!fstrncmp(line, "rrb", 3) && stack_b[0] && stack_b[1])
		rrb(stack_b, 0);
	else if (!fstrncmp(line, "rrr", 3) && stack_a[0] && stack_b[0] && stack_a[1]
		&& stack_b[1])
		rrr(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "rr", 2) && stack_a[0] && stack_b[0] && stack_a[1]
		&& stack_b[1])
		rr(stack_a, stack_b, 0);
}

void	action_taker(int *stack_a, int *stack_b)
{
	char	input[1024];
	size_t	size;
	size_t	i;
	size_t	len;

	size = read(0, input, sizeof(input));
	i = 0;
	while (i < size - 1)
	{
		while (i < size)
		{
			if (input[i] == '\n' || input[i] == '\0')
			{
				len = i;
				input[len] = 0;
				break ;
			}
			if (++i == sizeof(input))
				break ;
		}
		if (check_action(input))
			command(input, stack_a, stack_b);
		else
			return ((void)write(1, "Error\n", 6));
	}
}
