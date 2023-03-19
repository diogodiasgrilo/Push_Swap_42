/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsi_base_ten.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:28:00 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/05 18:28:01 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsi_base_ten(unsigned int n, int fd, long int *counter)
{
	if (n >= 10)
		ft_print_unsi_base_ten(n / 10, fd, counter);
	ft_putchar_fd(n % 10 + '0', fd, counter);
}
