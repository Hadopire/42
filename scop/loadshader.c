/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadshader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 15:56:55 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/14 17:58:08 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TAILLE_TAMPON 1024
#include "scop.h"

static char	*charger_contenu_fichier(const char *chemin_fichier)
{
	char			*mem;
	char			tampon[TAILLE_TAMPON];
	int				fd;
	unsigned int	i;
	unsigned int	lu;

	mem = NULL;
	if ((fd = open(chemin_fichier, O_RDONLY)) > 0)
	{
		if ((i = lseek(fd, 0, SEEK_END)) > 0)
		{
			mem = (char*)malloc(sizeof(char) * (i + 1));
			mem[i] = '\0';
			lseek(fd, 0, SEEK_SET);
			i = 0;
			while ((lu = read(fd, tampon, TAILLE_TAMPON)) > 0)
			{
				memcpy(&mem[i], tampon, lu);
				i += TAILLE_TAMPON;
			}
		}
		close(fd);
	}
	return (mem);
}

void		compile_shader(GLuint shaderid, const char *path)
{
	int		infologlength;
	char	*shader_code;
	GLint	result;
	char	*shader_error_msg;

	result = GL_FALSE;
	shader_code = charger_contenu_fichier(path);
	printf("Compiling shader : %s", path);
	glShaderSource(shaderid, 1, (const char*const*)&shader_code, NULL);
	glCompileShader(shaderid);
	free(shader_code);
	glGetShaderiv(shaderid, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderid, GL_INFO_LOG_LENGTH, &infologlength);
	if (infologlength > 0)
	{
		shader_error_msg = malloc(infologlength);
		glGetShaderInfoLog(shaderid, infologlength, NULL, shader_error_msg);
		printf("\n%s\n", shader_error_msg);
		free(shader_error_msg);
		exit(-1);
	}
	else
		printf(" | OK\n");
}

GLuint		link_program(GLuint vertexshader_id, GLuint fragmentshader_id)
{
	int		infologlength;
	GLint	result;
	GLuint	program_id;
	char	*program_error_msg;

	result = GL_FALSE;
	fprintf(stdout, "Linking program\n");
	program_id = glCreateProgram();
	glAttachShader(program_id, vertexshader_id);
	glAttachShader(program_id, fragmentshader_id);
	glLinkProgram(program_id);
	glGetProgramiv(program_id, GL_LINK_STATUS, &result);
	glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &infologlength);
	if (infologlength > 0)
	{
		program_error_msg = malloc(infologlength);
		glGetProgramInfoLog(program_id, infologlength, NULL, program_error_msg);
		fprintf(stdout, "%s\n", program_error_msg);
	}
	else
		printf(" | OK\n");
	return (program_id);
}

GLuint		loadshader(const char *vtx_file_path, const char *frag_file_path)
{
	GLuint	vertexshader_id;
	GLuint	fragmentshader_id;
	GLuint	program_id;

	vertexshader_id = glCreateShader(GL_VERTEX_SHADER);
	fragmentshader_id = glCreateShader(GL_FRAGMENT_SHADER);
	compile_shader(vertexshader_id, vtx_file_path);
	compile_shader(fragmentshader_id, frag_file_path);
	program_id = link_program(vertexshader_id, fragmentshader_id);
	glDeleteShader(vertexshader_id);
	glDeleteShader(fragmentshader_id);
	return (program_id);
}
