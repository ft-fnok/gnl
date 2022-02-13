/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:38:31 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/13 14:58:23 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stddef.h>
// included for use of size_t type
# include <stdlib.h>
// include for use of malloc
# include <unistd.h>
// include for use of read

// gnl
char	*get_next_line(int fd);
char	*ft_strjoin(char *next_line, char *buffer);
char	*ft_strdup(const char *s);
//gnl-utils
char	*ft_strchr(const char *s, int c); //addr of first occurence of c
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(char *s, c);
#endif