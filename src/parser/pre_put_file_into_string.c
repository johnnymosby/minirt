/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_put_file_into_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:33 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/25 18:47:52 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


static char	*read_file(int fd)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	char	*file_string;
	ssize_t	r;

	ft_bzero(buf, BUFFER_SIZE);
	file_string = ft_calloc(1,1);
	if (file_string == NULL)
		return (NULL);
	r = BUFFER_SIZE -1;
	while (r == BUFFER_SIZE -1)
	{
		r = read(fd, buf, BUFFER_SIZE -1);
		if (r < 0)
		{
			free (file_string);
			return (NULL);
		}
		tmp = file_string;
		file_string = ft_strjoin(file_string, buf);
		free(tmp);
		if (file_string == NULL)
			return (NULL);
	}
	return (file_string);
}

char *put_file_into_string(char *filename)
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