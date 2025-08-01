/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:54:34 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:11:17 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

int	event_transformation(int x, int y, t_control *control)
{
	if (control->alt == true && control->middlem == true)
		update_translation(x, y, control);
	else if (control->alt == true && control->leftm == true)
		update_rotation(x, y, control);
	else if (control->alt == true && control->rightm == true)
		update_zoom(x, y, control);
	else if (control->alt == false && control->middlem == true)
		update_height(x, y, control);
	return (0);
}

void	update_translation(int x, int y, t_control *control)
{
	if (control->first_value == true)
	{
		control->first_value = false;
		control->px_start = x - control->px_end;
		control->py_start = y - control->py_end;
	}
	control->px_update = x - control->px_start;
	control->py_update = y - control->py_start;
}

void	update_rotation(int x, int y, t_control *control)
{
	if (control->first_value == true)
	{
		control->first_value = false;
		control->rx_start = (x * (-1)) - control->rx_end;
		control->ry_start = y - control->ry_end;
	}
	control->rx_update = (x * (-1)) - control->rx_start;
	control->ry_update = y - control->ry_start;
}

void	update_zoom(int x, int y, t_control *control)
{
	(void)y;
	if (control->first_value == true)
	{
		control->first_value = false;
		control->zoomxy_start = x - control->zoomxy_end;
	}
	control->zoomxy_update = x - control->zoomxy_start;
}

void	update_height(int x, int y, t_control *control)
{
	(void)x;
	if (control->first_value == true)
	{
		control->first_value = false;
		control->zoomz_start = y - control->zoomz_end;
	}
	control->zoomz_update = y - control->zoomz_start;
}
