/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:51:05 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/24 12:09:54 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	tmp_c;
	size_t			i;

	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == tmp_c)
			return (&tmp_s[i]);
		i++;
	}
	return (0);
}
