/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:02:15 by trimize           #+#    #+#             */
/*   Updated: 2024/02/27 14:49:18 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	keyboard_controls_comp(int keycode, t_data *data)
{
	if (keycode == XK_w)
	{
		data->max_iteration -= 100;
		render(data);
	}
	if (keycode == XK_e)
	{
		data->inccolor += 10;
		data->psych += 100.0;
		render(data);
	}
	if (keycode == XK_r)
	{
		data->psych = 0.0;
		render(data);
	}
	if (keycode == XK_Right)
	{
		data->right += 0.7 * data->index_zoom;
		render(data);
	}
	return (0);
}

int	keyboard_controls(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		free_ev(data);
		(ft_printf("Process finished !\n"), exit(0));
	}
	if (keycode == XK_space)
	{
		data->inccolor += 5;
		if (data->inccolor == 360)
			data->inccolor -= 360;
		render(data);
	}
	if (keycode == XK_q)
	{
		data->max_iteration += 100;
		render(data);
	}
	if (keycode == XK_Left)
	{
		data->left -= 0.7 * data->index_zoom;
		render(data);
	}
	keyboard_controls_comp(keycode, data);
	keyboard_controls_comp2(keycode, data);
	return (0);
}

int	close_button(t_data *data)
{
	free_ev(data);
	(ft_printf("Process finished !\n"), exit(0));
	return (0);
}

void	mouse_event_comp(t_data *data, int x, int y)
{
	double	cursor_re;
	double	cursor_im;
	double	new_cursor_re;
	double	new_cursor_im;

	cursor_re = (x - WIDTH / 2.0) * (4.0 / WIDTH)
		/ data->zoom + data->center_x;
	cursor_im = (y - HEIGHT / 2.0) * (4.0 / HEIGHT)
		/ data->zoom + data->center_y;
	data->zoom /= ZOOM_FACTOR;
	new_cursor_re = (x - WIDTH / 2.0) * (4.0 / WIDTH)
		/ data->zoom + data->center_x;
	new_cursor_im = (y - HEIGHT / 2.0) * (4.0 / HEIGHT)
		/ data->zoom + data->center_y;
	data->center_x += cursor_re - new_cursor_re;
	data->center_y += cursor_im - new_cursor_im;
	data->index_zoom *= 1.4;
	render(data);
}

int	mouse_event(int keycode, int x, int y, t_data *data)
{
	double	cursor_re;
	double	cursor_im;
	double	new_cursor_re;
	double	new_cursor_im;

	if (keycode == MOUSE_WHEEL_DOWN && data->zoom > MIN_ZOOM)
	{
		cursor_re = (x - WIDTH / 2.0) * (4.0 / WIDTH)
			/ data->zoom + data->center_x;
		cursor_im = (y - HEIGHT / 2.0) * (4.0 / HEIGHT)
			/ data->zoom + data->center_y;
		data->zoom *= ZOOM_FACTOR;
		new_cursor_re = (x - WIDTH / 2.0) * (4.0 / WIDTH)
			/ data->zoom + data->center_x;
		new_cursor_im = (y - HEIGHT / 2.0) * (4.0 / HEIGHT)
			/ data->zoom + data->center_y;
		data->center_x += cursor_re - new_cursor_re;
		data->center_y += cursor_im - new_cursor_im;
		data->index_zoom /= 1.4;
		render(data);
	}
	if (keycode == MOUSE_WHEEL_UP && data->zoom < MAX_ZOOM)
		mouse_event_comp(data, x, y);
	return (0);
}
