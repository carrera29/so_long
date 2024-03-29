/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:42:06 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/30 11:18:15 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(t_data *data)
{
	int	y;

	y = 0;
	while (data->map.map[y] != NULL)
		free(data->map.map[y++]);
	free(data->map.map);
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
	if (error == 8)
		exit (1);
	clean_map(data);
	exit (1);
}
