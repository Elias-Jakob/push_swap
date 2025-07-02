/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejakob <ejakob@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:50:19 by ejakob            #+#    #+#             */
/*   Updated: 2025/06/06 11:52:37 by ejakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*free_ret_null(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

static char	*fill_buffer(int fd, char **tmp)
{
	char	*buffer;
	ssize_t	n_read;

	buffer = NULL;
	while (1)
	{
		n_read = read(fd, *tmp, BUFFER_SIZE);
		if (n_read < 0)
			return (free_ret_null(&buffer));
		(*tmp)[n_read] = '\0';
		if (!buffer)
			buffer = ft_strdup_gnl(*tmp, &buffer);
		else
			buffer = ft_strjoin_gnl(&buffer, tmp, 1, 0);
		if (!buffer || ft_strchr_gnl(*tmp, '\n') != NULL || n_read == 0)
			break ;
	}
	return (buffer);
}

static char	*find_lb(int fd, char **remains)
{
	char	*buffer;
	char	*tmp;

	if (*remains != NULL && ft_strchr_gnl(*remains, '\n') != NULL)
		return (ft_strdup_gnl(*remains, remains));
	tmp = (char *)malloc(((size_t)BUFFER_SIZE) + 1);
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	buffer = fill_buffer(fd, &tmp);
	free(tmp);
	return (buffer);
}

static char	*extract_line(char **buffer, char **remains)
{
	char	*line;
	char	*lb_pos;

	lb_pos = ft_strchr_gnl(*buffer, '\n');
	if (lb_pos == NULL)
	{
		if (!(*remains))
			return (ft_strdup_gnl(*buffer, buffer));
		return (ft_strjoin_gnl(remains, buffer, 1, 1));
	}
	line = ft_substr_gnl(*buffer, 0, lb_pos + 1);
	if (*remains && line)
		line = ft_strjoin_gnl(remains, &line, 1, 1);
	if (*(lb_pos + 1) != '\0' && line)
		*remains = ft_strdup_gnl(lb_pos + 1, NULL);
	if (!line || (*(lb_pos + 1) != '\0' && line && !(*remains)))
	{
		free(line);
		free(*buffer);
		return (NULL);
	}
	free(*buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remains = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (free_ret_null(&remains));
	buffer = find_lb(fd, &remains);
	if (!buffer)
		return (free_ret_null(&remains));
	if (!ft_strlen(buffer))
	{
		free(buffer);
		if (remains)
			return (ft_strdup_gnl(remains, &remains));
		return (NULL);
	}
	line = extract_line(&buffer, &remains);
	if (!line)
		return (free_ret_null(&remains));
	return (line);
}
