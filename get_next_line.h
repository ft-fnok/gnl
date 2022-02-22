/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:38:31 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/22 17:36:31 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif
# include <stddef.h>
// included for use of size_t type
# include <stdlib.h>
// include for use of malloc
# include <unistd.h>
// include for use of read
# include <fcntl.h>

// gnl
char	*get_next_line(int fd);
char	*gnl_handler(char *buffer, char *next_line, int fd);
char	*ft_found_nl(char *buffer, char *next_line);

//gnl-utils
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *next_line, char *buffer, size_t bytes);
char	*ft_cplogic(char *out, char *next_line, char *buf, size_t bytes);

#endif