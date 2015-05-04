/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 20:47:29 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/04 16:14:09 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_triangle(GLfloat *vtx, int i)
{
	printf("T |   X  |   Y   |  Z  \n-----------------------\n");
	printf("1 | %.02f | % .02f | %.02f\n",
			vtx[i + 0], vtx[i + 1], vtx[i + 2]);
	printf("2 | %.02f | % .02f | %.02f\n",
			vtx[i + 3], vtx[i + 4], vtx[i + 5]);
	printf("3 | %.02f | % .02f | %.02f\n",
			vtx[i + 6], vtx[i + 7], vtx[i + 8]);
}

void	print_model(GLfloat *vtx, int triangle_count)
{
	int i;

	i = 0;
	while (i < triangle_count)
	{
		print_triangle(vtx, i * 9);
		i++;
	}
}
