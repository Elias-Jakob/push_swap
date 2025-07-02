/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:43:26 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 14:32:33 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = *stack;
	while (last)
	{
		tmp = last->next;
		free(last);
		last = tmp;
	}
}

void	stack_addback(t_stack **stack_head, t_stack *item)
{
	t_stack	*last;

	if (!(*stack_head))
	{
		*stack_head = item;
		return ;
	}
	last = *stack_head;
	while (last->next)
		last = last->next;
	last->next = item;
	item->prev = last;
}

size_t	stack_size(t_stack **stack)
{
	size_t	size;
	t_stack	*last;

	size = 0;
	last = *stack;
	while (last)
	{
		last = last->next;
		size++;
	}
	return (size);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*last;
	int		max;

	if (!(*stack)->next)
		return (1);
	max = (*stack)->num;
	last = (*stack)->next;
	while (last)
	{
		if (max > last->num)
			return (0);
		max = last->num;
		last = last->next;
	}
	return (1);
}
