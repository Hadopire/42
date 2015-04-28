/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 19:52:03 by ncharret          #+#    #+#             */
/*   Updated: 2015/04/28 20:11:21 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector init_vector(float x, float y, float z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 1.0;
	return (vector);
}
