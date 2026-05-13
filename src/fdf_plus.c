/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:18:02 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:10:59 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_plus.h"


int	main(int argc, char **argv)
{
	t_data	data;

	init_control(&data.control);
	init_fdf(&data.fdf);
	if (argc != 2)
		return (1);

	if (fdf_parse(argv[1], &data))
		return (1);
	if (fdf_setup(&data))
		return (1);

	setup_hooks(&data);
	return (0);
}

int	fdf_setup(t_data *data)
{
	data->fdf.mlx = mlx_init();
	data->fdf.win = mlx_new_window(data->fdf.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FdF 42");
	if (!data->fdf.win)
		return (1);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_loop_hook(data->fdf.mlx, &event_update, data);
	mlx_hook(data->fdf.win, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_hook(data->fdf.win, KeyRelease, KeyReleaseMask, &event_keyrelease,
		&data->control);
	mlx_hook(data->fdf.win, ButtonPress, ButtonPressMask, &event_mousepress,
		&data->control);
	mlx_hook(data->fdf.win, ButtonRelease, ButtonReleaseMask,
		&event_mousereleased, &data->control);
	mlx_hook(data->fdf.win, MotionNotify, PointerMotionMask,
		&event_transformation, &data->control);
	mlx_hook(data->fdf.win, 17, 0, close_window, data);
	mlx_loop(data->fdf.mlx);
}

int	close_window(t_data *param)
{
	if (param->fdf.img)
		mlx_destroy_image(param->fdf.mlx, param->fdf.img);
	mlx_destroy_window(param->fdf.mlx, param->fdf.win);
	mlx_destroy_display(param->fdf.mlx);
	free(param->fdf.mlx);
	free(param->fdf.vertices); 
	free(param->fdf.edges); 
	exit(0);
	return (0);
}
