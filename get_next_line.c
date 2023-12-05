/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/05 23:18:43 by aglanuss         ###   ########.fr       */
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
	char		*ret;
	ssize_t	read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	if (read_bytes <= 0)
		return NULL;
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

// char	*strtrim(char **str)
// {
// 	int		i;
// 	char	*ret;
// 	char	*string;
// 	char	*tmp;

// 	i = 0;
// 	string = *str;
// 	while (string[i] != '\n')
// 		i++;
// 	ret = (char *)malloc((i + 2) * sizeof(char));
// 	if (!ret)
// 		return (NULL);
// 	ret[i + 1] = '\0';
// 	i = -1;
// 	while (string[++i] != '\n')
// 		ret[i] = string[i];
// 	ret[i] = '\n';
// 	ret[i + 1] = '\0';
// 	tmp = ft_strdup(ft_strchr(*str, '\n'));
// 	free(*str);
// 	*str = tmp;
// 	return (ret);
// }

// /**
//  * Assign read content to a variable, trim it until a '\\n' character and assign the trimmed
//  * value (including '\\n' character) to another variable.
// */
// char	*format_content(char **content)
// {
// 	char	*tmp;

// 	if (!ft_strchr(*content, '\n'))
// 	{
// 		tmp = ft_strdup(*content);
// 		free(*content);
// 		return (tmp);
// 	}
// 	else
// 		return (strtrim(content));
// }

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1 * sizeof(char));
	if (!sub)
	{
		free (s);
		return (NULL);
	}
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	free(s);
	return ((char *)sub);
}


char	*strdup_until_newline(char *str)
{
	size_t	size;
	char		*ret;

	size = 0;
	while (str[size] != '\n')
		size++;
	ret = (char *)malloc((size + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	
	
}

char	*format_content(char **content)
{
	hola comoestas/nsoyjuan/0
	char	*tmp;
	char	*ret;
	char	*n_pos;

	n_pos = ft_strchr(*content, '\n');
	if (!n_pos) //caso ultima linea
	{
		tmp = ft_strdup(*content);
		free(*content);
		return (tmp);
	}
	else
	{
		tmp = ft_substr(*(content), 0, n_pos + 1); //obtener la linea
		//actualizar content
		ret = ft_substr(*(content), n_pos + (*content), );
	}
}


char	*get_next_line(int fd)
{
	static char	*content;
	char *line;
	// printf("content: %s\n", content);

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, content, 0) < 0)
		return (NULL);
	read_until_newline(fd, &content);
	line = format_content(&content)
	return (line);
}

int main()
{
	int     file_descriptor;

	file_descriptor = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(file_descriptor));
	return (0);
}