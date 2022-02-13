#include "Scene5.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "shader.hpp"
#include "Application.h"
#include "MeshBuilder.h"


Scene5::Scene5()
{
}

Scene5::~Scene5()
{
}

void Scene5::Init()
{
	// Init VBO here
	rotateAngle = 0;
	rotatePlanetAngle = 0;
	rotateMoonAngle = 0;
	rotateStarAngle = 0;
	translateX = 0;
	scaleAll = 1;


	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	//remove all glGenBuffers, glBindBuffer, glBufferData code
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference", 1000, 1000, 1000);
	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("quad",(1, 1, 1), 1, 1);
	meshList[GEO_CIRCLE] = MeshBuilder::GenerateCircle("circle", Color (1, 1, 0), 20, 1);
	meshList[GEO_SPHERE] = MeshBuilder::GenerateSphere("sphere", Color (1, 0, 0), 10, 20);



	m_programID = LoadShaders(
	"Shader//TransformVertexShader.vertexshader",
	"Shader//SimpleFragmentShader.fragmentshader");

	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");

	glUseProgram(m_programID);

	glEnable(GL_DEPTH_TEST);

	camera.Init(Vector3(40, 30, 30), Vector3(0, 0, 0), Vector3(0, 1, 0));
}

void Scene5::Update(double dt)
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

	rotateAngle += (float)(10 * dt);
	rotatePlanetAngle += (float)(10 * dt);
	rotateStarAngle += (float)(10 * dt);
	rotateMoonAngle += (float)(20 * dt);
}

void Scene5::Render()
{
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Mtx44 MVP;

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Rotate(0, 0, 0, 1);
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_AXES]->Render();
	modelStack.PopMatrix();

	//Star
	modelStack.PushMatrix();
	modelStack.Translate(10, 5, 10);

	//Planet
	modelStack.PushMatrix();
	modelStack.Rotate(rotatePlanetAngle, 1, 0, 0); //Revolve
	modelStack.Translate(0, 10, 10);

	//Moon
	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(3, -3, 3);

	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(6, -3, 3);

	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(10, -3, 3);

	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(14, -3, 3);

	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(18, -3, 3);

	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(22, -3, 3);

	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(26, -3, 3);

	modelStack.PushMatrix();
	modelStack.Rotate(rotateMoonAngle, 0, 0, 1); //Revolve
	modelStack.Translate(30, -3, 3);

	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix()
		;
	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotateMoonAngle, 0, 1, 0); //Rotate
	modelStack.Scale(1, 1, 1);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotatePlanetAngle, 0, 0, 1); //Rotate
	modelStack.Scale(2, 2, 2);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();

	modelStack.Rotate(rotateStarAngle, 0, 0, 1); //Rotate
	modelStack.Scale(6, 6, 6);
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_SPHERE]->Render();
	modelStack.PopMatrix();
}

void Scene5::Exit()
{
	// Cleanup VBO here
	delete meshList[GEO_QUAD];
	delete meshList[GEO_AXES];
	delete meshList[GEO_CUBE];
	delete meshList[GEO_CIRCLE];
	delete meshList[GEO_SPHERE];
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}