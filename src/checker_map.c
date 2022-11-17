/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:32:24 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/17 17:43:57 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	find_the_exit(t_data *data, int y, int x, int c)
// {
// 	if ((unsigned long)y != data->map.max_y && (unsigned long)x != data->map.max_x)
// 	{
// 		if (data->map.map[y + 1][x] != '1')
// 		{
// 			if (data->map.map[y + 1][x] == 'C')
// 				c--;
// 			if ((data->map.map[y + 1][x]) == 'E' && (c == 0))
// 				return (0);
// 			find_the_exit(data, (y + 1), x, c);
// 		}
// 		if (data->map.map[y][x + 1] != '1')
// 		{
// 			if (data->map.map[y][x + 1] == 'C')
// 				c--;
// 			if ((data->map.map[y][x + 1]) == 'E' && (c == 0))
// 				return (0);
// 			find_the_exit(data, y, (x + 1), c);
// 		}
// 		if (data->map.map[y - 1][x] != '1')
// 		{
// 			if (data->map.map[y - 1][x] == 'C')
// 				c--;
// 			if ((data->map.map[y - 1][x]) == 'E' && (c == 0))
// 				return (0);
// 			find_the_exit(data, (y - 1), x, c);
// 		}
// 		if (data->map.map[y][x - 1] != '1')
// 		{
// 			if (data->map.map[y][x - 1] == 'C')
// 				c--;
// 			if ((data->map.map[y][x - 1]) == 'E' && (c == 0))
// 				return (0);
// 			find_the_exit(data, y, (x - 1), c);
// 		}
// 	}
// 	return (1);
// }

void	check_char_to_char(t_data *data)
{
	int	y;
	int x;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'P')
			{
				data->map.p++;
				data->map.p_x = x;
				data->map.p_y = y;
			}
			else if (data->map.map[y][x] == 'E')
			{	
				data->map.e_x = x;
				data->map.e_y = y;
				data->map.e++;
			}
			else if (data->map.map[y][x] == 'C')
				data->map.c++;
			x++;
		}
		y++;
	}
}

void	checker_map(t_data *data)
{
	int i;
	
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
	if (data->map.c < 1 || data->map.e < 1)
		control_error(data, 3);
	// if (find_the_exit(data, data->map.p_y, data->map.p_x, data->map.c) == 1)
	// 	control_error(data, 4);
}
