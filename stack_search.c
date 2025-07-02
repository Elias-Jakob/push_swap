/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:18:26 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 11:31:21 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

ssize_t	get_minmax_idx(t_stack **stack, int max)
{
	t_stack	*last;
	size_t	idx;
	size_t	j;
	int		top;

	if (!(*stack))
		return (-1);
	if (!(*stack)->next)
		return (0);
	top = (*stack)->num;
	last = (*stack)->next;
	idx = 0;
	j = 1;
	while (last)
	{
		if ((max && last->num > top) || (!max && last->num < top))
		{
			top = last->num;
			idx = j;
		}
		last = last->next;
		j++;
	}
	return (idx);
}

int	get_minmax(t_stack **stack, int max)
{
	t_stack	*last;
	int		top;

	top = (*stack)->num;
	if (!(*stack)->next)
		return (top);
	last = (*stack)->next;
	while (last)
	{
		if ((max && last->num > top) || (!max && last->num < top))
			top = last->num;
		last = last->next;
	}
	return (top);
}

int	sort_3(t_stack **stack_a)
{
	int	s1;
	int	s2;
	int	s3;

	s1 = (*stack_a)->num;
	s2 = (*stack_a)->next->num;
	s3 = (*stack_a)->next->next->num;
	if (s1 > s2 && s2 < s3 && s1 < s3)
		return (swap(stack_a, "sa\n"));
	else if (s1 < s2 && s2 > s3 && s1 > s3)
		return (reverse_rotate(stack_a, "rra\n"));
	else if (s1 > s2 && s2 < s3 && s1 > s3)
		return (rotate(stack_a, "ra\n"));
	else if (s1 < s2 && s2 > s3 && s1 < s2)
	{
		if (reverse_rotate(stack_a, "rra\n") == -1
			|| swap(stack_a, "sa\n") == -1)
			return (-1);
	}
	else if (s1 > s2 && s2 > s3 && s1 > s3)
	{
		if (rotate(stack_a, "ra\n") == -1 || swap(stack_a, "sa\n") == -1)
			return (-1);
	}
	return (0);
}

int	small_stack_sort(t_stack **stack_a, t_stack **stack_b, size_t stack_a_size)
{
	if (stack_a_size == 2 && (*stack_a)->num > (*stack_a)->next->num)
		return (swap(stack_a, "sa\n"));
	if (stack_a_size == 3)
		return (sort_3(stack_a));
	while (stack_a_size - 3 > 0)
	{
		if (move_to_top(stack_a, stack_a_size,
				get_minmax_idx(stack_a, 0), 1) == -1)
			return (-1);
		if (push(stack_a, stack_b, "pb\n") == -1)
			return (-1);
		stack_a_size--;
	}
	if (sort_3(stack_a) == -1)
		return (-1);
	while (*stack_b)
	{
		if (push(stack_b, stack_a, "pa\n") == -1)
			return (-1);
	}
	return (0);
}
