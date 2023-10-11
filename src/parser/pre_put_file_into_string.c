/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_put_file_into_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:33 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/11 10:58:53 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*read_whole_file(int fd)
{
	char	buf[BUFFER_SIZE +1];
	char	*file_string;
	char	*tmp;
	ssize_t	r;
	
	file_string = ft_calloc(BUFFER_SIZE +1, 1);
	if (file_string == NULL)
		return (NULL);
	(void) fd;
	r = read(fd, file_string, BUFFER_SIZE);
	while (r > 0)
	{
		ft_bzero(buf, BUFFER_SIZE +1);
		r = read(fd, buf, BUFFER_SIZE);
		tmp = file_string;
		file_string = ft_strjoin(file_string, buf);
		free(tmp);
		if (file_string == NULL)
			return (NULL);
	}
	if (r < 0)
		free (file_string);
	return (file_string);
}

char	*put_file_into_string(char *filename)
{
	char	*str;
	int		fd;

	fd = open_file(filename);
	if (fd < 0)
		return (NULL);
	str = read_whole_file(fd);
	if (str == NULL)
	{
		close (fd);
		return (NULL);
	}
	close (fd);
	return (str);
}
