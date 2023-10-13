/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 16:26:44 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
*	opens a file and returns ERR_FILE on error (no fd stays open)
*/
int	open_file(char *filename)
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
