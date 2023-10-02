/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:19:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/02 11:47:26 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "matrices.h"

typedef struct s_camera {
	int			hsize;
	int			vsize;
	double		field_of_view;
	double		half_width;
	double		half_height;
	double		pixel_size;
	t_matrix	transform;
} t_camera;

t_camera	camera(int hsize, int vsize, double field_of_view);

#endif