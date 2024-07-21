/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:56:42 by kchikwam          #+#    #+#             */
/*   Updated: 2024/07/21 09:06:53 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char	*src)
{
	int		length;
	char	*dup;
	int		i;

	length = 0;
	while (src[length] != '\0')
	{
		length++;
	}
	dup = (char *)malloc((length + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i <= length)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
