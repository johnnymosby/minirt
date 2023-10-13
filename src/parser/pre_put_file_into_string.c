/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_put_file_into_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:29:33 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 19:01:29 by aguilmea         ###   ########.fr       */
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

/*
*	opens a file and returns ERR_FILE on error (no fd stays open)
*/
static int	open_file(char *filename)
{
	int	fd;

	if (filename == NULL || ft_strlen(filename) < 3)
	{
		ft_putstr_fd("The file name \"", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd("\" should more than 3 characters\n", 2);
		return (ERR_NAME_FILE_WRONG);
	}
	if (ft_strncmp(filename + ft_strlen(filename) -3, ".rt", 4))
	{
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(" file extension should be .rt\n", 2);
		return (ERR_NAME_FILE_WRONG);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error opening the file: ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd("\n", 2);
		return (ERR_OPEN_FILE);
	}
	return (fd);
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
		ft_putstr_fd("Error reading the file ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd("\n", 2);
		return (NULL);
	}
	close (fd);
	return (str);
}
