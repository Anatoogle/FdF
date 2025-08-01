/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:50:59 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:11:02 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

char	*get_next_line(int fd)
{
	char		*str_long;
	static char	*buffer_tmp[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_long = (char *)malloc(1);
	if (!str_long)
		return (0);
	str_long[0] = '\0';
	str_long = ft_set_first_chunk(fd, str_long, &buffer_tmp[fd]);
	str_long = ft_split_end(str_long);
	if (str_long == 0)
	{
		free(buffer_tmp[fd]);
		buffer_tmp[fd] = NULL;
	}
	return (str_long);
}

char	*ft_set_first_chunk(int fd, char *str_long, char **buffer_tmp)
{
	size_t	i;

	if (!*buffer_tmp)
	{
		*buffer_tmp = (char *)malloc(BUFFER_SIZE + 1);
		if (!*buffer_tmp)
			return (0);
	}
	else
	{
		*buffer_tmp = ft_set_last_to_first_chunk(*buffer_tmp);
		free(str_long);
		str_long = ft_strdup_t(*buffer_tmp, ft_strlen(*buffer_tmp));
		if (ft_chr_occur(*buffer_tmp, '\n'))
		{
			return (str_long);
		}
	}
	i = ft_strlen(str_long);
	return (ft_read_line(fd, str_long, buffer_tmp, &i));
}

char	*ft_read_line(int fd, char *str_long, char **buffer_tmp, size_t *len)
{
	int		byte;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	byte = 1;
	while (byte > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			ft_bzero(str_long, ft_strlen(str_long));
			return (str_long);
		}
		str_long = ft_combine(buffer, byte, str_long, len);
		if (ft_chr_occur(buffer, '\n'))
			break ;
	}
	free(*buffer_tmp);
	*buffer_tmp = ft_strdup_t(buffer, byte);
	free(buffer);
	return (str_long);
}

char	*ft_split_end(char *str_long)
{
	char	*dest;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (str_long[i] == '\0')
	{
		free(str_long);
		return (0);
	}
	while (str_long[i] != '\0' && str_long[i] != '\n')
		i++;
	i += (str_long[i] == '\n');
	dest = (char *)malloc(i + 1);
	if (!dest)
		return (0);
	while (j < i)
	{
		dest[j] = str_long[j];
		j++;
	}
	dest[j] = '\0';
	free(str_long);
	return (dest);
}

char	*ft_set_last_to_first_chunk(char *str_startchunk)
{
	int		i;
	int		j;
	char	*dest;
	int		len;

	if (!str_startchunk)
		return (NULL);
	len = ft_strlen(str_startchunk);
	i = 0;
	while (str_startchunk[i] != '\n' && str_startchunk[i] != '\0')
		i++;
	if (str_startchunk[i] == '\n')
		i++;
	dest = (char *)malloc(len - i + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (str_startchunk[i + j] != '\0')
	{
		dest[j] = str_startchunk[i + j];
		j++;
	}
	dest[j] = '\0';
	free(str_startchunk);
	return (dest);
}
