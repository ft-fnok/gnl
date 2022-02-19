/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:54:32 by nlalleik          #+#    #+#             */
/*   Updated: 2022/02/19 14:43:13 by nlalleik         ###   ########.fr       */
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

// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	len;

// 	len = 0;
// 	if (!size)
// 		return (ft_strlen((char *)src));
// 	while ((len < (size - 1)) && (src[len] != '\0'))
// 	{
// 		dest[len] = src[len];
// 		len++;
// 	}
// 	dest[len] = '\0';
// 	while (src[len] != 0)
// 		len++;
// 	return (len);
// }

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	size_t	len;

// 	len = ft_strlen((char *)s);
// 	dup = (char *)malloc(len + 1);
// 	if (dup == NULL)
// 		return (0);
// 	dup[len] = '\0';
// 	while (len > 0)
// 	{
// 		dup[len - 1] = s[len - 1];
// 		len--;
// 	}
// 	return (dup);
// }

char	*ft_strjoin(char  *next_line, char  *buf)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j= 0;
	if (!next_line || !buf)
		return (NULL);
	out = (char *)malloc(ft_strlen(next_line) + ft_strlen(buf) + 1);
	if (!out)
		return (NULL);
	//ft_bzero(out, ft_strlen(next_line) +  ft_strlen(buf) + 1);
	while(next_line[i] != '\0')
	{
		out[i] = next_line[i];
		i++;
	}
	while(buf[j] != '\0' && buf[j] != '\n')
		out[i++] = buf[j++];
	if (buf[j] == '\n')
		out[i] = '\n';
	out[++i] = '\0';
	return (out);
}

void	ft_bzero(void *s, size_t n)
{
	char	*a;

	a = (char *)s;
	while (n > 0)
	{
		a[(n - 1)] = '\0';
		n--;
	}
}