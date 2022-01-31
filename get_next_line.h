/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:38:31 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/31 18:25:30 by nlalleik         ###   ########.fr       */
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
size_t	ft_len(char *s);
char	*ft_bufferjoin(char *next_line, char *buffer);
void 	*ft_calloc(size_t num, size_t size);
//gnl-utils
char	*ft_strchr(const char *s, int c); //addr of first occurence of c
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strrchr(const char *s, int c); //addr of last occurence of c
char	*ft_strdup(const char *s);
#endif