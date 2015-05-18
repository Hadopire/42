/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:27:38 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/18 16:23:37 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double		toradian(double angle)
{
	return (((M_PI * angle) / 180));
}

void	init_sdl()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Erreur d'initialisation de la sdl\n");
		SDL_Quit();
		exit(-1);
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

void	init_win(t_sdlattr *sdlattr)
{
	sdlattr->win = SDL_CreateWindow("Scop OPENGL 4", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1366, 768, SDL_WINDOW_SHOWN);
	if (sdlattr->win == 0)
	{
		printf("Erreur lors de la creation de la fenetre\n");
		SDL_Quit();
		exit(-1);
	}
	sdlattr->openglcontext = SDL_GL_CreateContext(sdlattr->win);
	if (sdlattr->openglcontext == 0)
	{
		printf("Erreur lors de la creation du contexte opengl\n");
		SDL_DestroyWindow(sdlattr->win);
		SDL_Quit();

		exit(-1);
	}
}

void	init_opengl()
{
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void	dispose(t_sdlattr sdlattr)
{
	SDL_GL_DeleteContext(sdlattr.openglcontext);
	SDL_DestroyWindow(sdlattr.win);
	SDL_Quit();
}

int		bindmatrixglsl(t_mesh mesh, t_mvp *mvp, int pid, GLuint *programid)
{
	pid = pid == 1 ? 0 : 1;
	if (mesh.texture.data == NULL)
		pid = 0;
	mvp->modelmtx[0] = glGetUniformLocation(programid[pid], "SCALE");
	mvp->modelmtx[1] = glGetUniformLocation(programid[pid], "TRANS");
	mvp->projmtx = glGetUniformLocation(programid[pid], "PROJECTION");
	mvp->viewmtx = glGetUniformLocation(programid[pid], "VIEW");
	return (pid);
}

void	update_screen(GLuint *programid, t_mesh *mesh, t_sdlattr *sdlattr, t_mvp *mvp)
{
	int		terminate;
	int		programid_index;

	programid_index = 0;
	terminate = 0;
	while (!terminate)
	{
		SDL_PollEvent(&sdlattr->events);
		if (sdlattr->events.window.event == SDL_WINDOWEVENT_CLOSE)
			terminate = 1;
		if (sdlattr->events.type == SDL_KEYDOWN)
		{
			if (sdlattr->events.key.keysym.sym == 27)
				terminate = 1;
		}
		if (sdlattr->events.type == SDL_KEYUP)
			if (sdlattr->events.key.keysym.sym == SDLK_SPACE)
				programid_index = bindmatrixglsl(*mesh, mvp, programid_index, programid);
		sdlattr->events.type = 0;
		key_input(mesh);
		glUseProgram(programid[programid_index]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_mesh(*mesh, *mvp, programid_index);	
		SDL_GL_SwapWindow(sdlattr->win);
	}
}

int main(int ac, char **av)
{
	GLuint		programid[2];
	t_mesh		mesh;
	t_sdlattr	sdlattr;
	t_mvp		mvp;
	
	init_sdl();
	init_win(&sdlattr);
	init_opengl();
	mesh = load_model(av[1], ac > 2 ? av[2] : NULL);
	programid[0] = loadshader("colorvertexshader.vertexshader", "colorfragmentShader.fragmentshader");
	programid[1] = loadshader("texturevertexshader.vertexshader", "texturefragmentShader.fragmentshader");
	mvp.modelmtx[0] = glGetUniformLocation(programid[0], "SCALE");
	mvp.modelmtx[1] = glGetUniformLocation(programid[0], "TRANS");
	mvp.projmtx = glGetUniformLocation(programid[0], "PROJECTION");
	mvp.viewmtx = glGetUniformLocation(programid[0], "VIEW");
	update_screen(programid, &mesh, &sdlattr, &mvp);
	dispose(sdlattr);
	return (0);
}
