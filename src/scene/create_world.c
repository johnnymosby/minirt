/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:54:29 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/24 16:26:49 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	default_world(void)
{
	t_world	w;

	ft_bzero(&w, sizeof(t_world));
	return (w);
}
