/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:35:38 by kchikwam          #+#    #+#             */
/*   Updated: 2024/07/22 21:20:52 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_str_len(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_str_dup_len(const char *src, size_t len);
char	*ft_strchr(const char *s, int c);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*extract_line(char **saved, char *newline_pos)
{
	char	*line;
	char	*new_saved;

	if ((*saved == 0) || (saved == 0))
		return (NULL);
	line = ft_str_dup_len(*saved, newline_pos - *saved + 1);
	new_saved = ft_str_dup_len(newline_pos + 1, ft_str_len(newline_pos + 1));
	free(*saved);
	*saved = new_saved;
	if (*saved && **saved == '\0')
	{
		free(*saved);
		*saved = (NULL);
	}
	return (line);
}

static char	*get_line(char **saved)
{
	char	*newline_pos;
	char	*line;

	if (!*saved || !saved)
		return (NULL);
	newline_pos = ft_strchr(*saved, '\n');
	if (newline_pos)
		return (extract_line(saved, newline_pos));
	else
	{
		line = ft_str_dup_len(*saved, ft_str_len(*saved));
		free(*saved);
		*saved = NULL;
		return (line);
	}
}

static int	read_to_saved(int fd, char **saved)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;

	if (!saved)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	printf("Read %d bytes\n", bytes_read); // Debug statement
	if (bytes_read <= 0)
		return (bytes_read);
	buffer[bytes_read] = '\0';
	if (*saved)
	{
		temp = ft_strjoin(*saved, buffer);
		free(*saved);
		*saved = temp;
	}
	else
		*saved = ft_str_dup_len(buffer, ft_str_len(buffer));
	printf("Saved buffer: %s\n", *saved); // Debug statement
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	saved = NULL;
	while (bytes_read > 0 && !ft_strchr(saved, '\n'))
	{
		bytes_read = read_to_saved(fd, &saved);
		if (bytes_read == -1)
		{
			free(saved);
			saved = NULL;
		}
		return (NULL);
	}
	line = get_line(&saved);
	printf("Extracted line: %s\n", line); // Debug statement
	return (line);
}

