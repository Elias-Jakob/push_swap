/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:43:35 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 14:00:45 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fits_int(char *str)
{
	unsigned long long	res;
	int					i;

	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res * 10) + str[i] - '0' > 2147483647)
			return (0);
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (1);
}

static int	input_checker(char **input_array, ssize_t arr_len)
{
	ssize_t	idx;
	size_t	str_i;
	size_t	dup_idx;

	idx = 0;
	while ((idx < arr_len) || (input_array[idx] && arr_len == -1))
	{
		str_i = 0;
		if (input_array[idx][str_i] == '-' || input_array[idx][str_i] == '+')
			str_i++;
		while (input_array[idx][str_i] >= '0' && input_array[idx][str_i] <= '9')
			str_i++;
		if (str_i != ft_strlen(input_array[idx]) || !fits_int(input_array[idx]))
			return (0);
		dup_idx = idx + 1;
		while (input_array[dup_idx])
		{
			if (ft_atoi(input_array[idx]) == ft_atoi(input_array[dup_idx]))
				return (0);
			dup_idx++;
		}
		idx++;
	}
	return (1);
}

static t_stack	*stack_new(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	init_stack_a(t_stack **stack_a, char **input_array, ssize_t arr_len)
{
	ssize_t	i;
	t_stack	*new_element;

	*stack_a = NULL;
	if (!input_array || !input_array[0] || !input_checker(input_array, arr_len))
		return (0);
	i = 0;
	while ((i < arr_len) || (input_array[i] && arr_len == -1))
	{
		new_element = stack_new(ft_atoi(input_array[i]));
		if (!new_element)
		{
			free_stack(stack_a);
			return (0);
		}
		stack_addback(stack_a, new_element);
		i++;
	}
	return (1);
}
