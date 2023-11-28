/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:58:48 by aalamino          #+#    #+#             */
/*   Updated: 2023/11/26 17:58:55 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*liberar(char *pointer)
{
	free(pointer);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*a;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = '\0';
		++i;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}

char	*reader(char *str, int fd)
{
	char	*lecture;
	int		read_b;

	read_b = 1;
	while (read_b != 0 && !ft_strchr(str, '\n'))
	{
		lecture = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
		read_b = read(fd, lecture, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(lecture);
			return (liberar(str));
		}
		lecture[read_b] = '\0';
		if (!lecture)
		{
			free(lecture);
			return (liberar(str));
		}
		str = ft_strjoin(str, lecture);
		free(lecture);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*read_str;
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = (char *)ft_calloc(1, sizeof(char));
	read_str = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!ft_strchr(str, '\n'))
	{
		read_str = reader(read_str, fd);
		if (!read_str)
		{
			read_str = liberar(read_str);
			str = liberar(str);
			return (NULL);
		}
		str = ft_strjoin(str, read_str);
	}
	linea = get_all_line(str);
	str = reduce_str(str);
	free(read_str);
	return (linea);
}
