/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:32:24 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/12 12:00:44 by clcarrer         ###   ########.fr       */
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
	if (data->map.f > 0)
		control_enemies(data);
}

void	copy_map(t_data *data)
{
	int	i;

	data->map.check_map = malloc(sizeof(char **) * ((int)data->map.max_y + 2));
	if (!data->map.check_map)
		clean_map(data);
	i = 0;
	while (i <= (int)data->map.max_y)
	{
		data->map.check_map[i] = ft_strdup(data, data->map.map[i]);
		if (!data->map.check_map[i])
		{
			clean_check_map(data, i);
			control_error(data, 5);
		}
		i++;
	}
	data->map.check_map[i] = malloc(sizeof(char));
	data->map.check_map[i] = NULL;
}

int	find_the_exit(char **map, int y, int x, int collectives)
{
	static int	c;
	static int	e;

	if (map[y][x] == 'C')
		c += 1;
	else if (map[y][x] == 'E')
		e += 1;
	map[y][x] = '.';
	if ((map[y + 1][x] != '1') && (map[y + 1][x] != '.'))
		find_the_exit(map, (y + 1), x, c);
	if ((map[y][x + 1] != '1') && (map[y][x + 1] != '.'))
		find_the_exit(map, y, (x + 1), c);
	if ((map[y - 1][x] != '1') && (map[y - 1][x] != '.'))
		find_the_exit(map, (y - 1), x, c);
	if ((map[y][x - 1] != '1') && (map[y][x - 1] != '.'))
		find_the_exit(map, y, (x - 1), c);
	if (c == collectives && e > 0)
		return (0);
	return (1);
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
	if (data->map.c < 1 || data->map.e != 1)
		control_error(data, 3);
	copy_map(data);
	if (find_the_exit(data->map.check_map, \
		data->map.p_y, data->map.p_x, data->map.c) == 1)
	{	
		clean_check_map(data, data->map.max_y);
		control_error(data, 1);
	}
	clean_check_map(data, data->map.max_y);
}
