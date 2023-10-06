/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_open_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 15:56:24 by aguilmea         ###   ########.fr       */
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
	//fd = open(filename, O_DIRECTORY);
	//close(fd);
	//if (fd > 0)
	//	return (ERR_FILE);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERR_FILE);
	return (fd);
}
