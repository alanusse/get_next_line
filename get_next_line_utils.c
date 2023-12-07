/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:55 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/07 01:13:32 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str)
{
  size_t  count;
  
  count = 0;
  while (str[count])
    count++;
  return (count);
}

char    *ft_strchr(char *s, int c)
{
  int     i;
  int     len;

  if (!s)
    return (NULL);
  i = 0;
  len = ft_strlen(s);
  while (i <= len)
  {
    if (s[i] == (char)c)
      return ((char *)&s[i]);
    i++;
  }
  return (NULL);
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

char    *ft_strjoin(char *s1, char *s2)
{
  char            *ptr;
  size_t          i;
  size_t          j;
  size_t          strlen;

  strlen = ft_strlen(s1) + ft_strlen(s2);
  ptr = (char *)malloc((strlen + 1) * sizeof(char));
  if (!ptr)
    return (NULL);
  i = -1;
  while (s1[++i])
    ptr[i] = s1[i];
  j = -1;
  while (s2[++j])
    ptr[i + j] = s2[j];
  ptr[i + j] = '\0';
  free(s1);
  return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
    return (ft_strdup(""));
	if (len >= ft_strlen(&s[start]))
		ptr = (char *)malloc((ft_strlen(&s[start]) + 1) * sizeof(char));
	else
		ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}