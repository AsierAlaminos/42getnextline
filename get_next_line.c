/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus37 <asmus37@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:58:48 by asmus37           #+#    #+#             */
/*   Updated: 2023/05/04 18:58:49 by asmus37          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*readed;
	int	leidos;

	readed = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, readed, BUFFER_SIZE);
	printf("texto: %s\n", readed);
	return (readed);
}

int	main(void)
{
	int	fd = open("./test", O_RDONLY);
	get_next_line(fd);
	return (0);
}
