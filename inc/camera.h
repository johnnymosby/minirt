/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:19:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/22 13:50:23 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrices.h"
# include "world.h"
# include "computations.h"
# include "rays.h"
# include "canvas.h"

typedef struct s_canvas	t_canvas;

# define HSIZE_DEFAULT	200
# define VSIZE_DEFAULT	200

typedef struct s_camera {
	int			hsize;
	int			vsize;
	double		field_of_view;
	double		half_width;
	double		half_height;
	double		pixel_size;
	t_matrix	transform;
	t_matrix	inverse;
	t_matrix	original_transform;
}	t_camera;

typedef struct s_scene
{
	t_camera	camera;
	t_world		*world;
	t_canvas	*canvas;
}	t_scene;

t_camera	camera(int hsize, int vsize, double field_of_view);
t_ray		ray_for_pixel(t_camera *camera, int px, int py);
void		set_transform_in_camera(t_camera *shape, t_matrix *m);
bool		render(t_scene *scene);
void		set_size_values(t_camera *c);

#endif