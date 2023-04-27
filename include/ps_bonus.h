/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:13:30 by diogpere          #+#    #+#             */
/*   Updated: 2023/04/27 10:56:42 by diogpere         ###   ########.fr       */
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
int		ft_tidy(char *buffer);
int		count_all(int *stack);
void	stack_free(int *stack);
int		ft_strlen(const char *s);
int		ft_is_sorted_a(int *stack_a);
char	*ft_strjoin(char *s1, char *s2);
int		count_strings(char *str, char c);
char	**ft_split(char const *s, char c);
int		find_duplicates(char **argv, int start);
int		find_non_letters(char **argv, int start);
int		action_taker(int *stack_a, int *stack_b);
void	stack_printer(int *stack_a, int *stack_b);
void	ft_fixer_mover(char *buffer, int gate, int i);
int		fstrncmp(const char *s1, const char *s2, int n);
int		free_both_exit(int *stack_a, int *stack_b, int gate);
int		check_possible(int *stack_a, int *stack_b, int option);
int		ft_bonus_atoi(const char *str, int *stack_a, int *stack_b);

#endif