
#include "so_long.h"

void	put_imagine(t_map *map, int x, int y, char *patch)
{
	t_data	*data;

	data.img = mlx_xpm_file_to_image(data.ptr, patchyt, &img_width, &img_height);
	mlx_put_image_to_window(data.ptr, data.window, data.img, x, y);
}

void	draw_map(t_map *map)
{
	char	c;
	map->y = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			c = map->map[map->y][map->x];
			if (c == '1')
				put_imagine(map, map->x, map->y, "./xpm_img/wall.xpm");
			else if (c == '0')
				put_imagine(map, map->x, map->y, "./xpm_img/space.xpm");
			else if (c == 'P')
				put_imagine(map, map->x, map->y, "./xpm_img/character.xpm")
			else if (c == 'E')
				put_imagine(map, map->x, map->y, "./xpm_img/exit.xpm")
			else if (c == 'C')
				put_imagine(map, map->x, map->y, "./xpm_img/coin.xpm")
			map->x++;
		}
		map->y++;
	}
}