/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:57 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/31 18:30:42 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*tmp;
	char			*buffer;
	char			*next_line;
	size_t			i;
	size_t			j;
	
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	i = 0;
	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		tmp = ft_strdup(buffer);
		if (buffer != ft_strchr(buffer, '\n'))
			ft_substr(temp, '\n')
		buffer = ft_strrchr(buffer, '\n')
		ft_strlcpy(next_line, tmp, BUFFER_SIZE - ft_len(buffer));
		tmp = ft_strtrim(tmp, '\n');
		next_line = (char *)ft_calloc(ft_len(tmp + 2, sizeof(char));
		while(ft_len(buffer) == BUFFER_SIZE)
		{
			next_line = ft_bufferjoin(next_line, buffer);
			read(fd, buffer, BUFFER_SIZE);
		}
		if (ft_len(buffer) < BUFFER_SIZE)
		{
			next_line = ft_bufferjoin(next_line, buffer);
		}
	}
	i++;
	return (next_line);
}	

size_t	ft_len(char *s)
{
	size_t i;
	
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_bufferjoin(char  *next_line, char  *buffer)
{
	char	*joint;
	size_t	nl_len;
	size_t	buf_len;
	size_t	i;
	size_t	j;

	nl_len = ft_len(next_line);
	buf_len = ft_len(buffer);
	i = 0;
	j= 0;
	
	if (!next_line || !buffer)
		return (NULL);
	joint = (char *)ft_calloc((nl_len + buf_len + 1), sizeof(char));
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

// void	*ft_memmove(char *dest, char *src, size_t n)
// {
	
// 	return((void *)dest);
// 	)
// }

void *ft_calloc(size_t num, size_t size)
{
	char	*out;

	out = (char *)malloc(num * size);
	if (!out)
		return (NULL);
	while (num > 0)
	{
		out[num - 1] = '\0';
		num--;
	}
	return ((void *)out);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fildes = open("/Users/nlalleik/Desktop/projects/gnl/testfile", O_RDWR);
	printf("%s", get_next_line(fildes));
	printf("%s", get_next_line(fildes));
	printf("%s", get_next_line(fildes));
}