/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_update_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:11:56 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:11:20 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

t_offsetfactor	update_offset(t_control *control)
{
	t_offsetfactor	of;

	of.mxy = (control->zoomxy_update / ZOOMXY_FACTOR) + ZOOMXY_DEFAULT;
	of.mz = (((control->zoomz_update / ZOOMZ_FACTOR) * (-1)) + ZOOMZ_DEFAULT)
		* of.mxy;
	of.ox = control->px_update + WINDOW_WIDTH / 2;
	of.oy = control->py_update + WINDOW_HEIGHT / 2;
	return (of);
}

void	update_transformation(t_control *control)
{
	if (control->alt == true && control->middlem == true)
	{
		control->px_end = control->px_update;
		control->py_end = control->py_update;
	}
	else if (control->alt == true && control->rightm == true)
		control->zoomxy_end = control->zoomxy_update;
	else if (control->alt == false && control->middlem == true)
		control->zoomz_end = control->zoomz_update;
	else if (control->alt == true && control->leftm == true)
	{
		control->rx_end = control->rx_update;
		control->ry_end = control->ry_update;
	}
}

// https://www.youtube.com/watch?v=8GrdqAizcfU
t_point	ft_rotate(float x, float y, float z, float rotate)
{
	t_point	new;

	new.x = (x * cos(rotate)) - (y * sin(rotate));
	new.y = (x * sin(rotate)) + (y * cos(rotate));
	new.z = z;
	return (new);
}

t_point	ft_center(int x, int y, int z, t_fdf *fdf)
{
	t_point	new;

	new.x = x - fdf->row / 2;
	new.y = y - fdf->col / 2;
	new.z = z;
	return (new);
}
