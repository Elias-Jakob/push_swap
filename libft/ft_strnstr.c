/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:44:47 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/24 13:59:46 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*tmp_b;
	char	*tmp_l;
	size_t	i;
	size_t	j;

	tmp_b = (char *)big;
	tmp_l = (char *)little;
	i = 0;
	if (tmp_l[i] == '\0')
		return (tmp_b);
	while (i < len && tmp_b[i])
	{
		j = 0;
		while (tmp_b[i + j] == tmp_l[j] && tmp_l[j] && (i + j) < len)
			j++;
		if (tmp_l[j] == '\0')
			return (&tmp_b[i]);
		i++;
	}
	return (0);
}
