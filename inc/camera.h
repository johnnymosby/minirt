/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:19:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/26 16:27:44 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "matrices.h"

typedef struct s_camera {
	int			hsize;
	int			vsize;
	double		field_of_view;
	t_matrix	transform;
} t_camera;

t_camera	camera(int hsize, int vsize, double field_of_view);

#endif