/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/29 22:37:47 by aguilmea         ###   ########.fr       */
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
# include "world.h"
# define ERR_FILE -1

typedef enum e_shape_type	t_shape_type;

typedef enum e_element_type
{
	ELMT_CAMERA,
	ELMT_AMBIENT,
	ELMT_LIGHT,
	ELMT_SPHERE,
	ELMT_PLANE,
	ELMT_CYLINDER,
	
}	t_element_type;

typedef struct s_element		// has to be modified when t_shape and t_material are final:
{
	t_element_type	element_type;
	t_tuple			coordinates;
	t_tuple			orientation;
	t_color			color;
	double			radius;
	double			ambient_lightning_ratio;
	t_color			light_intensity;
	double			cylinder_height;
	double			fov;
	
}	t_element;

/*
** ------------------------------- PARSER ------------------------------------
*/

t_element	*get_elements(char *file_string, int *nb_elmts);
char 		*put_file_into_string(char *filename);
int			open_file(char *filename);
bool	 	parse_double(char *file_string, int *index, double *result);
bool		parse_color(char *file_string, int *index, t_color *color);
bool		parse_coordinates(char *file_string, int *index, t_element *element);
bool		parse_orientation(char *file_string, int *index, t_element *element);
bool		parse_ambient(char *file_string, int *index, t_element *element);
bool		parse_camera(char *file_string, int *index, t_element *element);
bool		parse_light(char *file_string, int *index, t_element *element);
bool		parse_sphere(char *file_string, int *index, t_element *element);
bool		parse_plane(char *file_string, int *index, t_element *element);
bool		parse_cylinder(char *file_string, int *index, t_element *element);

#endif