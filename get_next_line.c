/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/30 21:52:18 by nlalleik         ###   ########.fr       */
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
			ft_readbuffer(fd);
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

char	*ft_bufferjoin(char const *s1, char const *s2)
{
	char	*joint;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_len(s1);
	s2_len = ft_len(s2);
	joint = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joint)
		return (NULL);
	while(s1[i] != '\0')
		joint[i++] = s1[i];
	while(s2[j] != '\0' && s2[j] != '\n')
		joint[i++] = s2[j++];
	if (s2[j] == '\n')
	
		joint[i] = '\n';
		joint[i + 1] = '\0';
	joint[i] = '\0';
	return (joint);
}
