/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:58:48 by aalamino          #+#    #+#             */
/*   Updated: 2023/06/13 13:27:02 by aalamino         ###   ########.fr       */
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

	lecture = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	read_b = 1;
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
	char		*linea;

	str = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	if (fd < 0 || BUFFER_SIZE <= 0 || !str)
		return (NULL);
	str = reader(str, fd);
	linea = get_all_line(str);
	str = get_more(str);
	return (linea);
}
/*
int	main(void)
{
	char	*str;
	int		i;
	int		fd = open("./test5", O_RDONLY);

	i = 0;
	while (i < 10){
		printf("\n++++++++++++++++++++++++++++\ni: %d\n", i);
		str = get_next_line(fd);
		printf("texto: |%s|\n", str);
		++i;
	}
	close(fd);
	return (0);
}*/
