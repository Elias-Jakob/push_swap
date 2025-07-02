/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:44:29 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/25 13:29:08 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tmp_s;
	int		s_len;
	char	*mem;

	i = 0;
	tmp_s = (char *)s;
	s_len = ft_strlen(tmp_s);
	mem = (char *)malloc(s_len + 1);
	if (!mem)
		return (NULL);
	while (i < s_len)
	{
		mem[i] = tmp_s[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
