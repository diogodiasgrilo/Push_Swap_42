/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:13:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/23 19:13:33 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
int		ft_strlen(const char *s);
int		ft_is_sorted_a(int *stack_a);
void	*ft_calloc(int size, int type);
void	action_taker(int *stack_a, int *stack_b);
int		free_both_exit(int *stack_a, int *stack_b);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_bonus_atoi(const char *str, int *stack_a, int *stack_b);

#endif