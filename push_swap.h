/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/06 20:32:20 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	pb(int *stack_a, int *stack_b, int *counter);
void	pa(int *stack_a, int *stack_b, int *counter);
void	sb(int *stack_b);
void	sa(int *stack_a);
void	ss(int *stack_a, int * stack_b);
void	ra(int *stack_a);
void	rr(int *stack_a, int *stack_b);
void	rb(int *stack_b);
void	rrb(int *stack_b);
void	rra(int *stack_a);
int		count_all(int *stack);
int		count_half(int *stack);
int		ft_atoi(const char *str);
int		find_duplicates(int *stack);
int		ft_is_sorted_b(int *stack_b);
int		ft_is_sorted_a(int *stack_a);
int		find_non_letters(char **argv);
int		find_biggest_index(int *stack);
int 	find_biggest_in_array(int *stack_a);
int		find_smallest_in_array(int *stack_a);
void	the_big_caller(int *stack_a, int argc);
void	int_array_copy(int *stack_a, int *sorted);
int		insert_sort(int *stack_a, int divide, int *sorted);
int		find_second_biggest_in_array(int *stack, int first_big);
void	final_chapter(int *stack_a, int *stack_b, int magic_number);
void	push_swap(int *stack_a, int *stack_b, int middle, int magic_x2, int *sorted);

// void	rrr(int *stack_a, int *stack_b);
// void	one_stack_printer(int *stack_a);
// void	stack_printer(int *stack_a, int *stack_b);

# endif
