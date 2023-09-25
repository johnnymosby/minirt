/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/25 18:36:36 by aguilmea         ###   ########.fr       */
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
	t_element_type	element_type;
	double			ambient_lightning_ratio;
	t_color			ambient_color;
	t_tuple			light_position;
	t_color			light_intensity;
	t_tuple 		sphere_origin;
	double			sphere_radius;
	t_color			sphere_color;
	
}	t_element;

/*
** ------------------------------- PARSER ------------------------------------
*/

t_element	*get_elements(char *file_string);
char 		*put_file_into_string(char *filename);
int			open_file(char *filename);
bool	 	parse_double(char *file_string, int *index, double *result);
bool	 	parse_point(char *file_string, int *index, t_tuple *point);
bool		parse_sphere(char *file_string, int *index, t_element *element);
bool		parse_ambient(char *file_string, int *index, t_element *element);
bool		parse_light(char *file_string, int *index, t_element *element);
bool		parse_color(char *file_string, int *index, t_color *color);

#endif