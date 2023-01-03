/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:28:09 by clcarre           #+#    #+#             */
/*   Updated: 2022/12/30 11:38:52 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		get_map(&data, argv);
		v_init(&data);
		checker_map(&data);
		if (data.map.f > 0)
			control_error(&data, 7);
		get_map(&data, argv);
		data.ptr = mlx_init();
		data.window = mlx_new_window(data.ptr, \
			(data.map.max_x + 1) * 64, (data.map.max_y + 1) * 64, "New Game!");
		first_draw_map(&data);
		mlx_hook(data.window, 2, 1L << 0, key_hook, &data);
		mlx_hook(data.window, 17, 1L << 0, exit_game, &data);
		mlx_loop(data.ptr);
	}
	return (0);
}
