/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:42:06 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/19 11:47:49 by clcarrer         ###   ########.fr       */
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
		write(1, "wrong number of character\n", 27);
	else if (error == 3)
		write(1, "not collectible or exit was found\n", 35);
	else if (error == 4)
		write(1, "not exit was found\n", 20);
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
