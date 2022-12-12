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

void	move_up(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y - 1][data->map.p_x];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->map.map[data->map.p_y][data->map.p_x] = '0';
		draw_water(data, data->map.p_x, data->map.p_y);
		data->map.p_y--;
		data->map.map[data->map.p_y][data->map.p_x] = 'P';
		data->movements++;
		if (p == 'C')
			data->map.c--;
	}
	draw_map(data);
}

void	move_down(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y + 1][data->map.p_x];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->map.map[data->map.p_y][data->map.p_x] = '0';
		draw_water(data, data->map.p_x, data->map.p_y);
		data->map.p_y++;
		data->map.map[data->map.p_y][data->map.p_x] = 'P';
		data->movements++;
		if (p == 'C')
			data->map.c--;
	}
	draw_map(data);
}

void	move_right(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y][data->map.p_x + 1];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->map.map[data->map.p_y][data->map.p_x] = '0';
		draw_water(data, data->map.p_x, data->map.p_y);
		data->map.p_x++;
		data->map.map[data->map.p_y][data->map.p_x] = 'P';
		data->movements++;
		if (p == 'C')
			data->map.c--;
	}
	draw_map(data);
}

void	move_left(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y][data->map.p_x - 1];
	if (p == 'E')
	{
		if (data->map.c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		data->map.map[data->map.p_y][data->map.p_x] = '0';
		draw_water(data, data->map.p_x, data->map.p_y);
		data->map.p_x--;
		data->map.map[data->map.p_y][data->map.p_x] = 'P';
		data->movements++;
		if (p == 'C')
			data->map.c--;
	}
	draw_map(data);
}
