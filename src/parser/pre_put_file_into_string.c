/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_put_file_into_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:33 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/20 18:43:19 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*read_whole_file(int fd, int *ret)
{
	char	buf[BUFFER_SIZE +1];
	char	*file_string;
	char	*tmp;
	ssize_t	r;

	ft_bzero(buf, BUFFER_SIZE +1);
	file_string = ft_calloc(1, 1);
	if (file_string == NULL)
		return (NULL);
	tmp = file_string;
	r = read(fd, buf, BUFFER_SIZE);
	while (*ret == 0 && r != 0)
	{
		file_string = ft_strjoin(file_string, buf);
		free(tmp);
		tmp = file_string;
		if (file_string == NULL)
			*ret = ERR_MALLOC;
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			*ret = ERR_READ;
	}
	if (*ret == ERR_READ)
		free (file_string);
	return (file_string);
}

char	*put_file_into_string(char *filename, int *ret)
{
	char	*str;
	int		fd;

	if (filename == NULL || ft_strlen(filename) <= 3
		||ft_strncmp(filename + ft_strlen(filename) -3, ".rt", 4))
	{
		*ret = ERR_NAME_FILE_WRONG;
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		*ret = ERR_OPEN_FILE;
		return (NULL);
	}
	str = read_whole_file(fd, ret);
	close (fd);
	return (str);
}
