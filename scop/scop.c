/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 16:27:38 by ncharret          #+#    #+#             */
/*   Updated: 2015/05/06 16:07:52 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double		toradian(double angle)
{
	return (((M_PI * angle) / 180));
}

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

	//mesh
	t_mesh	pyramide;
	//vertex
	GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		1.0f, 1.0f,-1.0f, // triangle 2 : begin
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // triangle 2 : end
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};
	pyramide.world_position = init_vector(1, 0, 0);
	pyramide.angle = init_vector(0, 0, 0);
	pyramide.scale = 0.5;
	pyramide.vtx = g_vertex_buffer_data;
	pyramide.triangle_count = 12;
	glGenBuffers(1, &pyramide.vertexbuffer);
	//colors
	GLfloat g_color_buffer_data[] = {
	0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f	
	};
	pyramide.colors = g_color_buffer_data;
	glGenBuffers(1, &pyramide.colorbuffer);
	//load shaders
	GLuint programID = loadshader( "vertex_shader.vertexshader", "FragmentShader.fragmentshader" );
	//TEST MATRIX
	matrix mtx;
	//FIN TEST
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// // Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	GLuint ModelMatrices[3];
	ModelMatrices[0] = glGetUniformLocation(programID, "SCALE");
	ModelMatrices[1] = glGetUniformLocation(programID, "ROTATION");
	ModelMatrices[2] = glGetUniformLocation(programID, "TRANS");
	GLuint ProjectionMatrix;
	ProjectionMatrix = glGetUniformLocation(programID, "PROJECTION");
	while (!terminate)
	{	
		glUseProgram(programID);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw_mesh(pyramide, ModelMatrices, ProjectionMatrix);	
		//refresh
		SDL_GL_SwapWindow(win);
		SDL_PollEvent(&events);
		if (events.window.event == SDL_WINDOWEVENT_CLOSE)
			terminate = 1;
		if (events.type == SDL_KEYDOWN)
		{
			if (events.key.keysym.sym == 27)
				terminate = 1;
			else if (events.key.keysym.sym == SDLK_UP)
			{
				pyramide.angle.x++;
			}
			else if (events.key.keysym.sym == SDLK_DOWN)
			{
				pyramide.angle.x--;
			}
			else if (events.key.keysym.sym == SDLK_RIGHT)
			{
				pyramide.angle.y++;
			}
			else if (events.key.keysym.sym == SDLK_LEFT)
			{
				pyramide.angle.y--;
			}
			else if (events.key.keysym.sym == SDLK_d)
				pyramide.world_position.x += 0.02;
			else if (events.key.keysym.sym == SDLK_a)
				pyramide.world_position.x -= 0.02;
		}
	}

	// On quitte la SDL
	SDL_GL_DeleteContext(openglcontext);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return (0);
}
