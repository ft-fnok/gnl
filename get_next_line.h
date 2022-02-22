/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:38:31 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/22 15:30:37 by nlalleik         ###   ########.fr       */
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
#include <fcntl.h>


// gnl
char	*get_next_line(int fd);
char	*gnl_handler(char *buffer, char *next_line, int fd);
char	*ft_found_nl(char *buffer, char* next_line);
//char	*ft_strdup(const char *s);

//gnl-utils
char	*ft_strchr(const char *s, int c); //addr of first occurence of c
//size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *next_line, char *buffer, size_t bytes);
void	ft_bzero(void *s, size_t n);


#endif