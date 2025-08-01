/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:20 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:11:15 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

t_point	projection_type(float x, float y, float z, t_data *data)
{
	t_point	new;
	t_point	input;
	float	rotate_x;
	float	rotate_y;

	input = set_point(x, y, z);
	new = set_point(0, 0, 0);
	rotate_x = data->control.rx_end / ROTATE_FACTOR;
	rotate_y = data->control.ry_end / ROTATE_FACTOR;
	if (data->fdf.cam == 0)
	{
		new = projection_iso(input);
	}
	else if (data->fdf.cam == 1)
	{
		new = projection_parallel(input, rotate_x, rotate_y);
	}
	return (new);
}

void	perspective_change(t_fdf *fdf)
{
	if (fdf->cam == 0)
		fdf->cam = 1;
	else
		fdf->cam = 0;
}

t_point	projection_parallel(t_point point, float rotate_x, float rotate_y)
{
	t_point	new;
	t_point	r1;

	r1 = ft_rotate(point.x, point.y, point.z, rotate_x);
	new.x = r1.x;
	if (rotate_y < 0)
		rotate_y = 0;
	if (rotate_y > 1)
		rotate_y = 1;
	new.y = ft_lerp(r1.z * (-1), r1.y, rotate_y);
	new.z = ft_lerp(0, r1.z, rotate_y);
	return (new);
}

t_point	projection_iso(t_point point)
{
	t_point	new;
	float	radian;
	float	degree;

	degree = 30;
	radian = degree * (M_PI / 180);
	new.x = (point.x - point.y) * cos(radian);
	new.y = (point.x + point.y) * sin(radian) - point.z;
	new.z = point.z;
	return (new);
}

/*
sin() and cos() in C takes radians not degree. So we need to convert them
degree = 30;
radian = degree * (M_PI / 180);

Degree
	Degrees are a more familiar, traditional unit of measuring angles.
	A full circle is divided into 360 equal parts, each part being 
	one degree.

Radian
	Radians are the standard unit of angular measure used in mathematics 
	and engineering. One radian is the angle subtended at the center of a 
	circle by an arc whose length is equal to the radius of the circle.

	A full circle is 2π radians (approximately 6.2832).
	This means that 2π radians correspond to 360°.
*/
