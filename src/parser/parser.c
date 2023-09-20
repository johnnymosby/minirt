/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/20 20:50:30 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
*	opens a file and returns ERR_FILE on error (no fd stays open)
*/
int	open_file(char *filename)
{
	int	fd;
	
	if (filename == NULL || ft_strlen(filename) < 4)
		return (ERR_FILE);
	if (ft_strncmp(filename + ft_strlen(filename) -3, ".rt", 4))
		return (ERR_FILE);
	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close (fd);
		return (ERR_FILE);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_FILE);
	return (fd);
}

static int	count_nl(int fd)
{
	char	buf;
	ssize_t	bytes;
	int		nb_elements;
	
	buf = '\n';	
	bytes = 1;
	nb_elements = 0;
	while (bytes > 0 && buf == '\n')
		bytes = read(fd, &buf, 1);
	while (bytes > 0 && buf != '\0')
	{
		bytes = read(fd, &buf, 1);
		if ((bytes > 0 && buf == '\n') || (bytes == 0 && buf!= '\n'))
		{
			nb_elements++;
			while(bytes > 0 && buf == '\n')
				bytes = read(fd, &buf, 1);
		}
	}
	if (bytes < 0)
		return (0);
	return (nb_elements);
}

/*
*	calls the open function, count the number of elements.
*	no file descriptor is open after returning the function.
*/
int	get_number_elements(char *filename)
{
	int		nb_elements;
	int		fd;


	nb_elements = 0;
	fd = open_file(filename);
	if (fd < 0)
		return (0);
	nb_elements = count_nl(fd);
	close (fd);
	return (nb_elements);
}
