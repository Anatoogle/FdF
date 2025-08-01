/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:31:29 by asemykin          #+#    #+#             */
/*   Updated: 2025/04/02 20:11:05 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

char	*ft_combine(const char *str_chunk, int byte, char *str_long,
		size_t *len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	if (str_long != NULL)
	{
		dest = ft_strdup_t(str_long, byte + *len);
		i = *len;
	}
	j = 0;
	while (str_chunk[j] != '\0')
	{
		dest[i + j] = str_chunk[j];
		j++;
	}
	dest[i + j] = '\0';
	*len = i + j;
	free(str_long);
	return (dest);
}

char	*ft_strdup_t(const char *s, size_t byte_len)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)malloc(byte_len + 1);
	if (d == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	ft_chr_occur(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}
