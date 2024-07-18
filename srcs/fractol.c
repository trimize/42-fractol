/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:40:40 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/27 15:20:59 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render_comp(t_data *data, double pr, double pi)
{
	double	smooth_value;

	smooth_value = 0.0;
	if (data->set == 0)
		smooth_value = mandelbrot(pr, pi, data);
	else if (data->set == 1)
		smooth_value = julia(pr, pi, data);
	else if (data->set == 2)
		smooth_value = burning_ship(pr, pi, data);
	if (smooth_value < data->max_iteration)
	{
		data->hue = smooth_value / data->max_iteration * 360.0 + data->inccolor;
		data->saturation = 1.0 + data->psych;
		data->lightness = 0.5;
		hsl_to_rgb(data);
	}
	else
	{
		data->color_r = 0;
		data->color_g = 0;
		data->color_b = 0;
	}
}

void	render(t_data *data)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = ((double)x - WIDTH / 2.0) * (4.0 / WIDTH)
				/ data->zoom + data->center_x + data->right + data->left;
			pi = ((double)y - HEIGHT / 2.0) * (4.0 / HEIGHT)
				/ data->zoom + data->center_y + data->up + data->down;
			render_comp(data, pr, pi);
			data->image_data[y * WIDTH + x] = (data->color_r << 16)
				| (data->color_g << 8) | data->color_b;
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(&data, argv, argc);
	mlx_hook(data.mlx_win, 17, 1L << 5, &close_button, &data);
	mlx_key_hook(data.mlx_win, &keyboard_controls, &data);
	mlx_mouse_hook(data.mlx_win, &mouse_event, &data);
	render(&data);
	mlx_loop(data.mlx);
	return (0);
}
