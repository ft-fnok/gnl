/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/03/28 09:54:32 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = (char *)malloc(sizeof(char));
	if (!next_line)
		return (NULL);
	next_line[0] = '\0';
	return (gnl_handler(buffer, next_line, fd));
}

char	*gnl_handler(char *buffer, char *next_line, int fd)
{
	ssize_t	readresult;

	while (1)
	{
		if (buffer[0])
		{
			if (ft_strchr(buffer, '\n'))
			{
				return (ft_found_nl(buffer, next_line));
			}
			next_line = ft_strjoin(next_line, buffer, 0);
		}
		readresult = read(fd, buffer, BUFFER_SIZE);
		if (readresult == -1 || (readresult == 0 && next_line[0] == '\0'))
		{
			free(next_line);
			return (NULL);
		}
		buffer[readresult] = '\0';
		if (readresult == 0)
			return (next_line);
	}
}

char	*ft_found_nl(char *buffer, char *next_line)
{
	char	*out;
	size_t	i;
	size_t	bytes;

	i = 0;
	bytes = 0;
	while (buffer[bytes] != '\n')
		bytes++;
	bytes++;
	out = ft_strjoin(next_line, buffer, bytes);
	while (buffer[i + bytes] != '\0')
	{
		buffer[i] = buffer[i + bytes];
		i++;
	}
	buffer[i] = '\0';
	return (out);
}
