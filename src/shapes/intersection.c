/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:21:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/20 16:58:31 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	add_intersection(t_ipool *hits, t_hit *hit)
{
	hits->pool[hits->last % MAX_INTERSECTIONS] = *hit;
	hits->last++;
}
