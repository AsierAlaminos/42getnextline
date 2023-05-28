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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		++len;
	return (len);
}

char	*get_end_line(char *text)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(text) + 1);
	while (text[i] != '\0' && text[i] != '\n')
	{
		str[i] = text[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
