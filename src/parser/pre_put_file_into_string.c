/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_put_file_into_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:33 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 18:30:14 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*clean_and_return(int *ret, char *file_string, char *buf)
{
	if (*ret == ERR_READ)
	{	
		free(file_string);
		file_string = NULL;
	}
	free(buf);
	buf = NULL;
	return (file_string);
}

static char	*read_whole_file(int fd, int *ret, char *file_string)
{
	char	*buf;
	char	*tmp;
	int		r;

	buf = ft_calloc(BUFFER_SIZE +1, 1);
	if (buf == NULL)
		*ret = ERR_MALLOC;
	r = BUFFER_SIZE;
	while (r == BUFFER_SIZE && *ret == 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			*ret = ERR_READ;
			break ;
		}
		buf[r] = 0;
		tmp = file_string;
		file_string = ft_strjoin(file_string, buf);
		free(tmp);
		tmp = NULL;
		if (file_string == NULL)
			*ret = ERR_MALLOC;
	}
	return (clean_and_return(ret, file_string, buf));
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
	str = ft_calloc(BUFFER_SIZE +1, 1);
	if (str == NULL)
	{
		*ret = ERR_OPEN_FILE;
		close (fd);
		return (NULL);
	}
	str = read_whole_file(fd, ret, str);
	close (fd);
	return (str);
}
