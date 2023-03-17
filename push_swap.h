/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/16 20:47:11 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	sa(int *stack_a);
int		count_half(int *stack);
void	ra(int *stack_a);
void	rra(int *stack_a);
int		ft_is_sorted_a(int *stack_a);
int		ft_is_sorted_b(int *stack_b);
int		insert_sort(int *stack_a, int argc);
void	int_array_copy(int *stack_a, int *sorted);
void	stack_printer(int *stack_a, int *stack_b);
void		pb(int *stack_a, int *stack_b, int index, int *counter);
int		pa(int *stack_a, int *stack_b, int index, int *counter);
void	push_swap(int *stack_a, int *stack_b, int middle, int size);

# endif
