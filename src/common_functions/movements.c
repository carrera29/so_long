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

void	cycle_counter(t_data *data, char p)
{
	if (p == 'E' && data->map.c == 0)
		end_game(data, 0);
	else if (p == 'F')
		end_game(data, 1);
	else if (p == '0' || p == 'C')
	{
		data->movements++;
		if (p == 'C')
			data->map.c--;
		data->map.map[data->map.p_y][data->map.p_x] = '0';
		draw_water(data, data->map.p_x, data->map.p_y);
	}
}

void	move_up(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y - 1][data->map.p_x];
	if (p != '1')
	{
		cycle_counter(data, p);
		if (p == '0' || p == 'C')
		{
			data->map.p_y--;
			data->map.map[data->map.p_y][data->map.p_x] = 'P';
			if (data->map.f > 0)
				move_enemies(data);
			draw_map(data);
		}
	}
}

void	move_down(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y + 1][data->map.p_x];
	if (p != '1')
	{
		cycle_counter(data, p);
		if (p == '0' || p == 'C')
		{
			data->map.p_y++;
			data->map.map[data->map.p_y][data->map.p_x] = 'P';
			if (data->map.f > 0)
				move_enemies(data);
			draw_map(data);
		}
	}
}

void	move_right(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y][data->map.p_x + 1];
	if (p != '1')
	{
		cycle_counter(data, p);
		if (p == '0' || p == 'C')
		{
			data->map.p_x++;
			data->map.map[data->map.p_y][data->map.p_x] = 'P';
			if (data->map.f > 0)
				move_enemies(data);
			draw_map(data);
		}
	}
}

void	move_left(t_data *data)
{
	char	p;

	p = data->map.map[data->map.p_y][data->map.p_x - 1];
	if (p != '1')
	{
		cycle_counter(data, p);
		if (p == '0' || p == 'C')
		{
			data->map.p_x--;
			data->map.map[data->map.p_y][data->map.p_x] = 'P';
			if (data->map.f > 0)
				move_enemies(data);
			draw_map(data);
		}
	}
}
