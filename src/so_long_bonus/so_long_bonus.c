/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:53:06 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/15 15:48:22 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_data	data;

	atexit(check_leaks);
	data.c = 'b';
	if (argc > 1)
	{
		get_map(&data, argv);
		v_init(&data);
		checker_map(&data);
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
