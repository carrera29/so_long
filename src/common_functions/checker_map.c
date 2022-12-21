/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:32:24 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/21 09:45:22 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	element_count(t_data *data, char c, int y, int x)
{
	if (c == 'P')
	{
		data->map.p++;
		data->map.p_x = x;
		data->map.p_y = y;
	}
	else if (c == 'E')
		data->map.e++;
	else if (c == 'C')
		data->map.c++;
	else if (c == 'F')
		data->map.f++;
	else if (c != '0' && c != '1')
		control_error(data, 6);
}

void	check_char_to_char(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			element_count(data, data->map.map[y][x], y, x);
			x++;
		}
		y++;
	}
}

void	coordenates_x_y(t_data *data, int y, int x)
{
	if ((y <= 0) || (y >= (int)data->map.max_y)
		|| (x <= 0) || (x >= (int)data->map.max_x))
		control_error(data, 1);
}

int	find_the_exit(t_data *data, int y, int x, int collectives)
{
	static int	c;
	static int	e;

	if (data->map.map[y][x] == 'C')
		c += 1;
	else if (data->map.map[y][x] == 'E')
		e += 1;
	data->map.map[y][x] = '.';
	if ((data->map.map[y + 1][x] != '1') && (data->map.map[y + 1][x] != '.'))
		(coordenates_x_y(data, y + 1, x), find_the_exit(data, (y + 1), x, c));
	if ((data->map.map[y][x + 1] != '1') && (data->map.map[y][x + 1] != '.'))
		(coordenates_x_y(data, y, x + 1), find_the_exit(data, y, (x + 1), c));
	if ((data->map.map[y - 1][x] != '1') && (data->map.map[y - 1][x] != '.'))
		(coordenates_x_y(data, y - 1, x), find_the_exit(data, (y - 1), x, c));
	if ((data->map.map[y][x - 1] != '1') && (data->map.map[y][x - 1] != '.'))
		(coordenates_x_y(data, y, x - 1), find_the_exit(data, y, (x - 1), c));
	if (c == collectives && e > 0)
		return (1);
	return (0);
}

void	checker_map(t_data *data)
{
	int	i;

	i = 1;
	while (data->map.map[i])
	{
		if (data->map.max_x != ft_strlen(data->map.map[i++]) - 1)
			control_error(data, 1);
	}
	if (data->map.max_x == data->map.max_y)
		control_error(data, 1);
	check_char_to_char(data);
	if (data->map.p != 1)
		control_error(data, 2);
	if (data->map.c < 1)
		control_error(data, 3);
	if (data->map.e != 1)
		control_error(data, 4);
	if (find_the_exit(data, data->map.p_y, data->map.p_x, data->map.c) == 0)
		control_error(data, 1);
	clean_map(data);
}
