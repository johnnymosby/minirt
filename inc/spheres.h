/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:31:30 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/20 16:28:40 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERES_H
# define SPHERES_H

# include "shapes.h"

typedef struct s_shape
{
	union {
		t_sphere	sphere;
	};
}	t_shape;

t_shape	create_sphere(void);

#endif