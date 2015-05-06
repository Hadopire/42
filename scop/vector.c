/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 19:52:03 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/06 16:35:32 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector	init_vector(float x, float y, float z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 1.0;
	return (vector);
}

t_vector	sub_vector(t_vector a, t_vector b)
{
	t_vector vector;

	vector.x = a.x - b.x;
	vector.y = a.y - b.y;
	vector.z = a.z - b.z;
	return (vector);
}

double		dot_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector vector;

	vector.x = (a.y * b.z) - (a.z * b.y);
	vector.y = (a.z * b.x) - (a.x * b.z);
	vector.z = (a.x * b.y) - (a.y * b.x);
	return (vector);
}

t_vector	norm_vector(t_vector a)
{
	t_vector vector;

	vector.x = a.x / sqrtf( ( (a.x * a.x) + (a.x * a.y) + (a.z * a.z) ) );
	vector.y = a.y / sqrtf( ( (a.x * a.x) + (a.x * a.y) + (a.z * a.z) ) );
	vector.z = a.z / sqrtf( ( (a.x * a.x) + (a.x * a.y) + (a.z * a.z) ) );
	return (vector);
}
