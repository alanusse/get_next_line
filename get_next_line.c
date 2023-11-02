/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:35:29 by aglanuss          #+#    #+#             */
/*   Updated: 2023/11/02 19:23:34 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	read_line(int fd, char *line, char *rest)
{
	char	*buffer[BUFFER_SIZE];
	char	*new_line_pos;
	int		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	new_line_pos = new_line_position(buffer);
	while (read_bytes > 0 && !new_line_pos)
	{
		if (!line)
		{
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		new_line_pos = new_line_position(buffer);
	}
}

// 1 - function to get pointer of \n encountered
// 2 - function to join buffers until \n char (passed pointer)
char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	read_line(fd, line, rest);
	return (line);
}

int	main()
{
	int	fd;
	char filename[] = "test_file.txt";

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("An error occurred while trying to open '%s' file!\n", filename);
		return (0);
	}
	printf("Read line of '%s' file is:\n\n", filename);
	printf("%s\n", get_next_line(fd));
	printf("\nEnd of content.\n");

	close(fd);
	return (1);
}