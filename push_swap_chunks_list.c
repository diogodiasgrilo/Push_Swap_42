/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunks_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogpere <diogpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:29:24 by diogpere          #+#    #+#             */
/*   Updated: 2023/03/17 13:30:39 by diogpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk new_chunk(int *stack_a, int argc)
{
	t_chunk chunk;

	chunk.middle = insert_sort(stack_a, argc);
	chunk.size = count_all(stack_a);
	chunk.next = 0;
	return (chunk);
}
