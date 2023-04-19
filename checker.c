/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:41:40 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/19 18:29:19 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_and_return(int *stack, int gate)
{
	if (gate)
		sa(stack);
	free(stack);
	return (0);
}

int check_action(char *line)
{
	if ((!strncmp(line, "sa", 2) || !strncmp(line, "sb", 2) \
	|| !strncmp(line, "ss", 2) || !strncmp(line, "pa", 2) || !strncmp(line, "pb", 2)) \
	|| !strncmp(line, "ra", 2) || !strncmp(line, "rb", 2) || !strncmp(line, "rr", 2) \
	|| !strncmp(line, "rra", 3) || !strncmp(line, "rrb", 3) || !strncmp(line, "rrr", 3))
		return (1);
	return (0);
}

void command(char *line, int *stack_a, int *stack_b)
{
	if (!strncmp(line, "sa", 2))
		sa(stack_a);
	else if (!strncmp(line, "sb", 2))
		sb(stack_b);
	else if (!strncmp(line, "ss", 2))
		ss(stack_a, stack_b);
	else if (!strncmp(line, "pa", 2))
		pa(stack_a, stack_b, 0);
	else if (!strncmp(line, "pb", 2))
		pb(stack_a, stack_b, 0);
	else if (!strncmp(line, "ra", 2))
		ra(stack_a);
	else if (!strncmp(line, "rb", 2))
		rb(stack_b);
	else if (!strncmp(line, "rr", 2))
		rr(stack_a, stack_b);
	else if (!strncmp(line, "rra", 3))
		rra(stack_a);
	else if (!strncmp(line, "rrb", 3))
		rrb(stack_b);
	else if (!strncmp(line, "rrr", 3))
		rrr(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*line;
	int	*stack_a;
	int	*stack_b;

	i = 0;
	stack_a = (int *)malloc(sizeof(int) * argc - 1);
	stack_b = (int *)ft_calloc(argc - 1, 4);
	if (!stack_a || !stack_b)
		return (0);
	while (++i < argc)
		stack_a[i - 1] = ft_atoi(argv[i]);
	if (find_duplicates(stack_a) || find_non_letters(argv)
		|| ft_is_sorted_a(stack_a))
		return (free_and_return(stack_a, 0));
	while (line = get_next_line(0))
	{
		if (check_action(line))
			command(line, stack_a, stack_b);
		else
			(break);
	}
	if(!*stacl_b && ft_is_sorted_a(stack_a) && !*stack_b)
				return (write(1, "OK\n", 3));
	return (free_and_return(stack_a, 0));
}