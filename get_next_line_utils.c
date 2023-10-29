/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:09:29 by aglanuss          #+#    #+#             */
/*   Updated: 2023/10/29 13:23:05 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Returns a pointer to first '\n' character found.
 * If no one '\n' character was found, returns a null pointer.
*/
char  *new_line_position(char *str)
{
  size_t  i;

  i = 0;
  while (str[i] != '\n')
  {
    if (str[i] == '\0')
      return (NULL);
    i++;
  }
  return (&str[i]);
}

#include <stdio.h>
int main()
{
  char *str = "\n";

  printf("%s", new_line_position(str));
  return 0;
}