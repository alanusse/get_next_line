/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/11 02:15:07 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

/**
 * Read file descriptor and returns read data.
 * 
 * If bytes read is 0 returns NULL.
 * If an error occurred in the read returns NULL.
*/
// char	*read_fd(int fd)
// {
// 	char		buffer[BUFFER_SIZE + 1];
// 	ssize_t	bytes_read;

// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	buffer[bytes_read] = '\0';
// 	if (bytes_read <= 0)
// 		return (NULL);
// 	return (ft_strdup(buffer));
// }
char	*read_fd(int fd)
{
	char		buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	char		*ret;
	ssize_t	i;

	bytes_read = read(fd, &buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	ret = (char *)malloc((bytes_read + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[bytes_read] = '\0';
	i = -1;
	while (++i < bytes_read)
		ret[i] = buffer[i];
	return (ret);
}

/**
 * Read file descriptor and join results until a '\\n' or '\\0' character
 * is found in result string.
 * 
 * If there is nothing to read returns NULL.
*/
char	*read_fd_until_newline(int fd)
{
	char	*read_data;
	char	*ret;

	ret = NULL;
	while (!ret || !ft_strchr(ret, '\n'))
	{
		read_data = read_fd(fd);
		if (!read_data)
			return (ret);
		if (!ret)
			ret = read_data;
		else
		{
			ret = ft_strjoin(ret, read_data);
			free(read_data);
		}
	}
	return (ret);
}
/**
 * hola
 * hola\nhola
 * hola\n
 * hola\n\n
 * \nhola
 * \n\nhola
*/
char	*return_line(char **content)
{
	char	*newline_position;
	char	*tmp;
	char	*ret;

	newline_position = ft_strchr(*content, '\n');
	if (!newline_position)
	{
		ret = ft_strdup(*content);
		free(*content);
		*content = NULL;
	}
	else
	{
		ret = ft_substr(*content, 0, newline_position - *content + 1);
		if (!ret)
			return (NULL);
		tmp = ft_strdup(newline_position + 1);
		if (!tmp)
			return (NULL);
		free(*content);
		*content = tmp;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char				*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!content) // caso primera llamada o llamada luego de devolver todas las lineas.
		content = read_fd_until_newline(fd);
	else if (!ft_strchr(content, '\n')) // caso llamada que no contenga \n en el content.
	{
		tmp = read_fd_until_newline(fd);
		if (tmp)
		{
			content = ft_strjoin(content, tmp);
			free(tmp);
		}
	}
	if (!content)
		return (NULL);
	return (return_line(&content));
}

// int main()
// {
// 	int     file_descriptor;
// 	char    *str;

// 	file_descriptor = open("file.txt", O_RDONLY);
	
// 	str = get_next_line(file_descriptor);
// 	printf("%s", str);
// 	free(str);
	
// 	// str = get_next_line(file_descriptor);
// 	// printf("%s", str);
// 	// str = get_next_line(file_descriptor);
// 	// printf("%s", str);
// 	// str = get_next_line(file_descriptor);
// 	// printf("%s", str);

// 	return (0);
// }

// int main()
// {
// 	char *str = "hola\n mundo";
// 	char *ch = ft_strchr(str, '\n');

// 	printf("%s", ft_substr(str, 0, ch - str + 1));
// 	return (0);
// }