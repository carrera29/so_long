/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:41 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/11 13:00:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_values(t_map *map)
{
	while (map->map[map->max_y + 1])
		map->max_y++;
	map->max_x = ft_strlen(map->map[0]) - 1;
}

void	get_map(t_map *map, char **argv)
{
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		control_error(map, 0);
	map->add_line = NULL;
	while (map->line)
	{
		map->line = get_next_line(map->fd);
		if (map->line == NULL || map->line[0] == '\n')
			break ;
		map->add_line = ft_strjoin(map->add_line, map->line);
		free(map->line);
	}
	free (map->line);
	map->map = ft_split(map->add_line, '\n');
	get_values(map);
}
