/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:32:41 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/30 11:45:32 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_data *data)
{
	int	i;

	mlx_clear_window(data->ptr, data->window);
	clean_map(data);
	if (data->map.f > 0)
	{
		i = 0;
		while (i < data->map.f)
		{
			free(data->map.enemy[i]);
			i++;
		}
	}
	mlx_destroy_window(data->ptr, data->window);
	exit (EXIT_SUCCESS);
}

void	end_game(t_data *data, int i)
{
	mlx_clear_window(data->ptr, data->window);
	if (i == 0)
		write(1, "You won!\n", 10);
	else
		write(1, "Game over!\n", 12);
	exit_game(data);
}
