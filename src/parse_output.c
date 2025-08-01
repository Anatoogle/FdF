/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:19:00 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/01 16:19:40 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_iar(int **iar, int fd, int col, int row)
{
	char	*line;
	char	**sar;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(fd);
	while (i < col)
	{
		sar = ft_split(line, 32);
		j = 0;
		iar[i] = malloc(sizeof(int) * row);
		while (j < row)
		{
			iar[i][j] = ft_atoi(sar[j]);
			j++;
		}
		free(line);
		free_sar(sar);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

void	free_sar(char **sar)
{
	int	i;

	i = -1;
	while (sar[++i])
		free(sar[i]);
	free(sar);
}

void	free_iar(int **iar, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		free(iar[i]);
		i++;
	}
	free(iar);
}
