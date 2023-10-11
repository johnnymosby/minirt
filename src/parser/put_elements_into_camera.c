/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_camera.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:30:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/11 16:32:59 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	put_elements_into_camera(t_element *element, t_camera *cam)
{
//	t_tuple	from;
//	t_tuple	to;
//	t_tuple	up;

	*cam = camera(HSIZE_DEFAULT, VSIZE_DEFAULT, element->fov);
	//cam->transform = view_transform(&from, &to, &up);
}
