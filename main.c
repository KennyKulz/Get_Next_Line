/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:43:14 by kchikwam          #+#    #+#             */
/*   Updated: 2024/08/20 21:27:39 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void	test_get_next_line(const char *filename)
{
	int		fd;
	char	*line;
	int		line_number;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return ;
	}
	line = get_next_line(fd);
	line_number = 1;
	printf("Starting to read lines from %s\n", filename);
	while (line != NULL)
	{
		printf("Line %d: %s\n", line_number++, line);
		free(line);
	}
	printf("Finished reading lines from %s\n", filename);
	close(fd);
}

int	main(void)
{
	const char	*filename;

	filename = "test.txt";
	test_get_next_line(filename);
	return (0);
}

