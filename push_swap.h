/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:54:56 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 12:49:00 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// init_stack_a.c
int		init_stack_a(t_stack **stack_a, char **input_array, ssize_t arr_len);

// stack_operations.c
ssize_t	swap(t_stack **stack, char *instruction);
ssize_t	push(t_stack **stack_1, t_stack **stack_2, char *instruction);
ssize_t	rotate(t_stack **stack, char *instruction);
ssize_t	reverse_rotate(t_stack **stack, char *instruction);

// push_swap.c
ssize_t	push_swap(t_stack **stack_a, t_stack **stack_b);
int		move_to_top(t_stack **stack, size_t size, size_t index, int is_a);

// stack_search.c
ssize_t	get_minmax_idx(t_stack **stack, int max);
int		get_minmax(t_stack **stack, int max);
int		small_stack_sort(t_stack **stack_a, t_stack **stack_b,
			size_t stack_a_size);

// utils.c
size_t	stack_size(t_stack **stack);
void	stack_addback(t_stack **stack_head, t_stack *item);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack **stack);

// greedy_logic.c
ssize_t	check_new_minmax(t_stack **stack_b, t_stack *item, int forward);
ssize_t	looking_forward(t_stack **stack_b, t_stack *item);
ssize_t	looking_backward(t_stack **stack_b, t_stack *item);
ssize_t	moves_per_item(t_stack *item, t_stack **stack_b,
			size_t stack_a_size, size_t index);
ssize_t	calc_cheapes_item(t_stack *head_a, t_stack **stack_b,
			size_t stack_a_size);

#endif
