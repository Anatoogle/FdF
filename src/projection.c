/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:56:20 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:28:19 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	projection_type(float x, float y, float z)
{
	t_point	new;
	t_point	input;

	input = set_point(x, y, z);
	new = set_point(0, 0, 0);
	new = projection_iso(input);
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
