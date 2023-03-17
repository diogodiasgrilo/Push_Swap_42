/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:28:22 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 18:28:24 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, long int *counter)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd, counter);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd, counter);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd, counter);
	ft_putchar_fd(n % 10 + '0', fd, counter);
}
