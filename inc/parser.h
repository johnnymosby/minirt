/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 21:12:04 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h> // open
# include <unistd.h> // read
# include <stdio.h> // NULL macro
# include "libft.h"

# include "colors.h"
# define ERR_FILE -1

typedef struct s_material	// has to be modified when t_shape and t_material are final:
{
	t_color	color;
}	t_material;

typedef struct s_sphere
{
	t_tuple	origin;
	double	radius;
}	t_sphere;

typedef enum e_element_type	// has to be modified when t_shape and t_material are final:
{
	SPHERE
}	t_element_type;


typedef struct s_element		// has to be modified when t_shape and t_material are final:
{
	union {
		t_sphere	sphere;
	};
	t_element_type	element_type;
	t_material		material;
}	t_element;

/*
** ------------------------------- PARSER ------------------------------------
*/

t_element	*get_elements(char *file_string);
char 		*get_file_into_string(char *filename);
int			open_file(char *filename);
bool	 	parse_double(char *str, int *index, double *result);
bool	 	parse_point(char *str, int *index, t_tuple *point);
bool		parse_sphere(char *start, int *index, t_element *element);
bool		parse_color(char *start, int *index, t_element *element);

#endif