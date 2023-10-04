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

char	*get_next_line(int fd)
{
	static char	*str;

	str = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = reader(str, fd);
	if (!str)
		return (NULL);
	return (str);
}

int	main(void)
{
	char	*str;
	int		i;
	int		fd = open("./test3", O_RDONLY);

	i = 0;
	while (i < 30){
		printf("i: %d\n", i);
		str = get_next_line(fd);
		printf("texto: |%s|\n", str);
		++i;
	}
	close(fd);
	return (0);
}
