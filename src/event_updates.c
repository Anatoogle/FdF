/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_updates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:10:20 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/03 14:41:28 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	navigation_overlay(t_data *data);

int	event_update(t_data *data)
{
	if (!data->fdf.img || data->control.alt || data->control.middlem)
	{
		if (data->fdf.img)
			mlx_destroy_image(data->fdf.mlx, data->fdf.img);
		data->fdf.img = mlx_new_image(data->fdf.mlx, WINDOW_WIDTH,
				WINDOW_HEIGHT);
		data->fdf.addr = mlx_get_data_addr(data->fdf.img, &data->fdf.bpp,
				&data->fdf.line_len, &data->fdf.endian);
		draw_fdf_setup(data);
		mlx_put_image_to_window(data->fdf.mlx, data->fdf.win, data->fdf.img, 0,
			0);
	}
	navigation_overlay(data);
	return (0);
}

void	navigation_overlay(t_data *data)
{
	mlx_string_put(data->fdf.mlx, data->fdf.win, STR_X, STR_Y + (STR_D * 0),
		0xFFFFFF, "Navigate:");
	mlx_string_put(data->fdf.mlx, data->fdf.win, STR_X, STR_Y + (STR_D * 2),
		0xFFFFFF, "Move:            ALT + MMB + Mouse Move");
	mlx_string_put(data->fdf.mlx, data->fdf.win, STR_X, STR_Y + (STR_D * 4),
		0xFFFFFF, "Zoom:            ALT + RMB + Mouse Move");
}

/*
mlx_new_image(...);
	Allocates a new image in memory with the specified width and height.

mlx_get_data_addr:
	This function retrieves the raw pixel data
	of the image that was created with mlx_new_image.

	&data->fdf.bpp: The bits per pixel (bpp) value,
					which tells you how many bits
					are used to represent each pixel (usually 32 bits for each
					pixel, but it can vary).
					bpp is usually = 32.

	&data->fdf.line_len: 	The length of a line (or row) of the image in
							memory. This is typically the width of the image
							multiplied by the number of bytes per pixel, but
							it may be padded to the next multiple of 4 bytes
							for alignment reasons.

	&data->fdf.endian:	The endian-ness of the image. This tells you whether
						the data is stored in big-endian or little-endian
						format. This is important for correctly interpreting
						the pixel data.
						
						LSB 	= Least Significant Byte is stored first
								Example: 78 56 34 12
						MSB		= Most  Significant Byte is stored first
								Example: 12 34 56 78

	Return Value: 	This function returns a pointer to the beginning of the
					image's pixel data, which is assigned to data->fdf.addr.
					You can then access and manipulate individual pixels by
					directly modifying this memory.

draw_fdf_setup(...);
	this function will manipulate data->fdf.addr to draw the pixels

mlx_put_image_to_window(...)
	Pushes the final image onto the window.
*/
