/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/30 23:22:21 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*next_line;
	static size_t	i;
	size_t			j;
	
	i = 0;
	j = 0;
	next_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (next_line++)
		next_line = '\0';
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || !next_line)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		// if (i > 0)
		// strjoin remaining buffer + fd[i] buffersize - remaining buffer
		//copy buffer to next_line up to and incl \n
		if (ft_len(buffer) < BUFFER_SIZE)
		{
			i++;
			return (ft_bufferjoin(next_line, buffer));		
		}
		//change pointer to buffer memmove
		else if (ft_len(buffer) == BUFFER_SIZE)
		{
			while(ft_len(buffer) == BUFFER_SIZE)
			
				next_line = ft_bufferjoin(next_line, buffer);
				read(fd, buffer, BUFFER_SIZE);
			i++;
			return (ft_bufferjoin(next_line, buffer));
		}
		while (buffer[j] != '\n')
			next_line[j++] = buffer[j];
		if (buffer[j] == '\n')
			next_line[j] = '\n';
		else if (buffer[j] < BUFFER_SIZE && buffer[j] == '\0')
			return(next_line);
		else
			free (buffer);
	
	}
	return (NULL);
}

size_t	ft_len(char *s)
{
	size_t i;
	
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_bufferjoin(char const *next_line, char const *buffer)
{
	char	*joint;
	size_t	nl_len;
	size_t	buf_len;
	size_t	i;
	size_t	j;

	i = 0;
	if (!next_line || !buffer)
		return (NULL);
	next_line = ft_len(next_line);
	buffer = ft_len(buffer);
	joint = (char *)malloc((nl_len + buf_len + 1) * sizeof(char));
	if (!joint)
		return (NULL);
	while(next_line[i] != '\0')
		joint[i++] = next_line[i];
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

void	*ft_memmove(*dest, *src, size_t n)
{
	
	return((void *)dest);
	)
}