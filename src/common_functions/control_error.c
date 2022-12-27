/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:42:06 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/21 09:49:27 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < ((unsigned int)n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
	
void	clean_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->map.map[y] != NULL)
		free(data->map.map[y++]);
	free(data->map.map);
}

void	clean_check_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->map.check_map[y] != NULL)
		free(data->map.check_map[y++]);
	free(data->map.check_map);
}

void	*control_error(t_data *data, int error)
{
	write(1, "Error\n", 7);
	if (error == 1)
		write(1, "wrong map layout\n", 18);
	else if (error == 2)
		write(1, "wrong number of characters\n", 28);
	else if (error == 3)
		write(1, "not collectibles were found\n", 29);
	else if (error == 4)
		write(1, "wrong number of exits\n", 23);
	else if (error == 5)
		write(1, "malloc error\n", 14);
	else if (error == 6 || error == 7)
	{
		write(1, "unknown character was found\n", 29);
		if (error == 7)
			exit (1);
	}
	clean_map(data);
	exit (1);
}