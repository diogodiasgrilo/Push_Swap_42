/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 05:45:14 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/25 13:20:34 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps_bonus.h"

int	count_all(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != MAX_SORT)
		i++;
	return (i - 1);
}

int	ft_is_sorted_a(int *stack_a)
{
	int	i;

	i = 0;
	while (*stack_a != MAX_SORT && stack_a[i + 1] != MAX_SORT)
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc((sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new_str)
		return (0);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	if (s1)
		free(s1);
	while (*s2)
	{
		new_str[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_fixer_mover(char *buffer, int gate, int i)
{
	int	k;

	k = 0;
	if (gate)
	{
		while (buffer[i])
		{
			buffer[k++] = buffer[i];
			buffer[i++] = 0;
		}
	}
}

int	ft_tidy(char *buffer)
{
	int	gate;
	int	i;

	i = 0;
	gate = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			gate = 1;
			buffer[i++] = 0;
			break ;
		}
		buffer[i++] = 0;
	}
	ft_fixer_mover(buffer, gate, i);
	return (gate);
}
