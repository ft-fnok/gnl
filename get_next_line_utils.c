/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:54:32 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/22 17:28:59 by nlalleik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*first_c;
	size_t	i;
	size_t	len;

	i = 0;
	if (c > 255)
		return ((char *)s);
	len = ft_strlen((char *)s);
	while (i <= len)
	{
		if (s[i] == c)
		{
			first_c = (char *)&s[i];
			return (first_c);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *next_line, char *buf, size_t bytes)
{
	char	*out;

	if (!next_line || !buf)
		return (NULL);
	out = (char *)malloc(ft_strlen(next_line) + ft_strlen(buf) + 1);
	if (!out)
		return (NULL);
	return (ft_cplogic(out, next_line, buf, bytes));
	}

char	*ft_cplogic(char *out, char *next_line, char *buf, size_t bytes)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (next_line[i] != '\0')
		{
			out[i] = next_line[i];
			i++;
		}
	if (bytes == 0)
	{
		while (buf[j] != '\0')
				out[i++] = buf[j++];
	}
	else
	{
		while (j < bytes)
			out[i++] = buf[j++];
	}
	out[i] = '\0';
	return (out);
}

// void	ft_bzero(void *s, size_t n)
// {
// 	char	*a;

// 	a = (char *)s;
// 	while (n > 0)
// 	{
// 		a[(n - 1)] = '\0';
// 		n--;
// 	}
// }
