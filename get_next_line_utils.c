/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmus37 <asmus37@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:02:03 by asmus37           #+#    #+#             */
/*   Updated: 2023/05/07 19:02:04 by asmus37          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str, int max_size)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n' && len <= max_size)
		++len;
	return (len);
}

char	*get_end_line(char *text, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(size);
	while (text[i] != '\0' && text[i] != '\n')
	{
		printf("h");
		str[i] = text[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
