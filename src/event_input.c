/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:08:57 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:57:07 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	event_keypress(int button, t_data *data)
{
	if (button == XK_Escape)
		close_window(data);
	if (button == XK_Alt_L)
	{
		data->control.alt = true;
		data->control.first_value = true;
	}
	return (0);
}

int	event_keyrelease(int button, t_control *control)
{
	if (button == XK_Alt_L)
	{
		control->alt = false;
	}
	return (0);
}

int	event_mousepress(int button, int x, int y, t_control *control)
{
	(void)x;
	(void)y;
	if (button == MOUSE_THIRD_BUTTON)
	{
		control->rightm = true;
		control->first_value = true;
	}
	if (button == MOUSE_RIGHT_BUTTON)
	{
		control->middlem = true;
		control->first_value = true;
	}
	return (0);
}

int	event_mousereleased(int button, int x, int y, t_control *control)
{
	(void)x;
	(void)y;
	if (button == MOUSE_THIRD_BUTTON)
	{
		control->rightm = false;
	}
	if (button == MOUSE_RIGHT_BUTTON)
	{
		control->middlem = false;
	}
	return (0);
}
