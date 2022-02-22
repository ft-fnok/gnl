/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/22 17:04:19 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*next_line;
	size_t			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!next_line)
		return (NULL);
	next_line[0] = '\0';
	// ft_bzero(next_line, BUFFER_SIZE + 1);
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
				return (ft_found_nl(buffer, next_line));
			next_line = ft_strjoin(next_line, buffer, 0);
		}
		readresult = read(fd, buffer, BUFFER_SIZE);
		if (readresult == -1 || (readresult == 0 && next_line[0] == '\0'))
			return (NULL);
		buffer[readresult] = '\0';
		if (readresult == 0)
			return (next_line);
	}
}

char	*ft_found_nl(char *buffer, char *next_line)
{
	char	*p_nl;
	char	*out;
	size_t	i;
	size_t	bytes;

	i = 0;
	p_nl = ft_strchr(buffer, '\n');
	bytes = p_nl - buffer + 1;
	out = (char *)malloc(ft_strlen(next_line) + bytes + 2);
	if (!out)
		return (NULL);
	out = ft_strjoin(next_line, buffer, bytes);
	while (buffer[i + bytes] != '\0')
	{
		buffer[i] = buffer[i + bytes];
		i++;
	}
	buffer[i] = '\0';
	free(next_line);
	return (out);
}

#include <stdio.h>

int main(void)
{
	int fildes = open("testfile", O_RDWR);
	if (fildes >= 0)
	{
		printf("fildes = %i\n", fildes);
		printf("%s", get_next_line(fildes));
		printf("%s", get_next_line(fildes));
		printf("%s", get_next_line(fildes));
		printf("%s", get_next_line(fildes));
		close(fildes);
	}
}