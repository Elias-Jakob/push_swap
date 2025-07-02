/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:07:37 by ejakob            #+#    #+#             */
/*   Updated: 2025/05/07 12:00:31 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*mem;

	total = nmemb * size;
	if (nmemb != 0 && size != 0)
	{
		if (total / nmemb != size)
			return (NULL);
	}
	else
		return (malloc(0));
	mem = malloc(total);
	if (!mem)
		return (NULL);
	if (total != 0)
		ft_bzero(mem, total);
	return (mem);
}
