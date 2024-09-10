/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:52:54 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/23 15:30:39 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	freeing(char **one, char **two)
{
	free(*one);
	free(*two);
}

char	*reading(int fd, char *left_c, int b_read, char *tmp)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0 || (b_read == 0 && *left_c == '\0'))
		{
			freeing(&left_c, &buffer);
			return (NULL);
		}
		buffer[b_read] = '\0';
		tmp = ft_strjoin(left_c, buffer);
		if (!tmp)
		{
			freeing(&left_c, &buffer);
			return (NULL);
		}
		free(left_c);
		left_c = tmp;
		if (b_read == 0 || ft_strchr(left_c, '\n'))
			break ;
	}
	free(buffer);
	return (left_c);
}

char	*taking(char *buffer)
{
	int		i;
	char	*new;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	new = ft_substr(buffer, 0, i);
	return (new);
}

char	*change(char *buffer)
{
	char	*new;
	char	*new_pos;

	new_pos = ft_strchr(buffer, '\n');
	if (!new_pos)
	{
		free(buffer);
		buffer = NULL;
		new = NULL;
	}
	else
	{
		new = ft_strdup(new_pos + 1);
		free(buffer);
		buffer = NULL;
	}
	return (new);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*buffer;
	int			i;
	char		*tmp;

	tmp = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = reading(fd, buffer, i, tmp);
	if (!buffer)
		return (NULL);
	result = taking(buffer);
	buffer = change(buffer);
	return (result);
}
