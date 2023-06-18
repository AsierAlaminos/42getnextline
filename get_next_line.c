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

char	*get_next_line(int fd)
{
	char				*str;

	if (fd == 0 || BUFFER_SIZE <= 0)
		return (0);
	str = malloc(sizeof(char) * BUFFER_SIZE);
	if (str == 0)
		return (0);
	return (get_end_line(str, fd));
}
/*
int	main(void)
{
	char	*str;
	int		i;
	int		fd = open("test2", O_RDONLY);

	i = 0;
	while (i < 15){
		str = get_next_line(fd);
		printf("texto: %s\n", str);
		++i;
	}
	return (0);
}*/
