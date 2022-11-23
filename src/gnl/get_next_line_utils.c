/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:45:30 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/23 13:02:31 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_bzero(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		s[i++] = '\0';
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *aux)
{
	char	*s;
	int		i;
	int		ii;

	i = ft_strlen(str) + ft_strlen(aux);
	s = malloc(sizeof(char) * i + 1);
	if (!s)
		return (0);
	i = 0;
	if (!str)
		i = 0;
	else
	{
		while (str[i])
		{
			s[i] = str[i];
			i++;
		}
	}
	ii = 0;
	while (aux[ii])
		s[i++] = aux[ii++];
	s[i] = '\0';
	free(str);
	return (s);
}
