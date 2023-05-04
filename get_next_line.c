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

void	imprimir_leidos()
{
	
}

char	*get_next_line(int fd)
{
	char	*readed;
	leidos = read(fd, cadena, BUFFER_SIZE);
}

int	main(void)
{
	int	fd = open("./test", O_RDONLY);
	get_next_line(fd);
	return (0);
}
