/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:58:48 by aalamino          #+#    #+#             */
/*   Updated: 2023/11/04 17:22:22 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer;
	int		i;

	pointer = (char *)malloc(ft_strlen(s1) + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		++i;
	}
	pointer[i] = '\0';
	return (pointer);
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
			return (NULL);
		}
		lecture[read_b] = '\0';
		if (!lecture)
			return (NULL);
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

	if (!str)
		str = (char *)calloc(1, sizeof(char));
	read_str = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !read_str || !str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
	{
		read_str = reader(read_str, fd);
		if (!read_str)
			return (NULL);
		str = ft_strjoin(str, read_str);
	}
	linea = get_all_line(str);
	str = reduce_str(str);
	if (!linea || !str)
		free(str);
	free(read_str);
	return (linea);
}

void leaks(void) { system("leaks -q gnl"); }

int	main(void)
{
	char	*str;
	int		i;
	int		fd = open("./multiple_nl.txt", O_RDWR);

	atexit(leaks);
	i = 0;
	while (i < 6){
		//printf("\n++++++++++++++++++++++++++++\ni: %d\n", i);
		str = get_next_line(fd);
		//get_next_line(fd);
		printf("\ntexto: |%s|\n", str);
		++i;
	}
	close(fd);
	return (0);
}
