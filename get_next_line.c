/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/15 22:12:55 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	next_line = (char *)malloc(BUFFER_SIZE + 1);
	if (!next_line)
		return (NULL);
	next_line[0] = '\0';
	next_line[BUFFER_SIZE] = '\0';
	return(gnl_handler(buffer, next_line, fd));
}

char	*gnl_handler(char *buffer, char *next_line, int fd)
{
	ssize_t	readresult;

	while (1)
	{
		if (buffer[0])
		{
		//	printf("Option: A - buffer[0]\n");
			if(ft_strchr(buffer, '\n'))
				return(ft_found_nl(buffer, next_line));
			next_line = ft_strjoin(next_line, buffer);
		}
		readresult = read(fd, buffer, BUFFER_SIZE);
		// printf("read file: %s\n", buffer);
		if (readresult == -1)
		{
			printf("Option: B - readresult = (-1)\n");
			free(next_line);
			return(NULL);
		}
		buffer[readresult] = '\0';
		if (readresult == 0)
		{
			printf("Option: C - readresult = 0\n");
			return(next_line);
		}
	}
}
char	*ft_found_nl(char *buffer, char* next_line)
{
	size_t	len_next_line;
	size_t	len_buf2nl;
	size_t	i;
	char	*new_next_line;

	i = 0;
	len_next_line = ft_strlen(next_line, '\0');
	len_buf2nl = ft_strlen(buffer, '\n') + 1;
	new_next_line = (char *)malloc(len_next_line +  len_buf2nl + 1);
	if (!new_next_line)
		return (NULL);
	new_next_line = ft_strjoin(next_line, buffer);
	while(buffer[len_buf2nl] != '\0' && buffer[len_buf2nl != '\n'])
		buffer[i++] = buffer[len_buf2nl++];
	free(next_line);
	return (new_next_line);
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
		fflush(stdout);
		close(fildes);
	}
}