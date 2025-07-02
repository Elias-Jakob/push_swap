/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:19:58 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 11:38:31 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	move_to_top(t_stack **stack, size_t size, size_t index, int is_a)
{
	size_t	reverse;
	int		move;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (1);
	reverse = index > size / 2;
	if (reverse)
		index = size - index;
	while (index-- > 0)
	{
		if (reverse && is_a)
			move = reverse_rotate(stack, "rra\n");
		else if (reverse)
			move = reverse_rotate(stack, "rrb\n");
		else if (is_a)
			move = rotate(stack, "ra\n");
		else
			move = rotate(stack, "rb\n");
		if (move == -1)
			return (-1);
	}
	return (1);
}

static ssize_t	do_n_rotations(t_stack **stack, size_t n, int is_a, int reverse)
{
	ssize_t	move;

	while (n > 0)
	{
		if (reverse && is_a)
			move = reverse_rotate(stack, "rra\n");
		else if (reverse)
			move = reverse_rotate(stack, "rrb\n");
		else if (is_a)
			move = rotate(stack, "ra\n");
		else
			move = rotate(stack, "rb\n");
		if (move == -1)
			return (-1);
		n--;
	}
	return (1);
}

static int	insert_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		reverse;
	ssize_t	n_rotations;
	ssize_t	rrb;
	ssize_t	moves;

	n_rotations = looking_forward(stack_b, *stack_a);
	rrb = looking_backward(stack_b, *stack_a);
	if (n_rotations == -1 || rrb == -1)
		return (-1);
	reverse = n_rotations < rrb;
	if (n_rotations > rrb)
		n_rotations = rrb;
	if (reverse)
		moves = do_n_rotations(stack_b, n_rotations, 0, 0);
	else
		moves = do_n_rotations(stack_b, n_rotations, 0, 1);
	if (moves == -1 || push(stack_a, stack_b, "pb\n") == -1)
		return (-1);
	return (1);
}

static int	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if (move_to_top(stack_b, stack_size(stack_b),
			get_minmax_idx(stack_b, 1), 0) == -1)
		return (-1);
	while (*stack_b)
	{
		if (push(stack_b, stack_a, "pa\n") == -1)
			return (-1);
	}
	return (0);
}

ssize_t	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	size_t	stack_a_size;
	ssize_t	most_efficient;

	if (is_sorted(stack_a))
		return (0);
	stack_a_size = stack_size(stack_a);
	if (stack_a_size <= 5)
		return (small_stack_sort(stack_a, stack_b, stack_a_size));
	if (push(stack_a, stack_b, "pb\n") == -1
		|| push(stack_a, stack_b, "pb\n") == -1)
		return (-1);
	if ((*stack_b)->num < (*stack_b)->next->num && swap(stack_b, "sb\n") == -1)
		return (-1);
	stack_a_size = stack_size(stack_a);
	while (stack_a_size > 0)
	{
		most_efficient = calc_cheapes_item(*stack_a, stack_b, stack_a_size);
		if (most_efficient == -1
			|| move_to_top(stack_a, stack_a_size, most_efficient, 1) == -1)
			return (-1);
		if (insert_to_b(stack_a, stack_b) == -1)
			return (-1);
		stack_a_size--;
	}
	return (push_back_to_a(stack_a, stack_b));
}
