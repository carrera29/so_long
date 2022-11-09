/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:41 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/09 17:05:25 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_map *map, char **argv)
{
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		control_error(map, 0);
	map->line = get_next_line(map->fd);
	while (map->line)
	{
		if (map->line == NULL || map->line[0] == '\n')
			break ;
		map->add_line = ft_strjoin(map->add_line, map->line);
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	free (map->line);
	map->map = ft_split(map->add_line, '\n');
	map->max_y = 0;
	while (map->map[map->max_y + 1])
		map->max_y++;
	map->max_x = ft_strlen(map->map[0]) - 1;
}
