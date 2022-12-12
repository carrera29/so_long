/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:16:56 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/14 09:16:56 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_the_squid(t_data *data)
{
	mlx_clear_window(data->ptr, data->window);
	mlx_string_put(data->ptr, data->window, data->map.max_x / 2 * 64, \
		data->map.max_y / 2 * 64, RED, "Game over");
	return ;
	// end_game(data);
}

void	enemy_mov(t_data *data, int y, int x, int i)
{
	static int	dir;

	if (dir == 0 && data->map.map[y - 1][x] == 'P')
		kill_the_squid(data);
	else if (dir == 0 && data->map.map[y - 1][x] == '0')
	{
		data->map.map[y - 1][x] = 'F';
		data->map.map[y][x] = '0';
		data->map.enemy[i][0] = y - 1;
	}
	else
		dir = 1;
	if (dir == 0 && data->map.map[y + 1][x] == 'P')
		kill_the_squid(data);
	else if (dir == 1 && data->map.map[y + 1][x] == '0')
	{
		data->map.map[y + 1][x] = 'F';
		data->map.map[y][x] = '0';
		data->map.enemy[i][0] = y + 1;
	}
	else
		dir = 0;
}

void	move_enemies(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < data->map.f)
	{
		y = data->map.enemy[i][0];
		x = data->map.enemy[i][1];
		enemy_mov(data, y, x, i);
		i++;
	}
}
