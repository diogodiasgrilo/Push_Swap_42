/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:13:10 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/23 19:11:51 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	free_both_exit(int *stack_a, int *stack_b)
{
	write(1, "Error\n", 6);
	free(stack_a);
	free(stack_b);
	exit(0);
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

void	*ft_calloc(int size, int type)
{
	unsigned long int	i;
	unsigned long int	l_size;
	unsigned long int	l_type;
	char				*memory;

	i = 0;
	l_type = type;
	l_size = size;
	memory = malloc(l_size * l_type);
	if (!memory)
		return (0);
	while (i < (l_size * l_type))
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
