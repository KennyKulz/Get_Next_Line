/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:35:38 by kchikwam          #+#    #+#             */
/*   Updated: 2024/07/21 09:38:05 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

static char	*get_line(char **saved)
{
	char	*line;
	char	*new_saved;
	char	*newline_pos;

	if (!*saved)
		return (NULL);
	newline_pos = ft_strchr(*saved, '\n');
	if (newline_pos)
	{
		line = ft_strdup(*saved, newline_pos - *saved + 1);
		new_saved = ft_strdup(newline_pos + 1);
		free(*saved);
		*saved = new_saved;
		if (**saved == '\0')
		{
			free(*saved);
			*saved = NULL;
		}
	}
	else
	{
		line = ft_strdup(*saved);
		free(*saved);
		*saved = NULL;
	}
	return (line);
}

static int	read_to_saved(int fd, char **saved)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (bytes_read);
	buf[bytes_read] = '\0';
	if (!*saved)
		*saved = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(*saved, buf);
		free(*saved);
		*saved = temp;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(saved, '\n'))
		bytes_read = read_to_saved(fd, &saved);
	if (bytes_read < 0)
	{
		if (saved)
			free(saved);
		saved = NULL;
		return (NULL);
	}
	line = get_line(&saved);
	return (line);
}
