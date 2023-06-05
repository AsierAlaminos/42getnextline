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
#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 0
#endif

char	*get_end_line(char *text, int size);
int	ft_strlen(char *str, int max_size);

char	*get_next_line(int fd)
{
	char	*readed;
	char	*str;
	int		len_readed;

	if (fd == 0 || BUFFER_SIZE <= 0)
		return (0);
	readed = malloc(sizeof(char) * BUFFER_SIZE);
	len_readed = ft_strlen(readed, BUFFER_SIZE);
	str = malloc(sizeof(char) * len_readed);
	read(fd, str, len_readed);
	if (readed == 0)
		return (0);
	return (get_end_line(str, len_readed));
}

int	main(void)
{
	char	*str;
	int		i;
	int		fd = open("test", O_RDONLY);

	i = 0;
	while (i < 4){
		str = get_next_line(fd);
		printf("texto: %s\n", str);
		++i;
	}
	return (0);
}
