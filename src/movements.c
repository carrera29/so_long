
#include "so_long.h"

void	move_up(t_mov *mov, t_map *map, t_data *data)
{
	char	**p;

	put_imagine(map, map->x, map->y, "./xpm_img/p_up1.xpm");
	p = map->map[(map->y / 50) - 1][map->x / 50];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->y -= 50;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	put_imagine(map, map->x, map->y, "./xpm_img/p_up2.xpm");
}

void	move_down(t_mov *mov, t_map *map, t_data *data)
{
	char	**p;

	put_imagine(map, map->x, map->y, "./xpm_img/p_dw1.xpm");
	p = map->map[(map->y / 50) + 1][map->x / 50];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->y += 50;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	put_imagine(map, map->x, map->y, "./xpm_img/p_dw2.xpm");
}

void	move_right(t_mov *mov, t_map *map, t_data *data)
{
	char	**p;

	put_imagine(map, map->x, map->y, "./xpm_img/p_rg1.xpm");
	p = map->map[map->y / 50][(map->x / 50) + 1];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->x += 50;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	put_imagine(map, map->x, map->y, "./xpm_img/p_rg2.xpm");
}

void	move_left(t_mov *mov, t_map *map, t_data *data)
{
	char	**p;

	put_imagine(map, map->x, map->y, "./xpm_img/p_lf1.xpm");
	p = map->map[map->y / 50][(map->x / 50) - 1];
	if (p == 'E')
	{
		if (map->c == 0)
			end_game(data);
	}
	else if (p != '1')
	{
		map->x -= 50;
		mov->movements++;
	}
	if (p == 'C')
		map->c++;
	put_imagine(map, map->x, map->y, "./xpm_img/p_lf2.xpm");
}