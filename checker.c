/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:41:40 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/21 12:28:27 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_action(char *line)
{
	if ((!strncmp(line, "sa", ft_strlen(line)) || \
	!strncmp(line, "sb", ft_strlen(line)) || \
	!strncmp(line, "ss", ft_strlen(line)) || \
	!strncmp(line, "pa", ft_strlen(line)) || \
	!strncmp(line, "pb", ft_strlen(line))) || \
	!strncmp(line, "ra", ft_strlen(line)) || \
	!strncmp(line, "rb", ft_strlen(line)) || \
	!strncmp(line, "rr", ft_strlen(line)) \
	|| !strncmp(line, "rra", ft_strlen(line)) \
	|| !strncmp(line, "rrb", ft_strlen(line)) \
	|| !strncmp(line, "rrr", ft_strlen(line)))
		return (1);
	return (0);
}

void	command(char *line, int *stack_a, int *stack_b)
{
	if (!strncmp(line, "sa", 2) && stack_a[0] && stack_a[1])
		sa(stack_a, 0);
	else if (!strncmp(line, "sb", 2) && stack_b[0] && stack_b[1])
		sb(stack_b, 0);
	else if (!strncmp(line, "ss", 2) && stack_a[0] && stack_b[0])
		ss(stack_a, stack_b, 0);
	else if (!strncmp(line, "pa", 2) && stack_b[0])
		pa(stack_a, stack_b, 0);
	else if (!strncmp(line, "pb", 2) && stack_a[0])
		pb(stack_a, stack_b, 0);
	else if (!strncmp(line, "ra", 2) && stack_a[0] && stack_a[1])
		ra(stack_a, 0);
	else if (!strncmp(line, "rb", 2) && stack_b[0] && stack_b[1])
		rb(stack_b, 0);
	else if (!strncmp(line, "rra", 3) && stack_a[0] && stack_a[1])
		rra(stack_a, 0);
	else if (!strncmp(line, "rrb", 3) && stack_b[0] && stack_b[1])
		rrb(stack_b, 0);
	else if (!strncmp(line, "rrr", 3) && stack_a[0] && stack_b[0] \
	&& stack_a[1] && stack_b[1])
		rrr(stack_a, stack_b, 0);
	else if (!strncmp(line, "rr", 2) && stack_a[0] && stack_b[0] \
	&& stack_a[1] && stack_b[1])
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

int	main(int argc, char **argv)
{
	int		i;
	int		*stack_a;
	int		*stack_b;

	if (argc == 1)
		return (0);
	i = 0;
	stack_a = (int *)malloc(sizeof(int) * argc + 1);
	stack_b = (int *)ft_calloc(argc - 1, 4);
	if (!stack_a || !stack_b)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i]);
	if (find_duplicates(stack_a) || find_non_letters(argv)
		|| ft_is_sorted_a(stack_a))
	{
		write(1, "Error\n", 6);
		return (free_and_return(stack_a, 0));
	}
	action_taker(stack_a, stack_b);
	if (!*stack_b && ft_is_sorted_a(stack_a) && !*stack_b)
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
	return (free_and_return(stack_a, 0));
}
