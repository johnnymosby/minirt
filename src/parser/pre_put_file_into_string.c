/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_put_file_into_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:33 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/10 15:24:46 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*read_file(int fd)
{
	char	buf[BUFFER_SIZE +1];
	char	*tmp;
	char	*file_string;
	ssize_t	r;

	ft_bzero(buf, BUFFER_SIZE +1);
	file_string = ft_calloc(1, 1);
	if (file_string == NULL)
		return (NULL);
	r = read(fd, buf, BUFFER_SIZE);
	while (r == BUFFER_SIZE)
	{
		tmp = file_string;
		file_string = ft_strjoin(file_string, buf);
		free(tmp);
		if (file_string == NULL)
			return (NULL);
		r = read(fd, buf, BUFFER_SIZE);
	}
	if (r < 0)
		free (file_string);
	else
	{
		tmp = file_string;
		file_string = ft_strjoin(file_string, buf);
		free(tmp);
	}
	return (file_string);
}

char	*put_file_into_string(char *filename)
{
	char	*str;
	int		fd;

	fd = open_file(filename);
	if (fd < 0)
		return (NULL);
	str = read_file(fd);
	if (str == NULL)
	{
		close (fd);
		return (NULL);
	}
	close (fd);
	return (str);
}
