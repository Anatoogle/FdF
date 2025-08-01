/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:18:56 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/01 16:18:58 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	fdf_parse(char *str, t_data *data)
{
	int	fd;

	if (count_col_row(str, &data->fdf.col, &data->fdf.row) != 0)
		return (1);
	data->fdf.iar = malloc(sizeof(int *) * data->fdf.col);
	if (!data->fdf.iar)
		return (1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		free_iar(data->fdf.iar, data->fdf.col);
		return (1);
	}
	set_iar(data->fdf.iar, fd, data->fdf.col, data->fdf.row);
	close(fd);
	return (0);
}

int	count_col_row(char *fpath, int *col, int *row)
{
	int		fd_1;
	char	*line;
	int		count;

	fd_1 = open(fpath, O_RDONLY);
	if (fd_1 < 0)
		return (1);
	line = get_next_line(fd_1);
	*row = count_row(line);
	count = *row;
	if (*row == 0)
		return (1);
	while (line)
	{
		free(line);
		(*col)++;
		line = get_next_line(fd_1);
		if (line)
			if (count != count_row(line))
				return (1);
	}
	free(line);
	close(fd_1);
	return (0);
}

int	count_row(char *line)
{
	char	**sar;
	int		count;

	if (!line)
		return (0);
	sar = ft_split(line, 32);
	if (!sar)
	{
		free(line);
		return (0);
	}
	count = count_string_array(sar);
	free_sar(sar);
	return (count);
}

int	count_string_array(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
		i++;
	if (str[i - 1][0] == '\n' && str[i - 1][1] == '\0')
		return (i - 1);
	return (i);
}
