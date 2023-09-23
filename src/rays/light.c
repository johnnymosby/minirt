/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:20:01 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/23 16:31:56 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	point_light(t_color *intensity, t_tuple *position)
{
	t_light	created_light;

	created_light.position = *position;
	created_light.intensity = *intensity;
	return (created_light);
}
