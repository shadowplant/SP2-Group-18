#include "Scene4.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "shader.hpp"
#include "Application.h"
#include "MeshBuilder.h"


Scene4::Scene4()
{
}

Scene4::~Scene4()
{
}

void Scene4::Init()
{
	// Init VBO here
	rotateAngle = 0;
	translateX = 0;
	scaleAll = 1;


	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	

	//remove all glGenBuffers, glBindBuffer, glBufferData code
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference", 1000, 1000, 1000);



	m_programID = LoadShaders(
	"Shader//TransformVertexShader.vertexshader",
	"Shader//SimpleFragmentShader.fragmentshader");

	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	glUseProgram(m_programID);

	glEnable(GL_DEPTH_TEST);

	camera.Init(Vector3(4, 3, 3), Vector3(0, 0, 0), Vector3(0, 1, 0));
}

void Scene4::Update(double dt)
{
	if (Application::IsKeyPressed('1'))
		glEnable(GL_CULL_FACE);
	if (Application::IsKeyPressed('2'))
		glDisable(GL_CULL_FACE);
	if (Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if (Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode

	camera.Update(dt);

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

void Scene4::Render()
{
	

	// Render VBO here
	Mtx44 translate, rotate, scale;
	Mtx44 model;
	Mtx44 view;
	Mtx44 projection;
	Mtx44 MVP;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	


	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToLookAt(
		camera.position.x, camera.position.y, camera.position.z,
		camera.target.x, camera.target.y, camera.target.z,
		camera.up.x, camera.up.y, camera.up.z
	);


	projection.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 1000.0f); //FOV, Aspect Ratio, Near plane, Far plane

	model.SetToIdentity();
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	meshList[GEO_AXES]->Render();

	scale.SetToScale(1, 1, 1);
	rotate.SetToRotation(rotateAngle, 0, 0, 1);
	translate.SetToTranslation(0, 0, 0);

	//meshList[GEO_QUAD]->Render();

	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	meshList[GEO_CUBE]->Render();

	
}

void Scene4::Exit()
{
	// Cleanup VBO here
	delete meshList[GEO_QUAD];
	delete meshList[GEO_AXES];
	delete meshList[GEO_CUBE];
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}