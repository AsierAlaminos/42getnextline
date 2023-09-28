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

char	*get_end_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		++i;
	str = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
	{
		printf("gel\n");
		str[i] = text[i];
		++i;
	}
	if (text[i] == '\n')
	{
		str[i] = text[i];
		++i;
	}
	str[i] = '\0';
	return (str);
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
	int		read_b;
	char	*add;

	printf("reader");
	read_b = 1;
	add = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read_b != 0 && !ft_strchr(add, '\n'))
	{
		read_b = read(fd, add, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(add);
			return (NULL);
		}
		add[read_b] = '\0';
		str = ft_strjoin(str, add);
	}
	free(add);
	return (str);
}
