/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:11:54 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 15:23:37 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

bool	are_equal_matrices(t_matrix a, t_matrix b)
{
	if (ft_memcmp(&a, &b, sizeof(double) * MAX_TOTAL_SIZE) == 0)
		return (true);
	else
		return (false);
}
