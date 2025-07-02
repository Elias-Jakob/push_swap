/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:22:58 by ejakob            #+#    #+#             */
/*   Updated: 2025/05/07 12:25:52 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	in_set(const char *set, const char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*mem;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (in_set(set, *s1) && *s1)
		s1++;
	len = ft_strlen(s1);
	while (in_set(set, *(s1 + len - 1)) && len > 0)
		len--;
	mem = (char *)malloc(len + 1);
	if (!mem)
		return (0);
	i = 0;
	while (i < len)
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
