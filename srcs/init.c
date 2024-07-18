/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:07:51 by trimize           #+#    #+#             */
/*   Updated: 2024/02/27 15:21:10 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	data_init(t_data *data)
{
	data->mlx = NULL;
	data->mlx_img = NULL;
	data->mlx_win = NULL;
	data->zoom = 1.0;
	data->r = 0.0;
	data->g = 0.0;
	data->b = 0.0;
	data->center_x = 0.0;
	data->center_y = 0.0;
	data->inccolor = 0;
	data->max_iteration = 50;
	data->psych = 0.0;
	data->right = 0.0;
	data->left = 0.0;
	data->up = 0.0;
	data->down = 0.0;
	data->index_zoom = 1.0;
}

void	init_img(t_data *data)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;

	data->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->mlx_img)
		(ft_printf("Error initialising the image\n"), exit(-1));
	data->image_data = (int *)mlx_get_data_addr
		(data->mlx_img, &pixel_bits, &line_bytes, &endian);
	if (!data->image_data)
		(ft_printf("Error getting image data address\n"), exit(-1));
}

void	init(t_data *data, char **argv, int argc)
{
	msg(argc, argv, data);
	msg_controls();
	data_init(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		(ft_printf("Error connecting to mlx\n"), exit(-1));
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	if (!data->mlx_win)
		(ft_printf("Error creating mlx window\n"), exit(-1));
	init_img(data);
}
