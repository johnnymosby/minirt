/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/12 15:03:00 by rbasyrov         ###   ########.fr       */
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
# include "camera.h"
# define ERR_FILE -1

typedef enum e_shape_type	t_shape_type;

typedef enum e_element_type
{
	ELMT_CAMERA	,
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
void		put_elements_into_camera(t_element *element, t_camera *cam);
void		put_elements_into_lightning(t_element *element, int index, t_world *w);
void		put_elements_into_shapes(t_element *element, int index, t_world *w);
void		*print_error_parsing(char *str);
bool		parser(char *filename, t_world *w, t_camera *cam);

#endif