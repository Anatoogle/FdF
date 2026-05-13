/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_plus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:18:56 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:11:10 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_plus.h"

int count_file(char *str, t_data *data)
{
	int     fd;
	char    *line;
	int     mode = 0;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);

	line = get_next_line(fd);

	while (line)
	{
		if (line[0] == '\n')
		{
			mode = 1;
			free(line);
			line = get_next_line(fd);
			continue;
		}

		if(mode == 1)
			data->fdf.edge_count++;

		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
} 

int fdf_parse(char *str, t_data *data)
{
    int     fd;
    char    *line;
    int     v = 0;
    int     e = 0;
    int     mode = 0;

	count_file(str, data);
	data->fdf.vertices = malloc(sizeof(t_vertex) * data->fdf.edge_count); 
	data->fdf.edges = malloc(sizeof(t_edge) * data->fdf.edge_count); 

    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (1);

    line = get_next_line(fd);

    while (line)
    {
        if (line[0] == '\n')
        {
            mode = 1;
            free(line);
            line = get_next_line(fd);
            continue;
        }

        if (mode == 0)
        {
            parse_vertex(line, &data->fdf.vertices[v]);
            v++;
        }
        else
        {
            parse_edge(line, &data->fdf.edges[e]);
            e++;
        }

        free(line);
        line = get_next_line(fd);
    }

    close(fd);
    return (0);
}

void parse_vertex(char *line, t_vertex *v)
{
	char **s = ft_split(line, ',');

	v->id = atoi(s[0]);
	v->pos.x = atof(s[1]);
	v->pos.y = atof(s[2]);
	v->pos.z = atof(s[3]);

	free_sar(s);
}

void parse_edge(char *line, t_edge *e)
{
	char **s = ft_split(line, ',');

	e->from = atoi(s[0]);
	e->to = atoi(s[1]);

	free_sar(s);
}
