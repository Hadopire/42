/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:34:06 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/11 15:48:11 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include "libft/libft.h"
//supprimer avant de rendre
# include "/nfs/zfs-student-2/users/2014/ncharret/Library/Frameworks/SDL2.framework/Headers/SDL.h"
//# include <SDL.h>
# define GL3_PROTOTYPES 1
# include <opengl/gl3.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
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

typedef struct	s_mesh
{
	GLfloat		*vtx;
	GLfloat		*colors;
	int			vertex_count;
	t_vector	world_position;
	GLuint		vertexbuffer;
	GLuint		colorbuffer;
	t_vector	angle;
	float		scale;
}				t_mesh;

typedef struct	s_keys
{
	int			d;
	int			a;
	int			right;
	int			left;
	int			up;
	int			down;
}				t_keys;

typedef struct	s_camconfig
{
	float		ratio;
	float		fov;
	float		near;
	float		far;
}				t_camconfig;

GLuint				loadshader(const char *fichier_vertex_shader,
								const char *fichier_fragment_shader);
void 				create_translation_matrix(t_vector vtc, matrix mtx);
void				print_matrix(matrix mtx);
t_vector			init_vector(float x, float y, float z);
void				print_triangle(GLfloat *vtx, int i);
void				transform_triangle(GLfloat *vtx, matrix mtx, int index);
void				create_rx_matrix(matrix mtx, float angle);
void				create_ry_matrix(matrix mtx, float angle);
void				create_rz_matrix(matrix mtx, float angle);
void				transform_model(GLfloat *vtx, matrix mtx, int triangle_count);
void				print_model(GLfloat *vtx, int triangle_count);
void				draw_mesh(t_mesh mesh, GLuint *ModelMatrices, GLuint ProjectionMatrix, GLuint ViewMatrix);
double				toradian(double angle);
void 				create_projection_matrix(matrix mtx, t_camconfig cfg);
void				create_scale_matrix(matrix mtx, float factor);
void				multiply_matrix(matrix result, matrix mt1, matrix mt2);
t_vector			sub_vector(t_vector a, t_vector b);
double				dot_product(t_vector a, t_vector b);
t_vector			cross_product(t_vector a, t_vector b);
t_vector			norm_vector(t_vector a);
void				create_lookat_matrix(matrix mtx, t_vector eye, t_vector target, t_vector up);
t_mesh				load_model(char *path);
#endif
