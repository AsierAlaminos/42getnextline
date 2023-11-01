/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalamino <aalamino@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:02:03 by aalamino          #+#    #+#             */
/*   Updated: 2023/11/01 16:15:49 by aalamino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;
	char	*str;

	i = 0;
	character = (char) c;
	str = (char *) s;
	if (!str)
		printf("lll");
	while (str[i] != '\0')
	{
		if (str[i] == character)
			return (&str[i]);
		++i;
	}
	if (str[i] == character)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	int		i;
	int		j;

	pointer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		pointer[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		pointer[i + j] = s2[j];
		++j;
	}
	pointer[i + j] = '\0';
	return (pointer);
}

char	*get_all_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!temp && !str)
		return (NULL);
	if (str[i] == '\n')
		return (&str[i]);
	while (str[i] != '\n' && str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*reduce_str(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	temp = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (str);
	if (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\0'))
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}
