/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 15:56:55 by aduban            #+#    #+#             */
/*   Updated: 2015/04/28 18:57:46 by ncharret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TAILLE_TAMPON 1024
#include "scop.h"

static char    *charger_contenu_fichier(const char *chemin_fichier)
{
    char            *mem;
    char            tampon[TAILLE_TAMPON];
    int                fd;
    unsigned int    i;
    unsigned int    lu;

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

GLuint loadshader(const char * vertex_file_path,const char * fragment_file_path)
{
 
    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
 
    // Read the Vertex Shader code from the file
    char *VertexShaderCode = charger_contenu_fichier(vertex_file_path);
    
    // Read the Fragment Shader code from the file
    char *FragmentShaderCode = charger_contenu_fichier(fragment_file_path);
    
 
    GLint Result = GL_FALSE;
    int InfoLogLength;
 
// Compile Vertex Shader
    printf("Compiling shader : %s", vertex_file_path);
    glShaderSource(VertexShaderID, 1, (const char* const*)&VertexShaderCode , NULL);
    glCompileShader(VertexShaderID);
	free(VertexShaderCode);

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        char VertexShaderErrorMessage[InfoLogLength];
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, VertexShaderErrorMessage);
        printf("\n%s\n", VertexShaderErrorMessage);
    }
    else
        printf(" | OK\n");
 
 // Compile Fragment Shader
    printf("Compiling shader : %s", fragment_file_path);
    glShaderSource(FragmentShaderID, 1, (const char* const*)&FragmentShaderCode , NULL);
    glCompileShader(FragmentShaderID);
	free(FragmentShaderCode);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0)
    {
        char FragmentShaderErrorMessage[InfoLogLength];
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, FragmentShaderErrorMessage);
        printf("\n%s\n", FragmentShaderErrorMessage);
    }
    else
        printf(" | OK\n");
 
    // Link the program
    fprintf(stdout, "Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);
 
    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0)
	{
        char ProgramErrorMessage[InfoLogLength];
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
	}
	else
		printf(" | OK\n");
 
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
 
    return ProgramID;
}
