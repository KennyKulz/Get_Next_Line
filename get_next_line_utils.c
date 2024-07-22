/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:55:40 by kchikwam          #+#    #+#             */
/*   Updated: 2024/07/22 16:34:34 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_str_dup_len(const char	*src, size_t len)
{
	char	*copy;
	size_t	i;

	if (src == NULL)
		return (NULL);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len && src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_str_len(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
