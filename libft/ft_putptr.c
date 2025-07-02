/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:03:40 by ejakob            #+#    #+#             */
/*   Updated: 2025/05/12 15:11:38 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	write_ptr(unsigned long long n, char *base)
{
	if (n > 0)
	{
		write_ptr(n / 16, base);
		ft_putchar(base[n % 16]);
	}
}

size_t	ft_putptr(void *ptr)
{
	size_t				len;
	unsigned long long	n_ptr;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = 0;
	n_ptr = (unsigned long long)ptr;
	len += write(1, "0x", 2);
	write_ptr(n_ptr, "0123456789abcdef");
	while (n_ptr > 0)
	{
		n_ptr /= 16;
		len++;
	}
	return (len);
}
