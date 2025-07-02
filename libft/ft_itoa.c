/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:12:20 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/28 17:12:24 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	fill_num(int n, char *mem)
{
	if (n > 9)
		fill_num(n / 10, mem - 1);
	else
	{
		*mem = n + '0';
		return ;
	}
	*mem = (n % 10) + '0';
}

static int	num_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*mem;

	if (n == -2147483648)
	{
		mem = (char *)malloc(13);
		ft_strlcpy(mem, "-2147483648", 12);
		return (mem);
	}
	len = num_len(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	mem = (char *)malloc(len + 1);
	if (!mem)
		return (0);
	if (sign == -1)
		mem[0] = '-';
	fill_num(n * sign, mem + (len - 1));
	mem[len] = '\0';
	return (mem);
}
