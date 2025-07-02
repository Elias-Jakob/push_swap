/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:04:24 by ejakob            #+#    #+#             */
/*   Updated: 2025/05/12 15:04:25 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	write_unbr(unsigned int n)
{
	unsigned char	c;

	if (n > 9)
		write_unbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

size_t	ft_putunbr(unsigned int n)
{
	size_t	len;

	write_unbr(n);
	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
