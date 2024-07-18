/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trimize <trimize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:13:21 by teorimize         #+#    #+#             */
/*   Updated: 2024/07/18 14:17:46 by trimize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	msg_comp(char **argv, t_data *data)
{
	if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) != 0
		&& ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) != 0
		&& ft_strncmp(argv[1], "Burning Ship", ft_strlen("Burning Ship")))
	{
		ft_printf
			("\n██████████████████████████████████████████████████████\n\n");
		ft_printf("\n\nSet unknown, here is what's expected :");
		ft_printf("\n\t./fractol FRACTAL_SET\n\n");
		ft_printf("\n\n\tAccepted sets : 'Mandelbrot', 'Julia'\n\n");
		ft_printf
			("\tFor Julia, two value are expected both between -2 and 2\n");
		ft_printf
			("\n\n██████████████████████████████████████████████████████\n\n");
		exit(-1);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		data->set = 0;
}

void	msg_comp2(int argc, char **argv, t_data *data)
{
	if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0 && argc == 4)
	{
		if (ft_atof(argv[2]) < -2 || ft_atof(argv[2]) > 2
			|| ft_atof(argv[3]) < -2 || ft_atof(argv[3]) > 2)
			(ft_printf("Both values are expected between -2 ands 2"), exit(-1));
		data->cx = ft_atof(argv[2]);
		data->cy = ft_atof(argv[3]);
		data->set = 1;
	}
	else if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0 && argc != 4)
	{
		ft_printf
			("\n██████████████████████████████████████████████████████\n\n");
		ft_printf("\nFalse number of arguments, here is what's expected :\n");
		ft_printf("\n\t./fractol Julia\n\n");
		ft_printf
			("\tTwo value are expected both between -2 and 2\n");
		ft_printf
			("\n\n██████████████████████████████████████████████████████\n\n");
		exit(-1);
	}
}

void	msg(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc > 4)
	{
		ft_printf
			("\n██████████████████████████████████████████████████████\n\n");
		ft_printf("\nFalse number of arguments, here is what's expected :\n");
		ft_printf("\n\t./fractol FRACTAL_SET\n\n");
		ft_printf("\tAccepted sets :'Mandelbrot', 'Julia', 'Burning Ship'\n\n");
		ft_printf
			("\tFor Julia, two value are expected both between -2 and 2\n");
		ft_printf
			("\n\n██████████████████████████████████████████████████████\n\n");
		exit(-1);
	}
	else if (ft_strncmp(argv[1], "Burning Ship", ft_strlen("Burning Ship"))
		== 0)
		data->set = 2;
	msg_comp2(argc, argv, data);
	msg_comp(argv, data);
}

void	msg_controls(void)
{
	ft_printf("\n██████████████████████████████████████████████████████\n\n");
	ft_printf("Here are the available controls :\n\n");
	ft_printf("Q : Increase Precision\n");
	ft_printf("W : Decrease Precision\n");
	ft_printf("E : Psychedelic craziness\n");
	ft_printf("R : Remove psychedelic effect\n");
	ft_printf("Escape : Close the program\n");
	ft_printf("Space : Change colors\n");
	ft_printf("Up : Go up\n");
	ft_printf("Down : Go down\n");
	ft_printf("Right : Go right\n");
	ft_printf("Left : Go left\n");
	ft_printf("Left Control : Change julia set form to the left\n");
	ft_printf("Left shift : Change julia set form to the right\n");
	ft_printf("Scroll : Zoom in and out");
	ft_printf("\n\n██████████████████████████████████████████████████████\n\n");
}
