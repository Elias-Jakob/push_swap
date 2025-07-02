/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:12:36 by ejakob            #+#    #+#             */
/*   Updated: 2025/05/07 12:36:06 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	i;

	if (ft_strlen(s) == 0)
		return (0);
	count = 0;
	i = 0;
	if (s[i] != c)
		count++;
	while (s[i++])
	{
		if (s[i] != c && s[i - 1] == c && s[i])
			count++;
	}
	return (count);
}

static int	free_all(char **mem, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(mem[i]);
		i++;
	}
	free(mem);
	return (-1);
}

static int	fill_word(int curr_word, char *s, char **mem, char c)
{
	size_t	word_len;
	size_t	skip;

	word_len = 0;
	skip = 0;
	while (curr_word == 0 && s[skip] == c)
		skip++;
	while (s[skip + word_len] != c && s[skip + word_len])
		word_len++;
	word_len++;
	mem[curr_word] = (char *)malloc(sizeof(char) * word_len);
	if (!mem[curr_word])
		return (free_all(mem, curr_word));
	ft_strlcpy(mem[curr_word], s + skip, word_len);
	while (skip + word_len < ft_strlen(s) && *(s + skip + word_len) == c)
		word_len++;
	return (skip + word_len);
}

char	**ft_split(char const *s, char c)
{
	char	*tmp_s;
	int		word_count;
	int		curr_len;
	char	**mem;
	int		i;

	tmp_s = (char *)s;
	word_count = count_words(tmp_s, c);
	mem = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!mem)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		curr_len = fill_word(i, tmp_s, mem, c);
		if (curr_len == -1)
			return (NULL);
		tmp_s += curr_len;
		i++;
	}
	mem[i] = NULL;
	return (mem);
}
