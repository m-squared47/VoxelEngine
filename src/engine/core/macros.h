#pragma once
#include <GL/glew.h>
#include <GLM/glm.hpp>
/*==========================================*/
/*				File Path					*/
/*==========================================*/

// add a macro for solution directory

/*==========================================*/
/*					CUBE					*/
/*==========================================*/
// for basic shader
#define CUBE_VERTICES (float[]) { -0.5f,  0.0f, -0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, -0.5f,  1.0f, -0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,   0.5f, 1.0f, -0.5f, 1.0f, 0.6f, 0.32f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.5f, 0.0f, -0.5f, 0.9f, 0.45f, 0.17f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,0.5f, 0.0f, -0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f, -0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f,  0.5f, 1.0f, 0.6f, 0.32f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 0.0f,  0.5f, 0.9f, 0.45f, 0.17f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, 0.0f,  0.5f, 0.8f, 0.3f, 0.2f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -0.5f, 1.0f,  0.5f, 0.8f, 0.3f, 0.2f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 1.0f,  0.5f, 1.0f, 0.6f, 0.32f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f,  0.5f, 0.9f, 0.45f, 0.17f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, -0.5f, 0.0f,  0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, 1.0f,  0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, -0.5f, 1.0f, -0.5f, 1.0f, 0.6f, 0.32f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -0.5f, 0.0f, -0.5f, 0.9f, 0.45f, 0.17f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, -0.5f, 1.0f, -0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, -0.5f, 1.0f,  0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f,  0.5f, 1.0f, 0.6f, 0.32f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f, -0.5f, 0.9f, 0.45f, 0.17f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, -0.5f, 0.0f, -0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, -0.5f, 0.0f,  0.5f, 0.8f, 0.3f, 0.2f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.5f, 0.0f,  0.5f, 1.0f, 0.6f, 0.32f, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.5f, 0.0f, -0.5f, 0.9f, 0.45f, 0.17f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f}
#define CUBE_INDICES (int[]) { 0, 3, 2, 0, 1, 2, 4, 6, 7, 4, 5, 6, 8, 11, 10, 8, 9, 10, 12, 15, 14,12, 13, 14, 16, 19, 18, 16, 17, 18, 20, 23, 22, 20, 21, 22 }

// buffer properties
#define CUBE_VERTICES_LENGTH = 264;
#define CUBE_INDICES_LENGTH = 36;
#define CUBE_VERTICES_SIZEOF = (CUBE_VERTICES_LENGTH * sizeof(float))
#define CUBE_INDICES_SIZEOF = CUBE_INDICES_LENGTH * sizeof(int)
#define CUBE_VERTICES_STRIDE = 11 * sizeof(float)
#define CUBE_LAYOUT_0 = (void*)0
#define CUBE_LAYOUT_1 = (void*)(3 * sizeof(float))
#define CUBE_LAYOUT_2 = (void*)(6 * sizeof(float))
#define CUBE_LAYOUT_3 = (void*)(8 * sizeof(float))

/*==========================================*/
/*				LIGHT CUBE					*/
/*==========================================*/
// for light shader
#define LIGHT_CUBE_VERTICES (float[]) { -0.1f, -0.1f,  0.1f, -0.1f, -0.1f, -0.1f, 0.1f, -0.1f, -0.1f, 0.1f, -0.1f,  0.1f, -0.1f,  0.1f,  0.1f, -0.1f,  0.1f, -0.1f, 0.1f,  0.1f, -0.1f, 0.1f,  0.1f,  0.1f }
#define LIGHT_CUBE_INDICES (int[]) { 0, 1, 2, 0, 2, 3, 0, 4, 7, 0, 7, 3, 3, 7, 6, 3, 6, 2, 2, 6, 5, 2, 5, 1, 1, 5, 4, 1, 4, 0, 4, 5, 6, 4, 6, 7 }

// buffer properties
#define LIGHT_CUBE_VERTICES_LENGTH = 24;
#define LIGHT_CUBE_INDICES_LENGTH = 36;
#define LIGHT_CUBE_VERTICES_SIZEOF = LIGHT_CUBE_VERTICES_LENGTH * sizeof(float)
#define LIGHT_CUBE_INDICES_SIZEOF = LIGHT_CUBE_INDICES_LENGTH * sizeof(int)
#define LIGHT_CUBE_VERTICES_STRIDE = 3 * sizeof(float)
#define LIGHT_CUBE_VERTICES_OFFSET = (void*)0

/*
// Vertices coordinates
// CUBE
GLfloat vertices[] =
{
	//	Coords				// Colors				// Texture Coords	 // Normals
	-0.5f,  0.0f, -0.5f,    0.8f, 0.3f,  0.2f ,     0.0f, 0.0f,          0.0f, 0.0f, -1.0f,    // Front LL       0
	-0.5f,  1.0f, -0.5f,    0.8f, 0.3f,  0.2f ,     0.0f, 1.0f,          0.0f, 0.0f, -1.0f,    // Front UL       1
	 0.5f,  1.0f, -0.5f,    1.0f, 0.6f,  0.32f,     1.0f, 1.0f,          0.0f, 0.0f, -1.0f,    // Front UR       2
	 0.5f,  0.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          0.0f, 0.0f, -1.0f,    // Front LR       3

	 0.5f,  0.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,          1.0f, 0.0f, 0.0f,    // Right LL        4
	 0.5f,  1.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,          1.0f, 0.0f, 0.0f,    // Right UL        5
	 0.5f,  1.0f,  0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,          1.0f, 0.0f, 0.0f,    // Right UR        6
	 0.5f,  0.0f,  0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          1.0f, 0.0f, 0.0f,    // Right LR        7

	-0.5f,  0.0f,  0.5f,    0.8f, 0.3f, 0.2f,       1.0f, 0.0f,          0.0f, 0.0f, 1.0f,    // Back LL         8
	-0.5f,  1.0f,  0.5f,    0.8f, 0.3f, 0.2f,       1.0f, 1.0f,          0.0f, 0.0f, 1.0f,    // Back UL         9
	 0.5f,  1.0f,  0.5f,    1.0f, 0.6f, 0.32f,      0.0f, 1.0f,          0.0f, 0.0f, 1.0f,    // Back UR         10
	 0.5f,  0.0f,  0.5f,    0.9f, 0.45f, 0.17f,     0.0f, 0.0f,          0.0f, 0.0f, 1.0f,    // Back LR         11

	-0.5f,  0.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,         -1.0f, 0.0f, 0.0f,    // Left LL         12
	-0.5f,  1.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,         -1.0f, 0.0f, 0.0f,    // Left UL         13
	-0.5f,  1.0f, -0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,         -1.0f, 0.0f, 0.0f,    // Left UR         14
	-0.5f,  0.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,         -1.0f, 0.0f, 0.0f,    // Left LR         15

	-0.5f,  1.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,          0.0f, 1.0f, 0.0f,    // Top LL          16
	-0.5f,  1.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,          0.0f, 1.0f, 0.0f,    // Top UL          17
	 0.5f,  1.0f,  0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,          0.0f, 1.0f, 0.0f,    // Top UR          18
	 0.5f,  1.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          0.0f, 1.0f, 0.0f,    // Top LR          19

	-0.5f,  0.0f, -0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 0.0f,          0.0f, -1.0f, 0.0f,   // Bottom LL       20
	-0.5f,  0.0f,  0.5f,    0.8f, 0.3f, 0.2f,       0.0f, 1.0f,          0.0f, -1.0f, 0.0f,   // Bottom UL       21
	 0.5f,  0.0f,  0.5f,    1.0f, 0.6f, 0.32f,      1.0f, 1.0f,          0.0f, -1.0f, 0.0f,   // Bottom UR       22
	 0.5f,  0.0f, -0.5f,    0.9f, 0.45f, 0.17f,     1.0f, 0.0f,          0.0f, -1.0f, 0.0f    // Bottom LR       23
};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 2,	// Front Lower Tri
	0, 1, 2,	// Front Upper Tri

	4, 6, 7,	// Right Lower Tri
	4, 5, 6,	// Right Upper Tri

	8, 11, 10,	// Back Lower Tri
	8, 9, 10,	// Back Upper Tri

	12, 15, 14,	// Left Lower Tri
	12, 13, 14,	// Left Upper Tri

	16, 19, 18,	// Top Lower Tri
	16, 17, 18,	// Top Upper Tri

	20, 23, 22,	// Bottom Lower Tri
	20, 21, 22 	// Bottom Upper Tri
};

//LightCube
GLfloat lightVertices[] =
{ //     COORDINATES     //
	-0.1f, -0.1f,  0.1f,
	-0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f, -0.1f,
	 0.1f, -0.1f,  0.1f,
	-0.1f,  0.1f,  0.1f,
	-0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f, -0.1f,
	 0.1f,  0.1f,  0.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};
*/