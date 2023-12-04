/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:55 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/04 01:17:38 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
  size_t  count;

  count = 0;
  while (str[count])
    count++;
  return (count);
}

char  *ft_strdup(char *str)
{
  char    *ptr;
  size_t  i;

  ptr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
  if (!ptr)
    return (NULL);
  i = 0;
  while (str[i])
  {
    ptr[i] = str[i];
    i++;
  }
  return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	size_t		i;
	size_t		j;
	size_t		strlen;

	strlen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
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

char  *ft_strndup(char *str, size_t n)
{
  char    *ret;
  size_t  i;

  if (n <= 0)
    return (NULL);
  ret = (char *)malloc((n + 1) * sizeof(char));
  if (!ret)
    return (NULL);
  i = 0;
  while (i < n)
  {
    ret[i] = str[i];
    i++;
  }
  return (ret);
}