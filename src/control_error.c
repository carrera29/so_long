/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeplatt <chloeplatt@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:42:06 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/10 12:04:09 by chloeplatt       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_map(t_map *map)
{
	while (map->max_y--)
		free((void *)map->map[map->max_y]);
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
		write(1, "duplicates were found\n", 23);
	else if (error == 3)
		write(1, "not collectible was found\n", 27);
	clean_map(map);
	exit (1);
}