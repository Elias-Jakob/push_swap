/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:43:32 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 10:11:30 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

ssize_t	swap(t_stack **stack, char *instruction)
{
	t_stack	*new_head;

	if (!(*stack) || !(*stack)->next)
		return (-1);
	new_head = (*stack)->next;
	(*stack)->next = new_head->next;
	(*stack)->prev = new_head;
	if (new_head->next)
		new_head->next->prev = (*stack);
	new_head->next = (*stack);
	new_head->prev = NULL;
	*stack = new_head;
	return (write(1, instruction, ft_strlen(instruction)));
}

ssize_t	push(t_stack **stack_1, t_stack **stack_2, char *instruction)
{
	t_stack	*head_1;

	head_1 = *stack_1;
	if (!head_1)
		return (-1);
	if (head_1->next)
	{
		*stack_1 = head_1->next;
		(*stack_1)->prev = NULL;
	}
	else
		*stack_1 = NULL;
	if (!(*stack_2))
		head_1->next = NULL;
	else
	{
		(*stack_2)->prev = head_1;
		head_1->next = *stack_2;
	}
	*stack_2 = head_1;
	return (write(1, instruction, ft_strlen(instruction)));
}

ssize_t	rotate(t_stack **stack, char *instruction)
{
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return (-1);
	last = *stack;
	while (last->next)
		last = last->next;
	(*stack)->next->prev = NULL;
	(*stack)->prev = last;
	last->next = (*stack);
	*stack = (*stack)->next;
	last->next->next = NULL;
	return (write(1, instruction, ft_strlen(instruction)));
}

ssize_t	reverse_rotate(t_stack **stack, char *instruction)
{
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return (-1);
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	return (write(1, instruction, ft_strlen(instruction)));
}
