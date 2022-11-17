/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:28:09 by clcarre           #+#    #+#             */
/*   Updated: 2022/11/17 17:05:52 by clcarrer         ###   ########.fr       */
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

// int	mouse_hook(int keycode)
// {
// 	if (keycode == 4)
// 		write (1, "move up\n", 8);
// 	else if (keycode == 5)
// 		write (1, "move down\n", 10);
// 	else if (keycode == 2)
// 		write (1, "move right\n", 11);
// 	else if (keycode == 1)
// 		write (1, "move left\n", 10);
// 	return (0);
// }

// int	render(t_data *data)
// {
// 	// ft_drawing(data);
// 	return (0);
// }


void	v_init(t_data *data)
{
	data->movements = 0;
	data->map.p = 0;
	data->map.e = 0;
	data->map.c = 0;
	data->map.max_y = 0;
	while (data->map.map[data->map.max_y + 1])
		data->map.max_y++;
	data->map.max_x = ft_strlen(data->map.map[0]) - 1;
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc > 1)
	{
		get_map(&data, argv);
		int i = 0;
		while (data.map.map[i])
			printf("%s\n", data.map.map[i++]);
		v_init(&data);
		checker_map(&data);
		data.ptr = mlx_init();
		data.window = mlx_new_window(data.ptr, (data.map.max_x + 1) * 50, (data.map.max_y + 1) * 50, "New Game!");
		draw_map(&data);
		// // // // mlx_mouse_hook(data.window, mouse_hook, &data);
		mlx_hook(data.window, 2, 1L<<0, key_hook, &data);
		mlx_hook(data.window, 17, 1L<<0, end_game, &data);
		// // // mlx_loop_hook(data.ptr, render, &data);
		mlx_loop(data.ptr);
	}
	return (0);
}
