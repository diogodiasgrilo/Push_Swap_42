/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:28:33 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 18:28:34 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, long int *counter)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd, counter);
		return ;
	}
	while (*s)
		ft_putchar_fd(*s++, fd, counter);
}
