/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlalleik <nlalleik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:54:32 by nlalleik          #+#    #+#             */
/*   Updated: 2022/01/31 18:07:04 by nlalleik         ###   ########.fr       */
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
	len = ft_len((char *)s);
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*s;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	len = ft_len(s1);
	i = 0;
	while (i < len && ft_strrchr(set, s1[i]) != NULL)
		i++;
	if (i == len)
		return (ft_strdup(""));
	while (i <= len && ft_strrchr(set, s1[len - 1]) != NULL)
			len--;
	s = ft_calloc((len - i + 1), sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, &s1[i], len - i + 1);
	return (s);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (!size)
		return (ft_len(src));
	while ((len < (size - 1)) && (src[len] != '\0'))
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	while (src[len] != 0)
		len++;
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (c < 0 || c > 127)
		return ((char *)s);
	len = ft_len((char *)s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;

	len = ft_len(s);
	dup = ft_calloc((len + 1), sizeof(char));
	if (dup == NULL)
		return (0);
	while (len > 0)
	{
		dup[len - 1] = s[len - 1];
		len--;
	}
	return (dup);
}