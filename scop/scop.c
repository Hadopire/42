/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:27:38 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/15 15:01:26 by ncharret         ###   ########.fr       */
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

void	update_screen(GLuint programid, t_mesh *mesh, t_sdlattr *sdlattr, t_mvp *mvp)
{
	int		terminate;

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
		key_input(mesh);
		glUseProgram(programid);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_mesh(*mesh, *mvp);	
		SDL_GL_SwapWindow(sdlattr->win);
	}
}

int main(int ac, char **av)
{
	GLuint		programid;
	t_mesh		mesh;
	t_sdlattr	sdlattr;
	t_mvp		mvp;
	
	init_sdl();
	init_win(&sdlattr);
	init_opengl();
	mesh = load_model(av[1], ac > 2 ? av[2] : NULL);
	programid = loadshader("vertex_shader.vertexshader", "FragmentShader.fragmentshader");
	mvp.modelmtx[0] = glGetUniformLocation(programid, "SCALE");
	mvp.modelmtx[1] = glGetUniformLocation(programid, "TRANS");
	mvp.projmtx = glGetUniformLocation(programid, "PROJECTION");
	mvp.viewmtx = glGetUniformLocation(programid, "VIEW");
	update_screen(programid, &mesh, &sdlattr, &mvp);
	dispose(sdlattr);
	return (0);
}
