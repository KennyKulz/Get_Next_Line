/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchikwam <kchikwam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:29:52 by kchikwam          #+#    #+#             */
/*   Updated: 2024/07/21 09:07:09 by kchikwam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_str_len(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_str_dup_len(const char *src, size_t len);
char	*ft_strchr(const char *s, int c);

#endif