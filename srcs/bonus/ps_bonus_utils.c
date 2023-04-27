/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:13:10 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 10:50:32 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	str_arg(char **arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
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
