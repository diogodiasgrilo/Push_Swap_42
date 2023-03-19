/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:27:44 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 18:27:46 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_printer(unsigned int n, int fd, int gate,
		long int *counter)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (gate == 0)
	{
		write(1, "0x", 2);
		*counter += 2;
	}
	if (n >= 16)
		ft_hex_printer(n / 16, fd, ++gate, counter);
	ft_putchar_fd(hex[n % 16], fd, counter);
}
