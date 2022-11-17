/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarrer <clcarrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:12:41 by clcarrer          #+#    #+#             */
/*   Updated: 2022/11/17 15:15:23 by clcarrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (write(1, "fd error\n", 10));
	data->map.add_line = NULL;
	data->map.line = "";
	while (data->map.line)
	{
		data->map.line = get_next_line(fd);
		if (data->map.line == NULL || data->map.line[0] == '\n')
			break ;
		data->map.add_line = ft_strjoin(data->map.add_line, data->map.line);
		free(data->map.line);
	}
	free (data->map.line);
	data->map.map = ft_split(data->map.add_line, '\n');
}
