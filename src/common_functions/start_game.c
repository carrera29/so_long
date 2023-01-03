/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:41 by clcarrer          #+#    #+#             */
/*   Updated: 2022/12/30 11:16:21 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		exit_game(data);
	return (0);
}

void	check_file(t_data *data, char **argv)
{
	size_t	i;

	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (ft_strncmp(&argv[1][i - 4], ".ber", 4) != 0)
		control_error(data, 8);
}

void	get_map(t_data *data, char **argv)
{
	check_file(data, argv);
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		exit (write(1, "fd error\n", 10));
	data->map.add_line = NULL;
	data->map.line = "";
	while (data->map.line)
	{
		data->map.line = get_next_line(data->fd);
		if (data->map.line == NULL || data->map.line[0] == '\n')
			break ;
		data->map.add_line = ft_strjoin(data->map.add_line, data->map.line);
		free(data->map.line);
	}
	free (data->map.line);
	data->map.map = ft_split(data->map.add_line, '\n');
	free (data->map.add_line);
	close(data->fd);
}
