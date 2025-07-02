/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:03:23 by ejakob            #+#    #+#             */
/*   Updated: 2025/05/12 15:08:47 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_format(char *format, char c)
{
	while (*format)
	{
		if (*format == c)
			return (1);
		format++;
	}
	return (0);
}

static size_t	put_value(va_list *args, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(*args, int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	size_t	len;
	va_list	args;

	if (!string)
		return (-1);
	len = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%' && !is_format("cspdiuxX%", *(string + 1)))
		{
			va_end(args);
			return (-1);
		}
		else if (*string == '%')
			len += put_value(&args, *(++string));
		else
			len += write(1, string, 1);
		string++;
	}
	va_end(args);
	return (len);
}
