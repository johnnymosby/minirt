/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:08:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/19 21:38:53 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

bool	are_equal_images(void *const image1, void *const image2, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (((char *)image1)[i] != ((char *)image2)[i])
			return (false);
		i++;
	}
	return (true);
}
