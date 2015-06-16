/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:34:06 by ncharret          #+#    #+#             */
/*   Updated: 2015/04/28 20:55:08 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include "libft/libft.h"
//supprimer avant de rendre
# include "/home/ncharret/Library/SDL2/include/SDL.h"
//# include <SDL.h>
# define GL3_PROTOTYPES 1
# include <GL/gl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <strings.h>
# define TAILLE_TAMPON 1024

typedef float	matrix[4][4];
typedef	struct	s_vector
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector;

GLuint				loadshader(const char *fichier_vertex_shader,
								const char *fichier_fragment_shader);
void 				create_translation_matrix(t_vector vtc, matrix mtx);
void				print_matrix(matrix mtx);
t_vector			init_vector(float x, float y, float z);
void				print_triangle(GLfloat *vtx);
void				transform_triangle(GLfloat *vtx, matrix mtx);
#endif
