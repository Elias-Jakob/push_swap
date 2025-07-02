/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:20:26 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/24 11:17:05 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp_s;
	int		i;

	tmp_s = (char *)s;
	i = 0;
	while (tmp_s[i])
	{
		if (s[i] == (char)c)
			return (&tmp_s[i]);
		i++;
	}
	if ((char)c == 0)
		return (&tmp_s[i]);
	return (NULL);
}
