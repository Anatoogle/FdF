/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:54:34 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:23:55 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	event_transformation(int x, int y, t_control *control)
{
	if (control->alt == true && control->middlem == true)
		update_translation(x, y, control);
	else if (control->alt == true && control->rightm == true)
		update_zoom(x, y, control);
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
