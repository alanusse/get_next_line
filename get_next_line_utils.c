/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:09:29 by aglanuss          #+#    #+#             */
/*   Updated: 2023/10/30 15:05:36 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Create a return a pointer to new list of t_buffer type.
*/
t_buffer	*newlst_buffer(char *content)
{
	t_buffer	*node;

	node = (t_buffer *)malloc(sizeof(t_buffer));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/**
 * Add list passed by argument after the last one node of the linked list.
*/
void	*addlst_buffer(t_buffer **lst, t_buffer *new)
{
	t_buffer	*current;

	if (!*lst)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

/**
 * Returns non-null characters count.
*/
size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
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
 * Returns a pointer to first '\\n' character found.
 * If no one '\\n' character was found, returns a null pointer.
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
 * Read file until a '\\n' or '\0' character are found.
*/
char	*read_file(int fd)
{
	char		*buffer_content[BUFFER_SIZE];
	t_buffer	*buffer_list;
	ssize_t		read_bytes;

	read_bytes = read(fd, buffer_content, BUFFER_SIZE);
	while (read_bytes > 0 || !new_line_position(buffer_content))
	{
		read_bytes = read(fd, buffer_content, BUFFER_SIZE);
	}
}

#include <stdio.h>
int main()
{
	char *str = "";

	printf("%s", new_line_position(str));
	return 0;
}