/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:35:29 by aglanuss          #+#    #+#             */
/*   Updated: 2023/10/28 18:57:56 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char *current_line;

	if (!current_line)
	{
		current_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!current_line)
			return (NULL);
	}
	read(fd, current_line, BUFFER_SIZE);
	return (current_line);
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
	printf("Content of '%s' file is:\n\n", filename);
	printf("%s\n", get_next_line(fd));
	printf("\nEnd of content.\n");

	close(fd);
	return (1);
}