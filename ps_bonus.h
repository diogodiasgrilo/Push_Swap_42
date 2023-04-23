/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:21:38 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/23 17:29:47 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP__BONUS_H
# define PUSH_SWAP__BONUS_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

int		count_all(int *stack);
int		ft_is_sorted_a(int *stack_a);
int		find_biggest_index(int *stack);
int		find_biggest_in_array(int *stack_a);
int		find_smallest_in_array(int *stack_a);
void	the_big_caller(int *stack_a, int argc);
int		checker_for_end(int *stack_a, int middle);
void	int_array_copy(int *stack_a, int *sorted);
void	final_chapter(int *stack_a, int *stack_b);
int     free_both_exit(int *stack_a, int *stack_b);
int		insert_sort(int *stack_a, int divide, int *sorted);
int		find_second_biggest_in_array(int *stack, int first_big);
int		ft_bonus_atoi(const char *str, int *stack_a, int *stack_b);
void	push_swap(int *stack_a, int *stack_b, int magic_x2, int *sorted);
void	prep_middle(int *stack_a, int magic_x2, int *middle, int *sorted);
int		split_moves(int *stack_a, int *stack_b, int magic_x2, int *sorted);

#endif