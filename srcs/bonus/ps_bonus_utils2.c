/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:13:10 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 13:35:13 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

void	stack_free(int *stack)
{
	int	i;

	i = -1;
	while (stack[++i] != MAX_SORT)
		stack[i] = 0;
	stack[i] = '\0';
}

int	free_both_exit(int *stack_a, int *stack_b, int gate)
{
	write(1, "Error\n", 6);
	stack_free(stack_a);
	stack_free(stack_b);
	if (gate)
		exit(1);
	exit(0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	fstrncmp(const char *s1, const char *s2, int n)
{
	unsigned char	c1;
	unsigned char	c2;
	int				i;

	i = 0;
	if (n == 0 || (!*s1 && !*s2))
		return (0);
	if (n < 0)
		return (-1);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
		i++;
	c1 = s1[i];
	c2 = s2[i];
	return (c1 - c2);
}
