/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:58:48 by aalamino          #+#    #+#             */
/*   Updated: 2023/09/28 17:30:24 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd == 0 || BUFFER_SIZE < 0)
		return (0);
	str = reader(str, fd);
	if (!str)
		return (NULL);
	line = get_end_line(str);
	free(str);
	return (line);
}

int	main(void)
{
	char	*str;
	int		i;
	int		fd = open("test2", O_RDONLY);

	i = 0;
	while (i < 15){
		printf("i: %d\n", i);
		str = get_next_line(fd);
		printf("texto: %s\n", str);
		++i;
	}
	return (0);
}
