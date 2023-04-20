/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:57:09 by ddias             #+#    #+#             */
/*   Updated: 2023/04/20 16:41:28 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	if (str == NULL || *str == '\0')
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
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
