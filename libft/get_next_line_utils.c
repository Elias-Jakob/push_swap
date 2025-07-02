/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:50:33 by ejakob            #+#    #+#             */
/*   Updated: 2025/06/06 11:52:00 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin_gnl(char **s1, char **s2, int free1, int free2)
{
	size_t	i;
	size_t	j;
	char	*mem;

	mem = (char *)malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	i = 0;
	while (mem && (*s1)[i++])
		mem[i - 1] = (*s1)[i - 1];
	j = 0;
	while (mem && (*s2)[j++])
		mem[j + i - 2] = (*s2)[j - 1];
	if (mem)
		mem[j + i - 2] = '\0';
	if (free1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (free2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (mem);
}

char	*ft_strdup_gnl(char *s, char **allocation)
{
	int		i;
	int		s_len;
	char	*mem;

	i = 0;
	s_len = ft_strlen(s);
	mem = (char *)malloc(s_len + 1);
	while (mem && i < s_len)
	{
		mem[i] = s[i];
		i++;
	}
	if (mem)
		mem[i] = '\0';
	if (allocation && *allocation)
	{
		free(*allocation);
		*allocation = NULL;
	}
	return (mem);
}

char	*ft_strchr_gnl(const char *s, int c)
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

char	*ft_substr_gnl(char const *s, unsigned int start, char *len)
{
	char	*mem;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	mem = (char *)malloc((s_len - start) + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (s + start + i < len && start + i < s_len)
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
