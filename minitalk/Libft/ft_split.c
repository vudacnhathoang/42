/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvu-dac <nvu-dac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:47:32 by nvu-dac           #+#    #+#             */
/*   Updated: 2024/06/13 16:01:15 by nvu-dac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int	count;
	int	i;
	int	isword;

	i = 0;
	count = 0;
	isword = 0;
	while (s[i])
	{
		if (s[i] != c && !isword)
		{
			isword = 1;
			count++;
		}
		else if (s[i] == c)
		{
			isword = 0;
		}
		i++;
	}
	return (count);
}

static void	freeup(char **array, int j)
{
	while (j >= 0)
	{
		free(array[j]);
		j--;
	}
	free(array);
}

static const char	*interatings(const char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static const char	*iteee(const char *s, char c)
{
	while (*s != c && *s)
		s++;
	return (s);
}

char	**ft_split(const char *s, char c)
{
	char		**array;
	const char	*p;
	int			j;

	j = 0;
	array = (char **)malloc((countwords(s, c) + 1) * sizeof(array[0]));
	if (!array)
		return (NULL);
	while (*s)
	{
		s = interatings(s, c);
		p = s;
		s = iteee(s, c);
		if (s > p)
		{
			array[j++] = ft_substr(p, 0, s - p);
			if (!array[j - 1])
			{
				freeup(array, j - 1);
				return (NULL);
			}
		}
	}
	array[j] = NULL;
	return (array);
}
