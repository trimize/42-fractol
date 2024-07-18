/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teorimize <teorimize@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:06:54 by teorimize         #+#    #+#             */
/*   Updated: 2023/12/14 19:53:51 by teorimize        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	random_range(double min, double max, double seed)
{
	seed = fmod(seed * 1103515245 + 12345, RAND_MAX);
	return (min + (seed / RAND_MAX) * (max - min));
}
