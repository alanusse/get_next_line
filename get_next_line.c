/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/11/06 13:33:19 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

/**
 * Find a '\\n' character and returns its memory address.
 * 
 * If '\\n' is not found, returns NULL.
*/
char	*newline_position(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (&str[i]);
	}
	return (NULL);
}

/**
 * Read a file descriptor until a '\\n' is found in buffer.
 * 
 * This function will return a string containing all readings until a '\\n'
 * character was encountered in new buffer.
*/
char	*read_until_newline(int fd)
{
	char	*buffer;
	char	*str;
	char	*tmp;

	buffer = read_fd(fd);
	str = NULL;
	while (buffer && !newline_position(buffer))
	{
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str, buffer);
			free(str);
			str = tmp;
		}
		free(buffer);
		buffer = read_fd(fd);
	}
	return (str);
}
// char	*read_until_newline(int fd)
// {
// 	char	buffer[BUFFER_SIZE];
// 	char	*str;
// 	char	*tmp;
// 	ssize_t	read_bytes;

// 	str = ft_strdup("");
// 	if (!str)
// 		return (NULL);
// 	read_bytes = read(fd, buffer, BUFFER_SIZE);
// 	while (read_bytes > 0)
// 	{
// 		tmp = ft_strjoin(str, buffer);
// 		free(str);
// 		if (!tmp)
// 			return (NULL);
// 		str = tmp;
// 		if (newline_position(buffer))
// 			break ;
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	return (str);
// }

char	*read_fd(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*str;
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (NULL);
	if (read_bytes < BUFFER_SIZE)
		buffer[read_bytes] = '\0';
	str = ft_strdup(buffer);
	if (!str)
		return (NULL);
	return (str);
}

// char	*get_next_line(int fd)
// {

// }

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	str = read_until_newline(fd);
	// printf("file.txt first line:\n\n");
	printf("%s\n", str);
	free(str);
	return (0);
}
