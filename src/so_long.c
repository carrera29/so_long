/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:28:09 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/28 15:53:22 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_data *data)
{
	clean_map(data);
	mlx_destroy_window(data->ptr, data->window);
	exit (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == M_UP || keycode == A_UP)
		move_up(data);
	else if (keycode == M_DOWN || keycode == A_DOWN)
		move_down(data);
	else if (keycode == M_RIGHT || keycode == A_RIGHT)
		move_right(data);
	else if (keycode == M_LEFT || keycode == A_LEFT)
		move_left(data);
	if (keycode == 53)
		end_game(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc > 1)
	{
		get_map(&data, argv);
		v_init(&data);
		checker_map(&data);
		get_map(&data, argv);
		data.ptr = mlx_init();
		data.window = mlx_new_window(data.ptr, (data.map.max_x + 1) * 70, (data.map.max_y + 1) * 60, "New Game!");
		draw_map(&data);
		mlx_hook(data.window, 2, 1L<<0, key_hook, &data);
		mlx_hook(data.window, 17, 1L<<0, end_game, &data);
		mlx_loop(data.ptr);
	}
	return (0);
}
