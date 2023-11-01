/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:58:48 by aalamino          #+#    #+#             */
/*   Updated: 2023/11/01 16:16:07 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*reader(char *str, int fd)
{
	char	*lecture;
	int		read_b;

	read_b = 1;
	lecture = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	while (read_b != 0 && !ft_strchr(str, '\n'))
	{
		read_b = read(fd, lecture, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(lecture);
			return (NULL);
		}
		str = ft_strjoin(str, lecture);
	}
	free(lecture);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*read_str;
	char		*linea;

	if (!str)
		str = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	read_str = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	if (fd < 0 || BUFFER_SIZE <= 0 || !read_str || !str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
	{
		read_str = reader(read_str, fd);
		str = ft_strjoin(str, read_str);
	}
	linea = get_all_line(str);
	str = reduce_str(str);
	free(read_str);
	return (linea);
}
/*
void leaks(void) { system("leaks -q gnl"); }

int	main(void)
{
	char	*str;
	int		i;
	int		fd = open("./test5", O_RDWR);

	atexit(leaks);
	i = 0;
	while (i < 15){
		printf("\n++++++++++++++++++++++++++++\ni: %d\n", i);
		str = get_next_line(fd);
		printf("\ntexto: |%s|\n", str);
		++i;
	}
	close(fd);
	return (0);
}*/
