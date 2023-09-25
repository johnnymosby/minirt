/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/25 11:56:03 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h> // open
# include <unistd.h> // read
# include <stdio.h> // NULL macro
# include "libft.h"

# include "colors.h"
# include "shapes.h"
# define ERR_FILE -1

typedef enum e_shape_type	t_shape_type;

typedef enum e_element_type
{
	//ELMT_CAMERA
	ELMT_LIGHTNING,
	ELMT_LIGHT,
	ELMT_SPHERE,
	//ELMT_PLANE
	//ELMT_CYLINDER
	
}	t_element_type;

typedef struct s_element		// has to be modified when t_shape and t_material are final:
{
	union {
	//	t_camera	camera;
		t_lightning	lightning;
		t_light		light;
		t_sphere	sphere;
	//	t_plane		plane;
	//	t_cylinder	cylinder
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
bool	 	parse_double(char *file_string, int *index, double *result);
bool	 	parse_point(char *file_string, int *index, t_tuple *point);
bool		parse_sphere(char *file_string, int *index, t_element *element);
bool		parse_ambient(char *file_string, int *index, t_element *element);
bool		parse_light(char *file_string, int *index, t_element *element);
bool		parse_color(char *file_string, int *index, t_color *color);

#endif