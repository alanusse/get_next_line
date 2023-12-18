/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/18 01:27:12 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

void	free_content(char **content)
{
	free(*content);
	*content = NULL;
}

void	read_until_newline(int fd, char **content)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;
	char		*result;

	result = NULL;
	while (!ft_strchr(*content, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			if (read_bytes < 0 && *content)
				free_content(content);
			return ;
		}
		buffer[read_bytes] = '\0';
		if (!*content)
		{
			result = ft_strdup(buffer);
			if (!result)
				return (free_content(content));
		}
		else
		{
			result = ft_strjoin(*content, buffer);
			if (!result)
			{
				free_content(content);
				return ;
			}
		}
		*content = result;
	}
}

char	*retrieve_line(char *content)
{
	char	*nl_pos;
	char	*line;

	nl_pos = ft_strchr(content, '\n');
	if (!nl_pos)
	{
		line = ft_strdup(content);
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_substr(content, 0, nl_pos - content + 1);
		if (!line)
			return (NULL);
	}
	return (line);
}

void	update_content(char **content)
{
	char	*nl_pos;
	char	*tmp;

	nl_pos = ft_strchr(*content, '\n');
	if (!nl_pos)
		free_content(content);
	else
	{
		if (ft_strlen(nl_pos + 1) == 0)
			free_content(content);
		else
		{
			tmp = ft_substr(*content, nl_pos - *content + 1, ft_strlen(*content));
			free(*content);
			*content = tmp;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*content;
	char				*line;

	// if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		// if (content)
		// 	free_content(&content);
		return (NULL);
	}
	read_until_newline(fd, &content);
	if (!content)
		return (NULL);
	line = retrieve_line(content);
	if (!line) // maybe free content
	{
		if (content)
			free_content(&content);
		return (NULL);
	}
	update_content(&content);
	return (line);
}

// int main()
// {
// 	int     file_descriptor;
// 	char    *str;

// 	file_descriptor = open("file.txt", O_RDONLY);
	
// 	str = get_next_line(file_descriptor);
// 	printf("line: %s", str);
// 	free(str);

// 	str = get_next_line(file_descriptor);
// 	printf("line: %s", str);
// 	free(str);
	
// 	str = get_next_line(file_descriptor);
// 	printf("line: %s", str);
// 	free(str);

// 	return (0);
// }