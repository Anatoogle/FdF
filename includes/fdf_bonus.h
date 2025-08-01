/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:34:42 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:14:37 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../includes/get_next_line_bonus.h"
# include "../includes/keys_bonus.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define ZOOMXY_FACTOR 10
# define ZOOMXY_DEFAULT 30
# define ZOOMZ_FACTOR 40
# define ZOOMZ_DEFAULT 0.1
# define ROTATE_FACTOR 100
# define STR_X 50
# define STR_Y 50
# define STR_D 20

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	int			row;
	int			col;
	int			**iar;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			cam;
}				t_fdf;

typedef struct s_control
{
	bool		alt;
	bool		leftm;
	bool		middlem;
	bool		rightm;
	bool		first_value;
	bool		reset;
	int			px_start;
	int			px_update;
	int			px_end;
	int			py_start;
	int			py_update;
	int			py_end;
	float		rx_start;
	float		rx_update;
	float		rx_end;
	float		zoomxy_start;
	float		zoomxy_update;
	float		zoomxy_end;
	float		zoomz_start;
	float		zoomz_update;
	float		zoomz_end;
	float		ry_start;
	float		ry_update;
	float		ry_end;
}				t_control;

typedef struct s_data
{
	t_control	control;
	t_fdf		fdf;
}				t_data;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct s_offsetfactor
{
	float		mxy;
	float		mz;
	int			ox;
	int			oy;
}				t_offsetfactor;

int				count_string_array(char **str);
void			free_sar(char **sar);
void			free_iar(int **iar, int col);
int				count_row(char *line);
int				count_col_row(char *fpath, int *col, int *row);
void			set_iar(int **iar, int fd, int col, int row);
float			ft_lerp(float a, float b, float f);
t_point			set_point(float x, float y, float z);
void			put_pixel(t_fdf *fdf, int x, int y, int color);
void			draw_fdf_setup(t_data *data);
void			draw_line_loop(t_fdf *fdf, t_point d, t_point s, t_point start);
void			draw_line_setup(t_fdf *fdf, t_point start, t_point end);
t_point			ft_rotate(float x, float y, float z, float rotate);
t_point			ft_center(int x, int y, int z, t_fdf *fdf);
t_point			projection_parallel(t_point point, float rotate_x,
					float rotate_y);
t_point			projection_iso(t_point point);
t_point			projection_type(float x, float y, float z, t_data *data);
int				event_update(t_data *data);
t_offsetfactor	update_offset(t_control *control);
void			update_transformation(t_control *control);
void			draw_fdf(t_data *data, t_offsetfactor of, int x, int y);
void			update_translation(int x, int y, t_control *control);
void			update_zoom(int x, int y, t_control *control);
void			update_height(int x, int y, t_control *control);
void			update_rotation(int x, int y, t_control *control);
int				event_transformation(int x, int y, t_control *control);
void			perspective_change(t_fdf *fdf);
int				event_keypress(int button, t_data *data);
int				event_keyrelease(int button, t_control *control);
int				event_mousepress(int button, int x, int y, t_control *control);
int				event_mousereleased(int button, int x, int y,
					t_control *control);
void			setup_hooks(t_data *data);
int				fdf_parse(char *str, t_data *data);
int				fdf_setup(t_data *data);
void			init_control(t_control *control);
void			init_fdf(t_fdf *fdf);
int				close_window(t_data *param);
void			navigation_overlay(t_data *data);

#endif
