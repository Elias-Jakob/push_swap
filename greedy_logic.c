/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:18:43 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 11:05:09 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

ssize_t	check_new_minmax(t_stack **stack_b, t_stack *item, int forward)
{
	ssize_t	count;
	int		max_b;
	int		min_b;
	ssize_t	stack_b_size;

	max_b = get_minmax(stack_b, 1);
	min_b = get_minmax(stack_b, 0);
	if (item->num < max_b && item->num > min_b)
		return (0);
	stack_b_size = stack_size(stack_b);
	if (item->num > max_b)
	{
		count = get_minmax_idx(stack_b, 1);
		if (forward || count == -1)
			return (count);
		return (stack_b_size - count);
	}
	count = get_minmax_idx(stack_b, 0);
	if (count == -1)
		return (-1);
	if (count == stack_b_size)
		return (0);
	if (forward)
		return (count + 1);
	return (stack_b_size - (count + 1));
}

ssize_t	looking_forward(t_stack **stack_b, t_stack *item)
{
	t_stack	*head_b;
	size_t	count;

	if (item->num > get_minmax(stack_b, 1)
		|| item->num < get_minmax(stack_b, 0))
		return (check_new_minmax(stack_b, item, 1));
	count = 0;
	head_b = *stack_b;
	while (head_b->next)
	{
		count++;
		if (item->num < head_b->num && item->num > head_b->next->num)
			return (count);
		head_b = head_b->next;
	}
	return (0);
}

ssize_t	looking_backward(t_stack **stack_b, t_stack *item)
{
	size_t	count;
	t_stack	*tail_b;

	if (item->num > get_minmax(stack_b, 1)
		|| item->num < get_minmax(stack_b, 0))
		return (check_new_minmax(stack_b, item, 0));
	count = 0;
	tail_b = *stack_b;
	while (tail_b->next)
		tail_b = tail_b->next;
	while (tail_b->prev)
	{
		count++;
		if (tail_b->num < item->num && tail_b->prev->num > item->num)
			return (count);
		tail_b = tail_b->prev;
	}
	return (0);
}

ssize_t	moves_per_item(t_stack *item, t_stack **stack_b,
											size_t stack_a_size, size_t index)
{
	ssize_t	moves;
	ssize_t	n_rrb;

	if (index > stack_a_size / 2)
		index = stack_a_size - index;
	moves = looking_forward(stack_b, item);
	n_rrb = looking_backward(stack_b, item);
	if (moves == -1 || n_rrb == -1)
		return (-1);
	if (moves > n_rrb)
		moves = n_rrb;
	return (index + moves);
}

ssize_t	calc_cheapes_item(t_stack *head_a, t_stack **stack_b,
													size_t stack_a_size)
{
	ssize_t	n_moves;
	ssize_t	best;
	size_t	index;
	ssize_t	best_index;

	index = 0;
	best_index = -1;
	best = -1;
	while (head_a)
	{
		n_moves = moves_per_item(head_a, stack_b, stack_a_size, index);
		if (n_moves == -1)
			return (-1);
		if (best == -1 || n_moves < best)
		{
			best = n_moves;
			best_index = index;
		}
		index++;
		head_a = head_a->next;
	}
	return (best_index);
}
