/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:14:32 by trimize           #+#    #+#             */
/*   Updated: 2024/02/27 14:40:43 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define HEIGHT 920
# define WIDTH 920
# define ZOOM_FACTOR 1.5
# define PALETTE_SIZE 256
# define MIN_ZOOM 0.0000000000000000001
# define MAX_ZOOM 10000000000000000000.0
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_data
{
	long double	zoom;
	void		*mlx_img;
	void		*mlx_win;
	void		*mlx;
	double		r;
	double		g;
	double		b;
	double		hue;
	double		saturation;
	double		lightness;
	double		center_x;
	double		center_y;
	double		inccolor;
	double		psych;
	double		right;
	double		left;
	double		up;
	double		down;
	double		index_zoom;
	double		cx;
	double		cy;
	int			color_r;
	int			max_iteration;
	int			color_g;
	int			color_b;
	int			*image_data;
	int			set;
}				t_data;

int		keyboard_controls(int keycode, t_data *data);
int		close_button(t_data *data);
int		mouse_event(int keycode, int x, int y, t_data *data);
int		keyboard_controls_comp2(int keycode, t_data *data);
void	free_ev(t_data *data);
void	render(t_data *data);
void	init(t_data *data, char **argv, int argc);
void	hsl_to_rgb(t_data *data);
void	hsl_to_rgb2(t_data *data, double c, double x, double m);
void	data_init(t_data *data);
void	init_img(t_data *data);
void	msg(int argc, char **argv, t_data *data);
void	msg_controls(void);
double	random_range(double min, double max, double seed);
double	mandelbrot(double cr, double ci, t_data *data);
double	julia(double zr, double zi, t_data *f);
double	burning_ship(double cx, double cy, t_data *data);

#endif
