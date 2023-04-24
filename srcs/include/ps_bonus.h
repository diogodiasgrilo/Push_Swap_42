/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:13:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/24 15:36:58 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

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

int		ft_tidy(char *buffer);
int		count_all(int *stack);
int		ft_strlen(const char *s);
int		find_duplicates(int *stack);
int		ft_is_sorted_a(int *stack_a);
int		find_non_letters(char **argv);
void	*ft_calloc(int size, int type);
char	*ft_strjoin(char *s1, char *s2);
int		action_taker(int *stack_a, int *stack_b);
void	ft_fixer_mover(char *buffer, int gate, int i);
int		fstrncmp(const char *s1, const char *s2, int n);
int		free_both_exit(int *stack_a, int *stack_b, int gate);
int		ft_bonus_atoi(const char *str, int *stack_a, int *stack_b);

#endif