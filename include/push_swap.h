/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:32:21 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 15:14:10 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define MAX_SORT 100000

void	pb(int *stack_a, int *stack_b, int prnt);
void	pa(int *stack_a, int *stack_b, int prnt);
void	sb(int *stack_b, int prnt);
void	sa(int *stack_a, int prnt);
void	ss(int *stack_a, int *stack_b, int prnt);
void	ra(int *stack_a, int prnt);
void	rr(int *stack_a, int *stack_b, int prnt);
void	rb(int *stack_b, int prnt);
void	rrb(int *stack_b, int prnt);
void	rra(int *stack_a, int prnt);
void	rrr(int *stack_a, int *stack_b, int prnt);

int		str_arg(char **arg);
int		count_all(int *stack);
void	stack_free(int *stack);
void	small_call(int *stack_a);
int		find_duplicates(char **argv);
int		find_non_letters(char **argv);
int		ft_is_sorted_a(int *stack_a);
int		find_biggest_index(int *stack);
int		count_strings(char *str, char c);
char	**ft_split(char const *s, char c);
int		is_done(int *stack_a, int *stack_b);
int		free_and_exit(int *stack, int gate);
int		find_biggest_in_array(int *stack_a);
int		ft_atoi(const char *str, int *stack_a);
void	the_big_caller(int *stack_a, int argc);
void	stack_printer(int *stack_a, int *stack_b);
int		checker_for_end(int *stack_a, int middle);
void	int_array_copy(int *stack_a, int *sorted);
void	final_chapter(int *stack_a, int *stack_b);
int		insert_sort(int *stack_a, int divide, int *sorted);
int		find_second_biggest_in_array(int *stack, int first_big);
void	push_swap(int *stack_a, int *stack_b, int magic_x2, int *sorted);
void	prep_middle(int *stack_a, int magic_x2, int *middle, int *sorted);
int		split_moves(int *stack_a, int *stack_b, int magic_x2, int *sorted);

// void	rrr(int *stack_a, int *stack_b);
// void	one_stack_printer(int *stack_a);
// void	stack_printer(int *stack_a, int *stack_b);

#endif
