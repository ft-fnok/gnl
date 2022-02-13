/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/13 18:56:25 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	next_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!next_line)
		return (NULL);
	return(gnl_handler(buffer, next_line, fd));
}

char *gnl_handler(char *buffer, char *next_line, int fd)
{
	ssize_t	readresult;

	while (1)
	{
		if (buffer[0])
		{
			if(ft_strchr(buffer, '\n'))
				return(ft_found_nl(buffer, next_line));
			ft_strjoin(next_line, buffer);
		}
		readresult = read(fd, buffer, BUFFER_SIZE);
		if (readresult == -1)
		{
			free(next_line);
			return(NULL);
		}
		buffer[readresult] = '\0';
		if (readresult == 0)
			return(next_line);
	}
}
char	*ft_found_nl(char *buffer, char* next_line)
{
	size_t	len_next_line;
	size_t	len_buffer_to_nl;
	size_t	i;
	char	*new_next_line;

	i = 0;
	len_next_line = ft_strlen(next_line, '\0');
	len_buffer_to_nl = ft_strlen(buffer, '\n') + 1;
	new_next_line = (char *)malloc(len_next_line +  len_buffer_to_nl + 1);
	if (!new_next_line)
		return (NULL);
	i += ft_strlcpy(new_next_line, next_line, len_next_line);
	i += ft_strlcpy(&new_next_line[len_next_line], buffer, len_buffer_to_nl);
	new_next_line[i] = '\0';
	i = len_buffer_to_nl + 1;
	while (buffer[i] != '\0')
		buffer++ = buffer[i++];
	buffer[i] = '\0';
	free(next_line);
	return(new_next_line)
}

char	*ft_strjoin(char  *next_line, char  *buffer)
{
	char	*joint;
	size_t	nl_len;
	size_t	buf_len;
	size_t	i;
	size_t	j;

	nl_len = ft_strlen(next_line, '\0');
	buf_len = ft_strlen(buffer, '\0');
	i = 0;
	j= 0;

	if (!next_line || !buffer)
		return (NULL);
	joint = (char *)malloc(nl_len + buf_len + 1);
	if (!joint)
		return (NULL);
	while(next_line[i] != '\0')
	{
		joint[i] = next_line[i];
		i++;
	}
	while(buffer[j] != '\0' && buffer[j] != '\n')
		joint[i++] = buffer[j++];
	if (buffer[j] == '\n')
	{
		joint[i] = '\n';
		joint[i + 1] = '\0';
		buffer = &buffer[j + 1];
	}
	joint[i] = '\0';
	return (joint);
}
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s, '\0');
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (0);
	dup[len] = '\0';
	while (len > 0)
	{
		dup[len - 1] = s[len - 1];
		len--;
	}
	return (dup);
}

#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}

int main(void)
{
	int fildes = open("/Users/nlalleik/Desktop/projects/gnl/testfile", O_RDWR);
	printf("%s", get_next_line(fildes));
	printf("%s", get_next_line(fildes));
	printf("%s", get_next_line(fildes));
}