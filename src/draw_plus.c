/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:03:02 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:10:30 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_plus.h"

void	draw_fdf_setup(t_data *data)
{
	t_offsetfactor	of;
	int				i;
	t_edge			e;

	of = update_offset(&data->control);
	update_transformation(&data->control);

	i = 0;
	while (i < data->fdf.edge_count)
	{
		e = data->fdf.edges[i];

		draw_fdf(data, of, e.from, e.to);
		i++;
	}
}

void	draw_fdf(t_data *data, t_offsetfactor of, int a, int b)
{
	t_point	p1;
	t_point	p2;
	t_point	n1;
	t_point	n2;

	t_vertex v1 = data->fdf.vertices[a];
	t_vertex v2 = data->fdf.vertices[b];
	
	
	p1 = projection_type(v1.pos.x * of.mxy, v1.pos.y * of.mxy, v1.pos.z * of.mz, data);
	p2 = projection_type(v2.pos.x * of.mxy, v2.pos.y * of.mxy, v2.pos.z * of.mz, data);
	n1 = set_point(p1.x + of.ox, p1.y + of.oy, v1.pos.z);
	n2 = set_point(p2.x + of.ox, p2.y + of.oy, v2.pos.z);

	draw_line_setup(&data->fdf, n1, n2);

}

void	draw_line_setup(t_fdf *fdf, t_point start, t_point end)
{
	t_point	d;
	t_point	s;

	d.x = (float)abs((int)end.x - (int)start.x);
	d.y = (float)abs((int)end.y - (int)start.y);
	if (start.x < end.x)
		s.x = 1;
	else
		s.x = -1;
	if (start.y < end.y)
		s.y = 1;
	else
		s.y = -1;
	draw_line_loop(fdf, d, s, start);
}

void	draw_line_loop(t_fdf *fdf, t_point d, t_point s, t_point start)
{
	int	count;

	if (d.x > d.y)
		count = d.x;
	else
		count = d.y;
	while (count >= 0)
	{
		put_pixel(fdf, (int)start.x, (int)start.y, 0xFFFFFF);
		if (d.x < d.y)
		{
			start.x = start.x + ((1 * ((float)d.x / (float)d.y)) * s.x);
			start.y = start.y + (1 * s.y);
		}
		else
		{
			start.x = start.x + (1 * s.x);
			start.y = start.y + ((1 * ((float)d.y / (float)d.x)) * s.y);
		}
		count--;
	}
}

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		dst = fdf->addr + (y * fdf->line_len + x * (fdf->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

/*
Draw Line Algorithm
	- DDA (Digital Differential Analyzer)
	- Bresenham’s algorithm
*/

/*
put_pixel
	This function is used to set a pixel at a specific (x, y) location in
	the image, using a specified color.	It works by manipulating the raw
	pixel data stored in fdf->addr (the address of the image data) and
	calculating the correct position for the given pixel.

	Memory Calculation:

		y * fdf->line_len: 	This moves the pointer to the correct row of
							the image, since fdf->line_len tells us how
							many bytes each row occupies.

		x * (fdf->bpp / 8): This moves the pointer to the correct column
							within that row, taking into account the number
							of bytes each pixel occupies (fdf->bpp / 8).

	(unsigned int *)dst: 	The pointer dst is cast to an unsigned int *
							because each pixel is typically represented by
							4 bytes (32 bits) in memory, which is what
							unsigned int typically holds.

	*(unsigned int *)dst: 	This dereferences the pointer to access the
							memory location and assigns the color value
							to that address.

Example:
	The Image is 800 pixels wide 
	(line_len = 3200 because of RGBA = 4 bytes per pixel).

	To draw a pixel at (x = 5, y = 10).
    bpp = 32bit : bpp / 8 	= 4	(each pixel takes 4 bytes).
    line_len =  4 * 800 = 3200 	(each row is 3200 bytes).

	dst = fdf->addr + (10 * 3200 + 5 * 4);

	Moves 10 rows down (10 * 3200 = 32000 bytes).
	Moves 5 pixels right (5 * 4 = 20 bytes).
	Final position: 32020 bytes from the start.

*/
