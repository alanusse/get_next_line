/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/11/07 20:32:56 by aglanuss         ###   ########.fr       */
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

char	*append_new_content(char *str, char *buffer, int read_bytes)
{
	char	*content;
	char	*tmp;

	content = (char *)malloc((read_bytes + 1) * sizeof(char));
	if (!content)
		return (NULL);
	ft_strlcpy(content, buffer, read_bytes);
	if (!str)
		str = ft_strdup(content);
	else
	{
		tmp = ft_strjoin(str, content);
		if (!tmp)
			return (NULL);
		free(str);
		str = tmp;
	}
	free(content);
	return (str);
}

/**
 * Read a file descriptor until a '\\n' is found in buffer.
 * 
 * This function will return a string containing all readings until a '\\n'
 * character was encountered in new buffer.
*/
char	*read_until_newline(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	read_bytes;
	char	*str;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	str = NULL;
	while (read_bytes > 0)
	{
		if (!append_new_content(str, buffer, read_bytes))
			return (NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (str);
}

/**
 * Read file once with BUFFER_SIZE as value and return a string of read result.
 * 
 * Return NULL if read function return 0 or an error occurred.
*/
char	*read_fd(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*str;
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (NULL);
	str = (char *)malloc((read_bytes + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, buffer, read_bytes);
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
	// str = read_fd(fd);
	printf("%s\n", str);
	free(str);
	return (0);
}
