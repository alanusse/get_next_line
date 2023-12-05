/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/05 14:09:08 by aglanuss         ###   ########.fr       */
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
 * and return a string with all buffers joined into it.
 * 
 * If there is nothing to read or an error occurred, return NULL.
*/
char	*read_until_newline(int fd)
{
	char	*read;
	char	*tmp;
	char	*ret;

	ret = NULL;
	while (!ft_strchr(ret, '\n'))
	{
		read = get_read_data(fd);
		if (!read)
			return (ret);
		if (!ret)
			ret = read;
		else
		{
			tmp = ft_strjoin(ret, read);
			free(ret);
			free(read);
			ret = tmp;
		}
	}
	return (ret);
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

// char	*get_next_line(int fd)
// {
// 	static char	*content;

// 	// printf("content: %s\n", content);

// 	if (fd < 0 || read(fd, content, 0) < 0)
// 		return (NULL);
// 	read_until_newline(fd, &content);
// 	return (format_content(&content));
// }


// int    main(void)
// {
//     int     file_descriptor;
//     char    *result;

//     file_descriptor = open("file.txt", O_RDONLY);
//     if (file_descriptor == -1)
//         return (0);
//     result = read_until_newline(file_descriptor);
//     if (result == NULL)
//         return (0);
//     while (result != NULL)
//     {
//         printf("read: %s\n", result);
//         free(result);
//         result = NULL;
//         result = read_until_newline(file_descriptor);
//         if (result == NULL)
//             return (0);
//     }
//     free(result);
//     result = NULL;
//     return (0);
// }

int main()
{
	return (0);
}

// int    main(void)
// {
//     int        file_descriptor;
//     char    *result;

//     file_descriptor = open("tests/test1.txt", O_RDONLY);
//     if (file_descriptor == -1)
//         return (0);
//     result = get_next_line(file_descriptor);
//     if (result == NULL)
//         return (0);
//     while (result != NULL)
//     {
//         printf("%s", result);
//         free(result);
//         result = NULL;
//         result = get_next_line(file_descriptor);
//         if (result == NULL)
//             return (0);
//     }
//     free(result);
//     result = NULL;
//     return (0);
// }
