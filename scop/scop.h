/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:34:06 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/27 15:42:30 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include "libft/libft.h"
//supprimer avant de rendre
<<<<<<< HEAD
# include "/home/ncharret/Library/SDL2/include/SDL.h"
=======
# include "/nfs/zfs-student-3/users/2014/ncharret/Library/Frameworks/SDL2.framework/Headers/SDL.h"
>>>>>>> cbc7b3513d26b74fe0689e34cc7cf06797cef646
//# include <SDL.h>
# define GL3_PROTOTYPES 1
# include <GL/gl.h>
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

typedef struct	s_image
{
	int				width;
	int				height;
	unsigned char	*data;
	GLuint			textureid;
}				t_image;

typedef struct	s_mesh
{
	GLfloat		*vtx;
	GLfloat		*colors;
	GLfloat		*uv;
	GLfloat		*normals;
	int			vertex_count;
	t_vector	world_position;
	GLuint		vertexbuffer;
	GLuint		colorbuffer;
	GLuint		uvbuffer;
	GLuint		nmbuffer;
	t_vector	angle;
	float		scale;
	t_image		texture;
}				t_mesh;

typedef struct	s_camconfig
{
	float		ratio;
	float		fov;
	float		near;
	float		far;
}				t_camconfig;

typedef struct	s_objindex
{
	int		cstart;
	int		clen;
	int		vstart;
	int		vlen;
}				t_objindex;

typedef struct	s_sdlattr
{	
	SDL_Window		*win;
	SDL_Event		events;
	SDL_GLContext	openglcontext;	
}				t_sdlattr;

typedef struct	s_mvp
{
	GLuint		projmtx;
	GLuint		viewmtx;
	GLuint		modelmtx[2];
}				t_mvp;

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
void				draw_mesh(t_mesh mesh, t_mvp mvp, int programid_index);
double				toradian(double angle);
void 				create_projection_matrix(matrix mtx, t_camconfig cfg);
void				create_scale_matrix(matrix mtx, float factor);
void				multiply_matrix(matrix result, matrix mt1, matrix mt2);
t_vector			sub_vector(t_vector a, t_vector b);
double				dot_product(t_vector a, t_vector b);
t_vector			cross_product(t_vector a, t_vector b);
t_vector			norm_vector(t_vector a);
void				create_lookat_matrix(matrix mtx, t_vector eye, t_vector target, t_vector up);
t_mesh				load_model(char *path, char *imgpath);
void				get_coord_index(char **file, int *vstart, int *vlen);
void				get_vertex_index(char **file, int *vstart, int *vlen, int i);
int					count_obj_vertex(int vstart, int vlen, char **file);
int					count_line_index(char **file, int line);
void				get_index(char **file, int *numb, int i, int linecount);
void				error(char *msg);
char				*read_obj(char *path);
char				**split_obj(char **file);
void				key_input(t_mesh *mesh);
t_image				load_bmp(char *path);
t_vector			add_vector(t_vector a, t_vector b);
#endif
