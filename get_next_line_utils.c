/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:02:03 by aalamino           #+#    #+#             */
/*   Updated: 2023/06/13 13:27:00 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_end_line(char *text, int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(2);
	read(fd, str, 1);
	while (str[0] != '\0' && str[0] != '\n')
	{
		text[i] = str[0];
		read(fd, str, 1);
		++i;
	}
	text[i] = '\0';
	free(str);
	return (text);
}
