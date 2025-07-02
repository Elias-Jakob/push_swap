/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:03:47 by ejakob            #+#    #+#             */
/*   Updated: 2025/05/12 15:03:48 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	write_hex(unsigned int n, char *base)
{
	if (n > 0)
	{
		write_hex(n / 16, base);
		ft_putchar(base[n % 16]);
	}
}

size_t	ft_puthex(unsigned int n, char *base)
{
	size_t	len;

	len = 0;
	write_hex(n, base);
	if (n == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
