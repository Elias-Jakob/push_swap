/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:54:51 by ejakob            #+#    #+#             */
/*   Updated: 2025/07/01 14:01:28 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	free_input_array(char **input_array)
{
	size_t	i;

	if (!input_array)
		return ;
	i = 0;
	while (input_array[i])
	{
		free(input_array[i]);
		i++;
	}
	free(input_array);
}

static void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	char	**input_array;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		input_valid;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		input_array = ft_split(argv[1], ' ');
		input_valid = init_stack_a(&stack_a, input_array, -1);
		free_input_array(input_array);
	}
	else
		input_valid = init_stack_a(&stack_a, argv + 1, argc - 1);
	stack_b = NULL;
	if (!input_valid)
		ft_error_exit();
	if (push_swap(&stack_a, &stack_b) == -1)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		ft_error_exit();
	}
	free_stack(&stack_a);
}
