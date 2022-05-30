/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:28:09 by clcarre           #+#    #+#             */
/*   Updated: 2022/05/30 14:19:16 by clcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	draw_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*window;
	t_data	img;
	int		x;
	int		y;
	int		color;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 960, 540, "Hello World!");
	img.img = mlx_new_image(mlx, 960, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 100;
	y = 100;
	color = 0x550000FF;
	while (x < 400)
	{
		y = 100;
		while (y < 400)
			draw_pixel(&img, x, y++, color);
		x++;
	}
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
}
