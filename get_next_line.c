/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/04 22:46:35 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

/**
 * Read a file descriptor and return a string containing
 * all the reads until a '\\n' or '\\0' character are found.
 * 
 * If read function returns 0 bytes, return a NULL pointer.
*/
char	*read_until_newline(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*result;
	ssize_t	read_bytes;

	result = NULL;
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	while (!ft_strchr(result, '\n') && read_bytes > 0)
	{
		if (!result)
			result = ft_strdup(buffer);
		else
			result = ft_strjoin(result, buffer);
		if (!result)
			return (NULL);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
	}
	return (result);
}

char	*strtrim(char **str)
{
	int		i;
	char	*ret;
	char	*string;
	char	*tmp;

	i = 0;
	string = *str;
	while (string[i] != '\n')
		i++;
	ret = (char *)malloc((i + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[i + 1] = '\0';
	i = -1;
	while (string[++i] != '\n')
		ret[i] = string[i];
	ret[i] = '\n';
	ret[i + 1] = '\0';
	tmp = ft_strdup(ft_strchr(*str, '\n'));
	free(*str);
	*str = tmp;
	return (ret);
}

/**
 * Assign read content to a variable, trim it until a '\\n' character and assign the trimmed
 * value (including '\\n' character) to another variable.
*/
char	*format_content(char **content)
{
	char	*tmp;

	if (!ft_strchr(*content, '\n'))
	{
		tmp = ft_strdup(*content);
		free(*content);
		return (tmp);
	}
	else
		return (strtrim(content));
}

char	*get_next_line(int fd)
{
	static char	*content;

	printf("content: %s\n", content);

	if (fd < 0 || read(fd, content, 0) < 0)
		return (NULL);
	if (!content)
	{
		content = read_until_newline(fd);
		if (!content)
			return (NULL);
	}
	return (format_content(&content));
}


int    main(void)
{
    int        file_descriptor;
    char    *result;

    file_descriptor = open("tests/test1.txt", O_RDONLY);
    if (file_descriptor == -1)
        return (0);
    result = get_next_line(file_descriptor);
    if (result == NULL)
        return (0);
    while (result != NULL)
    {
        printf("%s", result);
        free(result);
        result = NULL;
        result = get_next_line(file_descriptor);
        if (result == NULL)
            return (0);
    }
    free(result);
    result = NULL;
    return (0);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("file.txt", O_RDONLY);
// 	printf("call: %s\n", get_next_line(fd));
// 	printf("call: %s\n", get_next_line(fd));
// 	printf("call: %s\n", get_next_line(fd));
// 	return (0);
// }
