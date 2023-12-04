/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/04 17:08:16 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

int	contains_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

/**
 * Read a file descriptor and return a string containing
 * all the reads until a '\\n' or '\\0' character are found.
 * 
 * If read function returns 0 bytes, return a NULL pointer.
*/
char	*read_until_newline(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*result;
	char		*tmp;
	ssize_t	read_bytes;

	result = NULL;

	while (!contains_newline(result))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes <= 0)
			return (result);
		if (!result)
		{
			result = ft_strdup(buffer);
			if (!result)
				return (NULL);
		}
		else
		{
			tmp = ft_strjoin(result, buffer);
			free(result);
			if (!tmp)
				return (NULL);
			result = tmp;
		}
	}
	return (result);
}

/**
 * Assign read content to a variable, trim it until a '\\n' character and assign the trimmed
 * value (including '\\n' character) to another variable.
*/
char	*format_content(char **content)
{
	char		*new_content;
	char		*tmp;
	char		*str;
	size_t	i;

	if (!contains_newline(*content))
	{
		tmp = ft_strdup(*content);
		free(*content);
		return (tmp);
	}
	else
	{
		str = *content;
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
			{
				tmp = ft_strndup(str, i);
				if (!tmp)
					return (NULL);
				new_content = ft_strdup(&str[i + 1]);
				if (!new_content)
					return (NULL);
				free(*content);
				*content = new_content;
				return (tmp);
			}
			i++;
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char				*last_read;
	char				*tmp;

	if (!content)
	{
		content = read_until_newline(fd);
		if (!content)
			return (NULL);
	}
	if (!contains_newline(content))
	{
		last_read = read_until_newline(fd);
		if (!last_read)
		{
			if (content)
				return (format_content(&content));
			return (NULL);
		}
		tmp = ft_strjoin(content, last_read);
		free(last_read);
		if (!tmp)
			return (NULL);
		free(content);
		content = tmp;
	}
	return (format_content(&content));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("file.txt", O_RDONLY);
// 	printf("call: %s\n", get_next_line(fd));
// 	printf("call: %s\n", get_next_line(fd));

// 	// printf("%i\n", !contains_newline(str));
// 	return (0);
// }
