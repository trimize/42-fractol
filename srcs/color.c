/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teorimize <teorimize@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:12:16 by teorimize         #+#    #+#             */
/*   Updated: 2023/12/18 16:20:02 by teorimize        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	hsl_to_rgb2(t_data *data, double c, double x, double m)
{
	if (data->hue < 180.0)
	{
		data->g = c;
		data->b = x;
	}
	else if (data->hue < 240.0)
	{
		data->g = x;
		data->b = c;
	}
	else if (data->hue < 300.0)
	{
		data->r = x;
		data->b = c;
	}
	else
	{
		data->r = c;
		data->b = x;
	}
	data->color_r = (int)((data->r + m) * 255);
	data->color_g = (int)((data->g + m) * 255);
	data->color_b = (int)((data->b + m) * 255);
}

void	hsl_to_rgb(t_data *data)
{
	double	c;
	double	x;
	double	m;

	data->r = 0.0;
	data->g = 0.0;
	data->b = 0.0;
	c = (1.0 - fabs(2.0 * data->lightness - 1.0)) * data->saturation;
	x = c * (1.0 - fabs(fmod(data->hue / 60.0, 2.0) - 1.0));
	m = data->lightness - c / 2.0;
	if (data->hue < 60.0)
	{
		data->r = c;
		data->g = x;
	}
	else if (data->hue < 120.0)
	{
		data->r = x;
		data->g = c;
	}
	hsl_to_rgb2(data, c, x, m);
}
