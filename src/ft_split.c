/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:04:41 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/30 09:57:19 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = NULL;
		free(s[i++]);
	}
	s = NULL;
	free(s);
}

static unsigned int	ft_division(char const *s, char c)
{
	unsigned int	n;
	unsigned int	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (n);
}

static char	*ft_write(char *split, const char *s, int count, int i)
{
	unsigned int	x;

	split = (char *)malloc(sizeof(char) * (count + 1));
	if (!split)
	{
		free_split(&split);
		return (NULL);
	}
	x = 0;
	i = i - count;
	while (count)
	{
		split[x++] = s[i++];
		count--;
	}
	split[x] = '\0';
	return (split);
}

static char	**ft_str(char **split, char const *s, char c)
{
	unsigned int	i;
	unsigned int	ii;
	unsigned int	count;

	i = 0;
	ii = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
			{
				i++;
				count++;
			}
			split[ii] = ft_write(split[ii], s, count, i);
			count = 0;
			ii++;
		}
	}
	split[ii] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n;

	if (!s)
		return (0);
	n = ft_division(s, c);
	split = (char **)malloc(sizeof(s) * (n + 1));
	if (!split)
		return (0);
	split = ft_str(split, s, c);
	if (!split)
	{
		free_split(split);
		return (0);
	}
	return (split);
}
