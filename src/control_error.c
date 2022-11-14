/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:42:06 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/14 10:39:11 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(t_map *map)
{
	while (map->max_y--)
		free(map->map[map->max_y]);
	free(map->map);
}

void	*control_error(t_map *map, int error)
{
	write(1, "Error\n", 7);
	if (error == 0)
		exit (write(1, "fd error\n", 10));
	else if (error == 1)
		write(1, "wrong map layout\n", 18);
	else if (error == 2)
		write(1, "the character is duplicated\n", 29);
	else if (error == 3)
		write(1, "not collectible or exit was found\n", 35);
	clean_map(map);
	exit (1);
}