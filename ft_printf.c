/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:28:04 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/15 11:48:40 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_helper(char *str, va_list ap, int i, long int *counter)
{
	if (str[i] == 'c')
		ft_putchar_fd(va_arg(ap, int), 1, counter);
	else if (str[i] == 's')
		ft_putstr_fd(va_arg(ap, char *), 1, counter);
	else if (str[i] == 'p')
		ft_pointer_printer(va_arg(ap, unsigned long long int), 1, 0, counter);
	else if (str[i] == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1, counter);
	else if (str[i] == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1, counter);
	else if (str[i] == 'u')
		ft_print_unsi_base_ten(va_arg(ap, unsigned int), 1, counter);
	else if (str[i] == 'x')
		ft_hex_printer(va_arg(ap, unsigned int), 1, 1, counter);
	else if (str[i] == 'X')
		ft_print_num_hex_upper(va_arg(ap, unsigned int), 1, counter);
	else if (str[i] == '%')
		ft_putchar_fd('%', 1, counter);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	long int	i;
	long int	counter;

	i = 0;
	counter = 0;
	va_start(ap, str);
	if (!*str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_print_helper((char *)str, ap, ++i, &counter);
		else
			ft_putchar_fd(str[i], 1, &counter);
		i++;
	}
	va_end(ap);
	return (counter);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Hello world";
// 	ft_printf("ft_printf: %x \n", -9);
// 	printf("\n");
// 	printf("printf: %x \n", -9);
// 	printf("\n");
// }
