/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_plus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:23:12 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:11:24 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_plus.h"

float	ft_lerp(float a, float b, float f)
{
	return (a + f * (b - a));
}

t_point	set_point(float x, float y, float z)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

void	init_control(t_control *control)
{
	control->alt = false;
	control->leftm = false;
	control->middlem = false;
	control->rightm = false;
	control->first_value = false;
	control->reset = false;
	control->px_start = 0;
	control->px_update = 0;
	control->px_end = 0;
	control->py_start = 0;
	control->py_update = 0;
	control->py_end = 0;
	control->rx_start = 0.0;
	control->rx_update = 0.0;
	control->rx_end = 0.0;
	control->zoomxy_start = 0.0;
	control->zoomxy_update = 0.0;
	control->zoomxy_end = 0.0;
	control->zoomz_start = 0.0;
	control->zoomz_update = 0.0;
	control->zoomz_end = 0.0;
	control->ry_start = 0.0;
	control->ry_update = 0.0;
	control->ry_end = 0.0;
}

void	init_fdf(t_fdf *fdf)
{
	fdf->row = 0;
	//fdf->col = 0;
	fdf->cam = 0;
	fdf->edge_count = 0;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->addr = NULL;
	fdf->iar = NULL;
	fdf->vertices = NULL;
	fdf->edges = NULL;
	fdf->bpp = 0;
	fdf->line_len = 0;
	fdf->endian = 0;
}
