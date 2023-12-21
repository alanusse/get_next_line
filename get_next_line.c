/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/21 13:40:44 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	set_content(int fd, char **content)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t	bytes_read;

	if (ft_strchr(*content, '\n'))
		return ;
	buffer[BUFFER_SIZE] = '\0';
	while (!ft_strchr(*content, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			return (free_ptr(content));
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			return ;
		tmp = ft_strjoin(*content, buffer);
		if (!tmp)
			return (free_ptr(content));
		*content = tmp;
	}
}

char	*extract_line(char *content)
{
	char	*nl_pos;
	char	*line;

	nl_pos = ft_strchr(content, '\n');
	if (!nl_pos)
	{
		line = ft_strdup(content);
		if (!line)
			return (NULL); // todo: maybe free *content
		return (line);
	}
	line = ft_substr(content, 0, nl_pos - content + 1);
	if (!line)
		return (NULL); // todo: maybe free content
	return (line);
}

void	refresh_content(char **content)
{
	char	*nl_pos;
	char	*tmp;

	nl_pos = ft_strchr(*content, '\n');
	if (!nl_pos || ft_strlen(nl_pos + 1) == 0)
		return (free_ptr(content));
	tmp = ft_strdup(nl_pos + 1);
	if (!tmp)
		return free_ptr(content); // todo: maybe free content
	free_ptr(content);
	*content = tmp;
}

char	*get_next_line(int fd)
{
	static char	*content;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free_ptr(&content);
		return (NULL);
	}
	line = NULL;
	set_content(fd, &content);
	if (!content)
		return (NULL);
	line = extract_line(content);
	if (!line)
	{
		free_ptr(&content);
		return (NULL);
	}
	refresh_content(&content);
	return (line);
}

// int main()
// {
// 	char *str = "hola\nque tal";
// 	char *npos = ft_strchr(str, '\n');

// 	printf("%s", ft_substr(str, npos - str, ft_strlen(str)));
// 	return 0;
// }


// int main()
// {
// 	int     file_descriptor;
// 	char    *str;

// 	file_descriptor = open("file.txt", O_RDONLY);
	
// 	str = get_next_line(file_descriptor);
// 	printf("%s", str);
// 	free(str);

// 	str = get_next_line(file_descriptor);
// 	printf("%s", str);
// 	free(str);
	
// 	str = get_next_line(file_descriptor);
// 	printf("%s", str);
// 	free(str);
	
// 	close(file_descriptor);
// 	return (0);
// }