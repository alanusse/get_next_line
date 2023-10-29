/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:09:29 by aglanuss          #+#    #+#             */
/*   Updated: 2023/10/29 22:46:37 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Returns non-null characters count.
*/
size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while(str[count])
		count++;
	return (count);
}

/**
 * Join two strings and returns the new one.
 * If memory alocation fails, returns NULL pointer.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		i;
	size_t		j;
	size_t		strlen;

	strlen = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc((strlen + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

/**
 * Returns a pointer to first '\n' character found.
 * If no one '\n' character was found, returns a null pointer.
 */
char	*new_line_position(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}

/**
 * Read file until a '\n' or '\0' character are found.
*/
char	*read_file(int fd)
{
	char	*str;
	char	*n_position;
	ssize_t	read_characters;

	n_position = new_line_position(str);
	while (!new_line_position(str))
	{
		if (read(fd, str, BUFFER_SIZE) > 0)
		{
			
		}
	}
}

#include <stdio.h>
int main()
{
	char *str = "";

	printf("%s", new_line_position(str));
	return 0;
}