/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:31:54 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/27 14:48:15 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_controls_comp2(int keycode, t_data *data)
{
	if (keycode == XK_Up)
	{
		data->up -= 0.7 * data->index_zoom;
		render(data);
	}
	if (keycode == XK_Down)
	{
		data->down += 0.7 * data->index_zoom;
		render(data);
	}
	if (keycode == XK_Control_L)
	{
		data->cx -= 0.01;
		data->cy += 0.01;
		render(data);
	}
	if (keycode == XK_Shift_L)
	{
		data->cx += 0.01;
		data->cy -= 0.01;
		render(data);
	}
	return (0);
}

void	free_ev(t_data *data)
{
	mlx_destroy_image(data->mlx, data->mlx_img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
