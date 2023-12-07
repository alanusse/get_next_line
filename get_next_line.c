/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/07 01:34:08 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

/**
 * Get read data of file descriptor.
 * 
 * Return a string containing buffer or return NULL if read bytes is 0.
*/
char	*get_read_data(int fd)
{
	char 		buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	if (read_bytes <= 0)
		return (NULL);
	return (ft_strdup(buffer));
}

/**
 * Read file descriptor until a '\\n' character is found in the buffer
 * and assign to content variable all read buffers joined.
*/
void	read_until_newline(int fd, char **content)
{
	char	*read;

	while (!ft_strchr(*content, '\n'))
	{
		read = get_read_data(fd);
		if (!read)
			return ;
		if (!*content)
			*content = read;
		else
		{
			*content = ft_strjoin(*content, read);
			free(read);
		}
	}
}

char	*format_content(char **content)
{
	char	*str;
	char	*tmp;
	char	*ret;
	char	*n_pos;

	n_pos = ft_strchr(*content, '\n');
	if (!n_pos)
	{
		tmp = ft_strdup(*content);
		free(*content);
		return (tmp);
	}
	else
	{
		str = *content;
		ret = ft_substr(str, 0, ((n_pos - &str[0]) + 2));
		if (!ret)
			return (NULL);
		tmp = ft_strdup(&str[n_pos - &str[0] + 2]);
		if (!tmp)
			return (NULL);
		free(*content);
		*content = tmp;
		return (ret);
	}
}


char	*get_next_line(int fd)
{
	static char	*content;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, content, 0) < 0 ||
			(content && ft_strlen(content) == 0))
		return (NULL);
	read_until_newline(fd, &content);
	if (content)
		return (format_content(&content));
	else
		return (NULL);
}

int main()
{
	int     file_descriptor;
	char    *str;

	file_descriptor = open("file.txt", O_RDONLY);
	
	printf("%s", get_next_line(file_descriptor));
	printf("%s", get_next_line(file_descriptor));
	// printf("%s", get_next_line(file_descriptor));
	// printf("%s", get_next_line(file_descriptor));
	// printf("%s", get_next_line(file_descriptor));
	return (0);
}

// int main()
// {
// 	char *str = "hola mundo";

// 	printf("%li\n", &str[3] - &str[0]); // output: 3
// 	return (0);
// }