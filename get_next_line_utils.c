/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:02:03 by aalamino          #+#    #+#             */
/*   Updated: 2023/06/13 13:27:00 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;
	char	*str;

	i = 0;
	character = (char) c;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == character)
			return (&str[i]);
		++i;
	}
	if (str[i] == character)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	int		i;
	int		j;

	pointer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		pointer[i + j] = s2[j];
		++j;
	}
	pointer[i + j] = '\0';
	return (pointer);
}

char	*reader(char *str, int fd)
{
	char	*lecture;
	int		read_b;
	int		line_counter;

	lecture = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	line_counter = 0;
	read_b = 1;
	while (read_b != 0 && !ft_strchr(str, '\n') && BUFFER_SIZE > line_counter)
	{
		read_b = read(fd, lecture, 1);
		if (read_b == -1)
		{
			free(lecture);
			return (NULL);
		}
		str = ft_strjoin(str, lecture);
		line_counter += read_b;
	}
	free(lecture);
	str[line_counter] = '\0';
	return (str);
}
