/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:35:38 by kchikwam          #+#    #+#             */
/*   Updated: 2024/08/20 19:55:24 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_line_ending(char *str, size_t i)
{
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*get_string(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	i = find_line_ending(str, i);
	new_str = (char *)malloc((ft_strlen(str) - i + 1));
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	if (new_str[0] == '\0')
	{
		free(str);
		free(new_str);
		return (NULL);
	}
	free(str);
	return (new_str);
}

char	*read_the_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	i = find_line_ending(str, i);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*free_and_null(char *buff1, char *buff2)
{
	free(buff1);
	free(buff2);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*read_content;
	int			read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!(ft_strchr(read_buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_content, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			read_buffer = free_and_null(read_content, read_buffer);
			return (NULL);
		}
		read_content[read_bytes] = '\0';
		read_buffer = ft_strjoin(read_buffer, read_content);
	}
	free(read_content);
	read_content = read_the_line(read_buffer);
	read_buffer = get_string(read_buffer);
	return (read_content);
}
// This is the final version of get_next_line.c. It is a function that reads a file line by line. It returns the line that has just been read. If there is nothing else to read, it returns NULL. The function has a static variable that holds the remaining content from the previous read. The function reads the file in chunks of BUFFER_SIZE bytes. The function ft_strjoin is used to concatenate the content of the buffer with the content of the read. The function find_line_ending is used to find the index of the line ending character. The function get_string is used to get the remaining content after the line ending character. The function read_the_line is used to read the line from the buffer. The function free_and_null is used to free the memory and return NULL. The function get_next_line is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in a loop until there is nothing else to read. The function is called with the file descriptor as an argument. The function returns the line that has just been read. The function is called in
