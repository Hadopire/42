/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:27:38 by ncharret          #+#    #+#             */
/*   Updated: 2015/04/28 20:59:02 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int main()
{
	// Notre fenêtre

	SDL_Window	*win;
	SDL_Event	events;
	SDL_GLContext openglcontext;	
	int			terminate = 0;

	//init SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Erreur d'initialisation de la sdl\n");
		SDL_Quit();

		return (-1);
	}

	// OPENGL VERSION
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	// Double buffer On
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	// Création de la fenêtre
	win = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	if (win == 0)
	{
		printf("Erreur lors de la creation de la fenetre\n");
		SDL_Quit();
		return (-1);
	}

	// Attacher fenetre a opengl
	openglcontext = SDL_GL_CreateContext(win);
	if (openglcontext == 0)
	{
		printf("Erreur lors de la creation du contexte opengl\n");
		SDL_DestroyWindow(win);
		SDL_Quit();

		return (-1);
	}
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//vertex
	GLfloat g_vertex_buffer_data[] = {
		-0.5, -0.5, 0.0,
		0.5, -0.5, 0.0,
		0.0, 0.5, 0.0,
	};
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	//load shaders
	GLuint programID = loadshader( "vertex_shader.vertexshader", "FragmentShader.fragmentshader" );
	
	//TEST MATRIX
	matrix mtx;
	create_translation_matrix(init_vector(0.1, 0, 0), mtx);
	print_matrix(mtx);
	print_triangle(g_vertex_buffer_data);
	transform_triangle(g_vertex_buffer_data, mtx);
	print_triangle(g_vertex_buffer_data);
	//FIN TEST
	
	while (!terminate)
	{	
		glUseProgram(programID);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);		
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);

		SDL_GL_SwapWindow(win);

		SDL_PollEvent(&events);
		if (events.window.event == SDL_WINDOWEVENT_CLOSE)
			terminate = 1;
		if (events.type == SDL_KEYDOWN)
		{
			if (events.key.keysym.sym == 27)
				terminate = 1;
		}
	}

	// On quitte la SDL
	SDL_GL_DeleteContext(openglcontext);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return (0);
}
