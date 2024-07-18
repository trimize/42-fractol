/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_sets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:17:27 by teorimize         #+#    #+#             */
/*   Updated: 2024/02/29 18:50:08 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	mandelbrot(double cr, double ci, t_data *data)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	double	a;
	double	b;

	n = 0;
	zr = 0.0;
	zi = 0.0;
	a = 0;
	b = 0;
	while (n < data->max_iteration && (a + b) < 4.0)
	{
		tmp = a - b + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		a = zr * zr;
		b = zi * zi;
		n++;
	}
	if (n == data->max_iteration)
		return (data->max_iteration);
	else
		return (n + 1 - log(log(sqrt(a + b))) / log(2.0));
}

double	julia(double zr, double zi, t_data *f)
{
	int		n;
	double	tmp;
	double	abs_z;

	n = 0;
	while (n < f->max_iteration)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->cx;
		zr = zr * zr - zi * zi + f->cy;
		zi = tmp;
		n++;
	}
	if (n == f->max_iteration)
		return (f->max_iteration);
	else
	{
		abs_z = zr * zr + zi * zi;
		return (n + 1 - log(log(abs_z)) / log(2));
	}
}

double	burning_ship(double cx, double cy, t_data *data)
{
	int		iter;
	double	abs_z;
	double	tmp;
	double	zx;
	double	zy;

	iter = 0;
	zx = 0;
	zy = 0;
	while (iter < data->max_iteration && (zx * zx + zy * zy) < 4.0)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2 * fabs(zx * zy) + cy;
		zx = tmp;
		iter++;
	}
	if (iter == data->max_iteration)
		return (data->max_iteration);
	else
	{
		abs_z = zx * zx + zy * zy;
		return (iter + 1 - log(log(abs_z)) / log(2.0));
	}
}
