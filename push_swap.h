/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/03 23:13:12 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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


int		*the_big_caller_for_b(int *stack_a, int argc);
void	push_swap_for_b(int *stack_a, int *stack_b, int middle, int size);
void	sb(int *stack_b);
void	sa(int *stack_a);
void	ra(int *stack_a);
void	rr(int *stack_a, int *stack_b);
void	rb(int *stack_b);
void	rrb(int *stack_b);
void	rra(int *stack_a);
void	rrr(int *stack_a, int *stack_b);
int		count_all(int *stack);
int		count_half(int *stack);
int		ft_atoi(const char *str);
int		find_duplicates(int *stack);
int		ft_is_sorted_a(int *stack_a);
int		ft_is_sorted_b(int *stack_b);
void	ss(int *stack_a, int * stack_b);
void	one_stack_printer(int *stack_a);
int		find_smallest_in_array(int *stack_a);
int		find_biggest_index(int *stack);
int 	find_biggest_in_array(int *stack_a);
int		insert_sort(int *stack_a, int argc, int divide);
int		ft_is_sorted_to_biggest(int *stack_a);
int 	find_biggest_in_array(int *stack_a);
void	int_array_copy(int *stack_a, int *sorted);
void	stack_printer(int *stack_a, int *stack_b);
void	pb(int *stack_a, int *stack_b, int *counter);
int 	check_for_bigger(int *stack_a, int *stack_b);
void	pa(int *stack_a, int *stack_b, int *counter);
int 	check_for_bigger(int *stack_a, int *stack_b);
int		*the_big_caller(int *stack_a, int argc, int *borders);
void	push_swap(int *stack_a, int *stack_b, int middle, int size);
int		find_smallest_in_chunk(int *stack_b, int *borders, int index, int max_index);
int		find_biggest_in_chunk(int *stack_b, int *borders, int index, int max_index);

# endif
