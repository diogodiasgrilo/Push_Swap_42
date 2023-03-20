/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/20 12:21:59 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct chunk
{
	int	*stack_a;
	int	*stack_b;
	int	middle;
	int	size;
	struct chunk *next;
}				t_chunk;

void	sb(int *stack_b);
void	sa(int *stack_a);
void	ra(int *stack_a);
void	rra(int *stack_a);
int		count_all(int *stack);
int		count_half(int *stack);
int		ft_is_sorted_b(int *stack_b);
int		ft_is_sorted_a(int *stack_a);
void	one_stack_printer(int *stack_a);
int		insert_sort(int *stack_a, int argc);
int		*the_big_caller(int *stack_a, int argc, int gate);
void	int_array_copy(int *stack_a, int *sorted);
void	stack_printer(int *stack_a, int *stack_b);
void	pb(int *stack_a, int *stack_b, int *counter);
void		pa(int *stack_a, int *stack_b, int *counter);
int		push_swap(int *stack_a, int *stack_b, int middle, int size);

# endif
