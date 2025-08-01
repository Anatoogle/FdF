/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_update.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:11:56 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:22:51 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
}

t_point	ft_center(int x, int y, int z, t_fdf *fdf)
{
	t_point	new;

	new.x = x - fdf->row / 2;
	new.y = y - fdf->col / 2;
	new.z = z;
	return (new);
}
