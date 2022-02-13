#include "Scene3.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "shader.hpp"
#include "Application.h"

Scene3::Scene3()
{
}

Scene3::~Scene3()
{
}

void Scene3::Init()
{
	// Init VBO here
	rotateAngle = 0;
	translateX = 0;
	translateY = 0;
	scaleAll = 1;

	
	


	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	glGenBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glGenBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);

	// rectangle ground
	static const GLfloat vertex_buffer_data[] = {
		1.0f, 1.0f, -1.0f,
		1.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		1.0f, 1.0f, -1.0f,
		0.0f, 1.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data),
		vertex_buffer_data, GL_STATIC_DRAW);
	static const GLfloat color_buffer_data[] = {
		0.4f, 0.4f, 0.0f,
		0.4f, 0.4f, 0.0f,
		0.4f, 0.4f, 0.0f,
		0.4f, 0.4f, 0.0f,
		0.4f, 0.4f, 0.0f,
		0.4f, 0.4f, 0.0f,
	
	
	};
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data),
		color_buffer_data, GL_STATIC_DRAW);

	// rain
	static const GLfloat vertex_buffer_data_2[] = {
		1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data_2),
		vertex_buffer_data_2, GL_STATIC_DRAW);
	static const GLfloat color_buffer_data_2[] = {
		0.6f, 0.6f, 0.8f,
		0.6f, 0.6f, 0.8f,
		0.6f, 0.6f, 0.8f,
		0.6f, 0.6f, 0.8f,
		0.6f, 0.6f, 0.8f,
		0.6f, 0.6f, 0.8f,


	};
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data_2),
		color_buffer_data_2, GL_STATIC_DRAW);

	//clouds
	static const GLfloat vertex_buffer_data_3[] = {
		1.0f, 1.0f, 2.0f,
		1.0f, 0.0f, 2.0f,
		0.0f, 0.0f, 2.0f,

		1.0f, 1.0f, 2.0f,
		0.0f, 1.0f, 2.0f,
		0.0f, 0.0f, 2.0f,
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_3]);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data_3),
		vertex_buffer_data_2, GL_STATIC_DRAW);
	static const GLfloat color_buffer_data_3[] = {
		0.4f, 0.4f, 0.4f,
		0.4f, 0.4f, 0.4f,
		0.2f, 0.2f, 0.2f,
		0.6f, 0.6f, 0.6f,
		0.6f, 0.6f, 0.6f,
		0.2f, 0.2f, 0.2f,


	};
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data_3),
		color_buffer_data_3, GL_STATIC_DRAW);

	//Trees
	static const GLfloat vertex_buffer_data_4[] = {
		-1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,

		0.0f, 0.5f, 0.0f,
		1.0f, -0.5f, 0.0f,
		-1.0f, -0.5f, 0.0f,

		-0.2f, -0.5f, 0.0f,
		-0.2f, -1.0f, 0.0f,
		0.2f, -0.5f, 0.0f,

		0.2f, -1.0f, 0.0f,
		0.2f, -0.5f, 0.0f,
		-0.2, -1.0f, 0.0f
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_4]);


	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data_4),
		vertex_buffer_data_4, GL_STATIC_DRAW);
	static const GLfloat color_buffer_data_4[] = {
		0.0f, 0.4f, 0.0f,
		0.0f, 0.4f, 0.0f,
		0.0f, 0.4f, 0.0f,
		0.0f, 0.4f, 0.0f,
		0.0f, 0.4f, 0.0f,
		0.0f, 0.4f, 0.0f,

		0.4f, 0.2f, 0.2f,
		0.4f, 0.2f, 0.2f,
		0.4f, 0.2f, 0.2f,
		0.4f, 0.2f, 0.2f,
		0.4f, 0.2f, 0.2f,
		0.4f, 0.2f, 0.2f
	};
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_4]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data_4),
		color_buffer_data_4, GL_STATIC_DRAW);

	m_programID = LoadShaders(
		"Shader//TransformVertexShader.vertexshader",
		"Shader//SimpleFragmentShader.fragmentshader");

	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	glUseProgram(m_programID);

	glEnable(GL_DEPTH_TEST);
}

void Scene3::Update(double dt)
{
	//if (Application::IsKeyPressed(VK_SPACE))
	
	static int rotation = 1;
	if (rotation == 1) {
		rotateAngle += (float)(10 * dt);
		if (rotateAngle > 2) {
			rotation = -1;
		}
	}
	else if (rotation == -1) {
		rotateAngle -= float(10 * dt);
		if (rotateAngle < 0) {
			rotation = 1;
		}
	}

	static int translate = 1;
	translateX += (float)(5 * dt);
	if (translateX > 40) {
		translateX = -40;
	}
	else if (translateX < -40) {
		translateX = 40;
	}

	translateY -= (float)(50 * dt);
	
    if (translateY < -30) {
		translateY = 30;
	}

	scaleAll += (float)(5 * dt);
	if (scaleAll > 50) {
		scaleAll = 1;
	}
	
	
	for (int i = 0; i < 50; i++)
	{
		randomrain = rand() % 80;
		randomrainh = rand() % 40;
		rain[i] = randomrain;
		rainheight[i] = randomrainh;
		
	}
}

void Scene3::Render()
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

	scale.SetToScale(80, 30, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(-40, -30, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//rain
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	for (int i = 0; i < 50; i++) {
		scale.SetToScale(0.5, 2, 1);
		rotate.SetToRotation(30, 0, 0, 1);
		translate.SetToTranslation(-40 + rain[i], 25 - rainheight[i], 0);

		model = translate * rotate * scale;
		MVP = projection * view * model;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	//cloud
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_3]);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_3]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);


	scale.SetToScale(40, 5, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(translateX, 16, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	scale.SetToScale(40, 6, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(translateX + 20, 19, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	scale.SetToScale(40, 8, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(translateX - 30 , 14, 0);

	scale.SetToScale(60, 4, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(translateX - 40, 19, 0);

	scale.SetToScale(80, 4, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(translateX -80, 18, 0);

	scale.SetToScale(30, 3, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(translateX - 60, 18, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	scale.SetToScale(570, 10, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(-40, 20, 0);

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);


	//trees
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_4]);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0
	);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_4]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	for (int i = 0; i < 15; i++) {
		scale.SetToScale(2, 6, 1);
		rotate.SetToRotation(rotateAngle, 0, 0, 1);
		translate.SetToTranslation(-40 + 6 * i, -10, 0);

		model = translate * rotate * scale;
		MVP = projection * view * model;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		glDrawArrays(GL_TRIANGLES, 0, 24);
	}

	for (int i = 0; i < 15; i++) {
		scale.SetToScale(2, 6, 1);
		rotate.SetToRotation(rotateAngle + 1, 0, 0, 1);
		translate.SetToTranslation(-43 + 6 * i, -4, 0);

		model = translate * rotate * scale;
		MVP = projection * view * model;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		glDrawArrays(GL_TRIANGLES, 0, 24);
	}

	for (int i = 0; i < 15; i++) {
		scale.SetToScale(2, 6, 1);
		rotate.SetToRotation(rotateAngle -1, 0, 0, 1);
		translate.SetToTranslation(-41 + 6 * i, 2, 0);

		model = translate * rotate * scale;
		MVP = projection * view * model;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		glDrawArrays(GL_TRIANGLES, 0, 24);
	}
	/*translate.SetToIdentity();
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
	glDisableVertexAttribArray(1);*/

}

void Scene3::Exit()
{
	// Cleanup VBO here
	glDeleteBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glDeleteBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);
	glDeleteVertexArrays(1, &m_vertexArrayID);

	glDeleteProgram(m_programID);
}