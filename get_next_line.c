/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/26 17:51:32 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*next_line;
	static size_t	i;
	size_t			j;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	i = 0;
	j = 0;
	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		// if (i > 0)
		// strjoin remaining buffer + fd[i * BUFFER_SIZE] buffersize - remaining buffer
		//copy buffer to next_line up to and incl \n
		while (buffer[j] != '\n' && buffer[j] != '\0')
		{
			next_line[j] = buffer[j];
			ft_strcpy(next_line, buffer);
			j++;
		}
		return(next_line);

		//change pointer to buffer memmove
		//increment i
	}

}