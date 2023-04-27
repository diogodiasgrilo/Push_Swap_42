/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:20:49 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 09:42:22 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

int	check_action(char *line)
{
	int		i;
	char	**comds;

	comds = (char *[]){"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr", "rra",
		"rrb", "rrr", 0};
	i = -1;
	while (comds[++i])
		if (!fstrncmp(line, comds[i], ft_strlen(comds[i])) && \
			!fstrncmp(line, comds[i], ft_strlen(line)))
			return (1);
	return (0);
}

void	command(char *line, int *stack_a, int *stack_b)
{
	if (!fstrncmp(line, "sa", 2) && check_possible(stack_a, stack_b, 0))
		sa(stack_a, 0);
	else if (!fstrncmp(line, "sb", 2) && check_possible(stack_a, stack_b, 1))
		sb(stack_b, 0);
	else if (!fstrncmp(line, "ss", 2) && check_possible(stack_a, stack_b, 2))
		ss(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "pa", 2) && check_possible(stack_a, stack_b, 3))
		pa(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "pb", 2) && check_possible(stack_a, stack_b, 4))
		pb(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "ra", 2) && check_possible(stack_a, stack_b, 0))
		ra(stack_a, 0);
	else if (!fstrncmp(line, "rb", 2) && check_possible(stack_a, stack_b, 1))
		rb(stack_b, 0);
	else if (!fstrncmp(line, "rra", 3) && check_possible(stack_a, stack_b, 0))
		rra(stack_a, 0);
	else if (!fstrncmp(line, "rrb", 3) && check_possible(stack_a, stack_b, 1))
		rrb(stack_b, 0);
	else if (!fstrncmp(line, "rrr", 3) && check_possible(stack_a, stack_b, 2))
		rrr(stack_a, stack_b, 0);
	else if (!fstrncmp(line, "rr", 2) && check_possible(stack_a, stack_b, 2))
		rr(stack_a, stack_b, 0);
	free(line);
}

int	action_taker(int *stack_a, int *stack_b)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = 0;
	if (read(0, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		i = 0;
		while (buffer[i])
			buffer[i++] = '\0';
		return (0);
	}
	if (*buffer || read(0, buffer, BUFFER_SIZE) > 0)
		line = ft_strjoin(line, buffer);
	(ft_tidy(buffer));
	if (line && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	if (line && check_action(line))
		command(line, stack_a, stack_b);
	else if (line)
		free_both_exit(stack_a, stack_b, 1);
	if (!line)
		return (0);
	return (1);
}
