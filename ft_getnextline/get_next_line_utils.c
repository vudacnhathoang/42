/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:50:58 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/19 14:38:34 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	g;

	g = (char) c;
	while (*s)
	{
		if (*s == g)
			return ((char *)s);
		s++;
	}
	if (g == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	ln;
	size_t	i;
	char	*newstr;

	ln = ft_strlen(s1) + 1;
	i = 0;
	newstr = malloc(sizeof(char) * ln);
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	ln;

	ln = ft_strlen(s);
	if (start >= ln)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	if (ln - start < len)
		len = ln - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < (size_t)ln && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	char	*start;

	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	start = newstr;
	if (!newstr)
		return (NULL);
	while (*s1)
	{
		*newstr = *s1;
		s1++;
		newstr++;
	}
	while (*s2)
	{
		*newstr = *s2;
		s2++;
		newstr++;
	}
	*newstr = '\0';
	return (start);
}
