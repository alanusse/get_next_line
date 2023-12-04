/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:17:33 by aglanuss          #+#    #+#             */
/*   Updated: 2023/12/04 19:45:06 by aglanuss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t ft_strlen(char *str);
char  *ft_strchr(char *s, int c);
char  *ft_strdup(char *str);
char  *ft_strndup(char *str, size_t n);
char	*ft_strjoin(char *s1, char *s2);

#endif