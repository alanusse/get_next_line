/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:45:21 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/22 12:38:38 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	set_content(int fd, char **content)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		bytes_read;

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
			return (NULL);
		return (line);
	}
	line = ft_substr(content, 0, nl_pos - content + 1);
	if (!line)
		return (NULL);
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
		return (free_ptr(content));
	free_ptr(content);
	*content = tmp;
}

char	*get_next_line(int fd)
{
	static char	*content[1025];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		free_ptr(&content[fd]);
		return (NULL);
	}
	line = NULL;
	set_content(fd, &content[fd]);
	if (!content[fd])
		return (NULL);
	line = extract_line(content[fd]);
	if (!line)
	{
		free_ptr(&content[fd]);
		return (NULL);
	}
	refresh_content(&content[fd]);
	return (line);
}

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