#include "Scene2.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "shader.hpp"
#include "Application.h"

Scene2::Scene2()
{
}

Scene2::~Scene2()
{
}

void Scene2::Init()
{
	// Init VBO here
	rotateAngle = 0;
	translateX = 0;
	scaleAll = 1;


glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

glGenVertexArrays(1, &m_vertexArrayID);
glBindVertexArray(m_vertexArrayID);

glGenBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
glGenBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);

static const GLfloat vertex_buffer_data[] = {
	-0.5f, 0.5f, 0.0f,
	-0.5f, 0.1f, 0.0f,
	0.0f, 0.5f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.1f, 0.0f,
	0.0f, 0.0f, 0.0f,

	0.1f, 0.5f, 0.0f,
	0.1f, 0.1f, 0.0f,
	0.6f, 0.5f, 0.0f,
	0.0f, -0.1f, 0.0f,
	0.0f, -0.5f, 0.0f,
	0.0f, -0.0f, 0.0f,

	-0.5f, -0.5f, 0.0f,
	-0.5f, -0.2f, 0.0f,
	0.0f, -0.5f, 0.0f,
	0.0f, -0.1f, 0.0f,
	0.0f, -0.5f, 0.0f,
	0.0f, -0.1f, 0.0f,

	0.1f, -0.5f, 0.0f,
	0.1f, -0.1f, 0.0f,
	0.0f, -0.5f, 0.0f,
	0.0f, -0.1f, 0.0f,
	0.6f, -0.5f, 0.0f,
	0.6f, -0.0f, 0.0f,
};

glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);


glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data),
	vertex_buffer_data, GL_STATIC_DRAW);
static const GLfloat color_buffer_data[] = {
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
};
glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data),
	color_buffer_data, GL_STATIC_DRAW);


m_programID = LoadShaders(
	"Shader//TransformVertexShader.vertexshader",
	"Shader//SimpleFragmentShader.fragmentshader");

m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

glUseProgram(m_programID);

glEnable(GL_DEPTH_TEST);
}

void Scene2::Update(double dt)
{
	if (Application::IsKeyPressed(VK_SPACE))
	{
		static int rotation = 1;
		if (rotation == 1) {
			rotateAngle += (float)(50 * dt);
			if (rotateAngle > 360) {
				rotation = -1;
			}
		}
		else if (rotation == -1) {
			rotateAngle -= float(50 * dt);
			if (rotateAngle < 0) {
				rotation = 1;
			}
		}

		static int translate = 1;
		translateX += (float)(50 * dt);
		if (translateX > 40) {
			translateX = -40;
		}
		else if (translateX < -40) {
			translateX = 40;
		}

		scaleAll += (float)(5 * dt);
		if (scaleAll > 50) {
			scaleAll = 1;
		}
	}
}

void Scene2::Render()
{
	// Render VBO here
	Mtx44 translate, rotate, scale;
	Mtx44 model;
	Mtx44 view;
	Mtx44 projection;
	Mtx44 MVP;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);


	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-40, +40, -30, +30, -10, +10);

	scale.SetToScale(scaleAll, 5, 1);
	rotate.SetToRotation(45, 0, 0, 1);
	translate.SetToTranslation(0, 0, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 24);



	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();

	scale.SetToScale(15, 15, 1);
	rotate.SetToRotation(rotateAngle, 0, 0, 1);
	translate.SetToTranslation(10, 10, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 24);



	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();

	scale.SetToScale(30, 30, 2);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(translateX, -10, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 24);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}

void Scene2::Exit()
{
	// Cleanup VBO here
	glDeleteBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glDeleteBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);
	glDeleteVertexArrays(1, &m_vertexArrayID);

	glDeleteProgram(m_programID);
}