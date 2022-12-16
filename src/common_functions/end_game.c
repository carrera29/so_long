/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:32:41 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/16 15:58:09 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_data *data)
{
	int	i;

	i = 0;
	clean_map(data);
	while (i <= data->map.f)
		free(data->map.enemy[i++]);
	close(data->fd);
	mlx_destroy_window(data->ptr, data->window);
	exit (EXIT_SUCCESS);
}

void	end_game(t_data *data, int i)
{
	char	*text;

	mlx_clear_window(data->ptr, data->window);
	if (i == 0)
	{
		mlx_string_put(data->ptr, data->window, (data->map.max_x * 64) / 2,
			(data->map.max_y * 64) / 2 - 64, RED, "You won!");
		text = ft_strjoin(ft_itoa(data->movements), " moves");
		mlx_string_put(data->ptr, data->window, (data->map.max_x * 64) / 2,
			(data->map.max_y * 64) / 2, RED, text);
		free(text);
	}
	else
		mlx_string_put(data->ptr, data->window, (data->map.max_x * 64) / 2,
			(data->map.max_y * 64) / 2 - 64, RED, "Game over");
}
