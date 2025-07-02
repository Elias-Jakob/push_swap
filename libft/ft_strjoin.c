/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:08:05 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/25 16:15:17 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*t_s1;
	char	*t_s2;
	char	*mem;

	i = 0;
	t_s1 = (char *)s1;
	t_s2 = (char *)s2;
	mem = (char *)malloc(ft_strlen(t_s1) + ft_strlen(t_s2) + 1);
	if (!mem)
		return (0);
	while (t_s1[i])
	{
		mem[i] = t_s1[i];
		i++;
	}
	j = 0;
	while (t_s2[j])
	{
		mem[j + i] = t_s2[j];
		j++;
	}
	mem[j + i] = '\0';
	return (mem);
}
