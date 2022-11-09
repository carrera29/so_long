/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:32:24 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/09 16:28:04 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker_map(t_map *map)
{
	map->p = 0;
	map->e = 0;
	map->c = 0;
	map->y = 0;
	if (map->max_x == map->max_y)
		control_error(map, 1);
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			if ((map->map[0][map->x] != '1') || (map->map[map->max_y][map->x] != '1')
				|| (map->map[map->y][0] != '1') || (map->map[map->y][map->max_x] != '1'))
				control_error(map, 1);
			if (map->map[map->y][map->x] == 'P')
				map->p++;
			else if (map->map[map->y][map->x] == 'E')
				map->e++;
			else if (map->map[map->y][map->x] == 'C')
				map->c++;
			map->x++;
		}
		map->y++;
	}
	if (map->p != 1 || map->e != 1 || map->c < 1)
		control_error(map, 2);
}
