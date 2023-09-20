/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/20 17:15:04 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h> // open
#include <unistd.h> // read
# include <stdio.h> // NULL macro
# include "libft.h"

# define ERR_FILE -1
/*
** ------------------------------- PARSER ------------------------------------
*/

int	open_file(char *filename);
int	get_number_elements(char *filename);



#endif