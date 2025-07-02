/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:56:19 by ejakob            #+#    #+#             */
/*   Updated: 2025/04/24 11:16:21 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	int		i;
	int		last_occ;

	tmp_s = (char *)s;
	i = 0;
	last_occ = -1;
	while (tmp_s[i])
	{
		if (tmp_s[i] == (char)c)
			last_occ = i;
		i++;
	}
	if (last_occ != -1)
		return (&tmp_s[last_occ]);
	if ((char)c == 0)
		return (&tmp_s[i]);
	return (0);
}
