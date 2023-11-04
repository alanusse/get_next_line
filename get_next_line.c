/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:18:20 by aglanuss          #+#    #+#             */
/*   Updated: 2023/11/04 20:18:53 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <printf.h>

char	*append_new_buffer(char *str, char *buffer)
{
	if (!str)
		return (ft_strdup(buffer));
	else
		return (ft_strjoin(str, buffer));
}

char	*read_until_newline(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*str;
	char	*tmp;

	str = NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (!str)
		{
			str = ft_strdup(buffer);
			printf("----\n\nstr: %s\n\n----\n", str);
		}
		else
		{
			tmp = ft_strjoin(str, buffer);
			// printf("----\n\nstr: %s\n\n----\n", str);
			free(str);
			str = tmp;
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{

}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("file.txt first line:\n\n");
	printf("%s", read_until_newline(fd));
	return (0);
}
