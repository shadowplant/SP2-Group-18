#include "Assignment2.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "shader.hpp"
#include "Application.h"
#include "MeshBuilder.h"
#include "Utility.h"
#include "LoadTGA.h"
#include "LoadOBJ.h"
#include <fstream>
#include <sstream>


Assignment2::Assignment2()
{
}

Assignment2::~Assignment2()
{
}

void Assignment2::InitObjsPos()
{
	// button [0 - 2]
	buttonPos.push_back(0.f);
	buttonPos.push_back(0.f);
	buttonPos.push_back(-100.f);

	// bportal [0 - 2]
	portalPos.push_back(-8.f);
	portalPos.push_back(10.f);
	portalPos.push_back(19.6f);

	// oportal [3 - 5]
	portalPos.push_back(-20.f);
	portalPos.push_back(10.f);
	portalPos.push_back(-59.4f);

	// glass 1 [0 - 2]
	objsPos.push_back(20.0f);
	objsPos.push_back(20.0f);
	objsPos.push_back(0.0f);

	// glass 2 [3 - 5]
	objsPos.push_back(-20.0f);
	objsPos.push_back(20.0f);
	objsPos.push_back(0.0f);

	// glass 3 [6 - 8]
	objsPos.push_back(0.0f);
	objsPos.push_back(20.0f);
	objsPos.push_back(20.0f);

	// glass 4 [9 - 11]
	objsPos.push_back(0.0f);
	objsPos.push_back(20.0f);
	objsPos.push_back(-20.0f);

	// toilet [12 - 14]
	objsPos.push_back(7.0f);
	objsPos.push_back(4.5f);
	objsPos.push_back(-15.0f);
	
	// nightstand [15 - 17]
	objsPos.push_back(-15.0f);
	objsPos.push_back(-1.f);
	objsPos.push_back(-15.0f);

	// cube [18 - 20]
	objsPos.push_back(50.f);
	objsPos.push_back(1.8f);
	objsPos.push_back(-80.f);

	// leftD [21 - 23]
	objsPos.push_back(-5.f);
	objsPos.push_back(10.f);
	objsPos.push_back(-60.f);

	// rightD [24 - 26]
	objsPos.push_back(5.f);
	objsPos.push_back(10.f);
	objsPos.push_back(-60.f);

	// wall 1 [27 - 29]
	objsPos.push_back(60.f);
	objsPos.push_back(40.f);
	objsPos.push_back(0.f);

	// wall 2 [30 - 32]
	objsPos.push_back(-60.f);
	objsPos.push_back(40.f);
	objsPos.push_back(0.f);

	// wall 3 [33 - 35]
	objsPos.push_back(0.f);
	objsPos.push_back(40.f);
	objsPos.push_back(60.f);

	// wall 4 [36 - 38]
	objsPos.push_back(35.f);
	objsPos.push_back(40.f);
	objsPos.push_back(-60.f);

	// wall 5 [39 - 41]
	objsPos.push_back(-35.f);
	objsPos.push_back(40.f);
	objsPos.push_back(-60.f);

	// leftD 1 [42 - 44]
	objsPos.push_back(60.f);
	objsPos.push_back(10.f);
	objsPos.push_back(-105.f);

	// rightD 1 [45 - 47]
	objsPos.push_back(60.f);
	objsPos.push_back(10.f);
	objsPos.push_back(-95.f);

	// wall 1 [48 - 50]
	objsPos.push_back(20.f);
	objsPos.push_back(40.f);
	objsPos.push_back(-120.f);

	// wall 2 [51 - 53]
	objsPos.push_back(-20.f);
	objsPos.push_back(40.f);
	objsPos.push_back(-90.f);

	// wall 3 [54 - 56]
	objsPos.push_back(60.f);
	objsPos.push_back(40.f);
	objsPos.push_back(-115.f);

	// wall 4 [57 - 59]
	objsPos.push_back(60.f);
	objsPos.push_back(40.f);
	objsPos.push_back(-70.f);

	// comcube 2 [60 - 62]
	objsPos.push_back(15.f);
	objsPos.push_back(1.8f);
	objsPos.push_back(-15.f);

	// sink [63 - 65]
	objsPos.push_back(-1.f);
	objsPos.push_back(-1.f);
	objsPos.push_back(-15.f);
}

void Assignment2::InitObjsSize()
{
	// button [0 - 2]
	buttonSize.push_back(10.0f);
	buttonSize.push_back(5.0f);
	buttonSize.push_back(10.0f);

	// bportal [0 - 2]
	portalSize.push_back(15.f);
	portalSize.push_back(20.f);
	portalSize.push_back(1.f);

	// oportal [3 - 5]
	portalSize.push_back(15.f);
	portalSize.push_back(20.f);
	portalSize.push_back(1.f);

	// glass 1 [0 - 2]
	objsSize.push_back(1.0f);
	objsSize.push_back(40.0f);
	objsSize.push_back(40.0f);

	// glass 2 [3 - 5]
	objsSize.push_back(1.0f);
	objsSize.push_back(40.0f);
	objsSize.push_back(40.0f);

	// glass 3 [6 - 8]
	objsSize.push_back(40.0f);
	objsSize.push_back(40.0f);
	objsSize.push_back(1.0f);

	// glass 4 [9 - 11]
	objsSize.push_back(40.0f);
	objsSize.push_back(40.0f);
	objsSize.push_back(1.0f);

	// toilet [12 - 14]
	objsSize.push_back(1.0f);
	objsSize.push_back(1.0f);
	objsSize.push_back(1.0f);

	// nightstand [15 - 17]
	objsSize.push_back(1.0f);
	objsSize.push_back(1.0f);
	objsSize.push_back(1.0f);

	// comcube [18 - 20]
	objsSize.push_back(1.0f);
	objsSize.push_back(1.0f);
	objsSize.push_back(1.0f);

	// leftD [21 - 23]
	objsSize.push_back(10.0f);
	objsSize.push_back(20.0f);
	objsSize.push_back(0.5f);

	// rightD [24 - 26]
	objsSize.push_back(10.0f);
	objsSize.push_back(20.0f);
	objsSize.push_back(0.5f);

	// wall 1 [27 - 29]
	objsSize.push_back(1.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(120.0f);

	// wall 2 [30 - 32]
	objsSize.push_back(1.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(120.0f);

	// wall 3 [33 - 35]
	objsSize.push_back(120.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(1.0f);

	// wall 4 [36 - 38]
	objsSize.push_back(50.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(1.0f);

	// wall 5 [39 - 41]
	objsSize.push_back(50.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(1.0f);

	// leftD 1 [42 - 44]
	objsSize.push_back(0.5f);
	objsSize.push_back(20.0f);
	objsSize.push_back(10.0f);

	// rightD 1 [45 - 47]
	objsSize.push_back(0.5f);
	objsSize.push_back(20.0f);
	objsSize.push_back(10.0f);

	// wall 1 [48 - 50]
	objsSize.push_back(80.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(1.0f);

	// wall 2 [51 - 53]
	objsSize.push_back(1.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(60.0f);

	// wall 3 [54 - 56]
	objsSize.push_back(1.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(10.0f);

	// wall 4 [57 - 59]
	objsSize.push_back(1.0f);
	objsSize.push_back(80.0f);
	objsSize.push_back(40.0f);

	// comcube 2 [60 - 62]
	objsSize.push_back(1.f);
	objsSize.push_back(1.f);
	objsSize.push_back(1.f);

	// sink [63 - 65]
	objsSize.push_back(3.f);
	objsSize.push_back(3.f);
	objsSize.push_back(3.f);
}

void Assignment2::InitModel()
{
	//center
	centerRotateX = 0;
	centerRotateY = 90;
	centerRotateZ = 0;
	centerTranslateX = 1;
	centerTranslateY = 8.5;
	centerTranslateZ = 5;

	//head
	headRotateX = 0;
	headRotateY = 0;
	headRotateX = 0;
	headTranslateX = 0;
	headTranslateY = 0;
	headTranslateZ = 0;

	//left
	LshoulderRotateX = 0;
	LshoulderRotateY = 0;
	LshoulderRotateZ = 0;
	LelbowRotateX = 0;
	LelbowRotateY = 0;
	LelbowRotateZ = 0;
	LhandRotateX = 0;
	LhandRotateY = 0;
	LhandRotateZ = 0;
	Lthumb1Rotate = 0;
	Lthumb2Rotate = 10;
	Lindex1Rotate = 0;
	Lindex2Rotate = 20;
	Lindex3Rotate = 20;
	Lmiddle1Rotate = 0;
	Lmiddle2Rotate = 20;
	Lmiddle3Rotate = 20;
	Lring1Rotate = 0;
	Lring2Rotate = 20;
	Lring3Rotate = 20;
	LthighRotateX = 0;
	LthighRotateY = 0;
	LthighRotateZ = 0;
	LkneeRotateX = 0;
	LkneeRotateY = 0;
	LkneeRotateZ = 0;
	LfootRotate = 0;

	//right
	RshoulderRotateX = 0;
	RshoulderRotateY = 0;
	RshoulderRotateZ = 0;
	RelbowRotateX = 0;
	RelbowRotateY = 0;
	RelbowRotateZ = 0;
	RhandRotateX = 0;
	RhandRotateY = 0;
	RhandRotateZ = 0;
	Rthumb1Rotate = 0;
	Rthumb2Rotate = -10;
	Rindex1Rotate = 0;
	Rindex2Rotate = 20;
	Rindex3Rotate = 20;
	Rmiddle1Rotate = 0;
	Rmiddle2Rotate = 20;
	Rmiddle3Rotate = 20;
	Rring1Rotate = 0;
	Rring2Rotate = 20;
	Rring3Rotate = 20;
	RthighRotateX = 0;
	RthighRotateY = 0;
	RthighRotateZ = 0;
	RkneeRotateX = 0;
	RkneeRotateY = 0;
	RkneeRotateZ = 0;
	RfootRotate = 0;
}

void Assignment2::Init()
{
	// Init VBO here
	InitObjsPos();
	InitObjsSize();
	InitModel();

	pickup = false;

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights"); //in case you missed out practical 7
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");

	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");;
	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
	m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
	m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
	m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
	m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
	m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
	m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
	m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
	m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
	m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
	m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");

	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	glUseProgram(m_programID);
	glUniform1i(m_parameters[U_NUMLIGHTS], 4);

	light[0].type = Light::LIGHT_POINT;
	light[0].position.Set(0, 30, 0);
	light[0].color.Set(1, 1, 1);
	light[0].power = 1;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 3.f;
	light[0].spotDirection.Set(0.f, 1.f, 0.f);

	light[1].type = Light::LIGHT_POINT;
	light[1].position.Set(1, 30, -100);
	light[1].color.Set(1, 1, 1);
	light[1].power = 1;
	light[1].kC = 1.f;
	light[1].kL = 0.01f;
	light[1].kQ = 0.001f;
	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
	light[1].cosInner = cos(Math::DegreeToRadian(30));
	light[1].exponent = 3.f;
	light[1].spotDirection.Set(0.f, 1.f, 0.f);

	light[2].type = Light::LIGHT_SPOT;
	light[2].position.Set(50, 50, -80);
	light[2].color.Set(1, 1, 1);
	light[2].power = 1;
	light[2].kC = 1.f;
	light[2].kL = 0.01f;
	light[2].kQ = 0.001f;
	light[2].cosCutoff = cos(Math::DegreeToRadian(10));
	light[2].cosInner = cos(Math::DegreeToRadian(30));
	light[2].exponent = 3.f;
	light[2].spotDirection.Set(0.f, 1.f, 0.f);

	light[3].type = Light::LIGHT_SPOT;
	light[3].position.Set(50, 50, -80);
	light[3].color.Set(1, 1, 1);
	light[3].power = 1;
	light[3].kC = 1.f;
	light[3].kL = 0.01f;
	light[3].kQ = 0.001f;
	light[3].cosCutoff = cos(Math::DegreeToRadian(10));
	light[3].cosInner = cos(Math::DegreeToRadian(30));
	light[3].exponent = 3.f;
	light[3].spotDirection.Set(0.f, 1.f, 0.f);

	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

	glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].color.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);

	glUniform1i(m_parameters[U_LIGHT2_TYPE], light[2].type);
	glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &light[2].color.r);
	glUniform1f(m_parameters[U_LIGHT2_POWER], light[2].power);
	glUniform1f(m_parameters[U_LIGHT2_KC], light[2].kC);
	glUniform1f(m_parameters[U_LIGHT2_KL], light[2].kL);
	glUniform1f(m_parameters[U_LIGHT2_KQ], light[2].kQ);
	glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], light[2].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT2_COSINNER], light[2].cosInner);
	glUniform1f(m_parameters[U_LIGHT2_EXPONENT], light[2].exponent);

	glUniform1i(m_parameters[U_LIGHT3_TYPE], light[3].type);
	glUniform3fv(m_parameters[U_LIGHT3_COLOR], 1, &light[3].color.r);
	glUniform1f(m_parameters[U_LIGHT3_POWER], light[3].power);
	glUniform1f(m_parameters[U_LIGHT3_KC], light[3].kC);
	glUniform1f(m_parameters[U_LIGHT3_KL], light[3].kL);
	glUniform1f(m_parameters[U_LIGHT3_KQ], light[3].kQ);
	glUniform1f(m_parameters[U_LIGHT3_COSCUTOFF], light[3].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT3_COSINNER], light[3].cosInner);
	glUniform1f(m_parameters[U_LIGHT3_EXPONENT], light[3].exponent);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);


	camera.Init(Vector3(1, 9.5, 5), Vector3(0, 9.5, 1), Vector3(0, 1, 0));

	for (int i = 0; i < NUM_GEOMETRY; i++)	meshList[i] = nullptr;
	
	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_FRONT]->textureID = LoadTGA("Image//front.tga");
	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BACK]->textureID = LoadTGA("Image//back.tga");
	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_LEFT]->textureID = LoadTGA("Image//left.tga");
	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//right.tga");
	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_TOP]->textureID = LoadTGA("Image//top.tga");
	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//bottom.tga");

	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("axes", 1000, 1000, 1000);
	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("light", Color(1, 1, 1), 50, 100);

	meshList[GEO_SPHERE] = MeshBuilder::GenerateSphere("sphere", Color(1, 1, 1), 50, 100);
	meshList[GEO_HEMISPHERE] = MeshBuilder::GenerateHemiSphere("hemisphere", Color(1, 1, 1), 50, 100);
	meshList[GEO_TORUS] = MeshBuilder::GenerateTorus("torus", Color(0.7, 0.7, 0.7), 50, 50, 15, 1);
	meshList[GEO_CYLINDER] = MeshBuilder::GenerateCylinder("cylinder", Color(0.1, 0.1, 0.1), 50, 1);

	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("light ball", Color(1, 1, 1), 50, 100);

	meshList[GEO_CUBE] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);

	meshList[GEO_CONE] = MeshBuilder::GenerateCone("cone", Color(1, 0.8196, 0.8627), 50.f, 1.f, 1.f);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//DimboFont.tga");

	meshList[GEO_GROUND] = MeshBuilder::GenerateFloor("floor", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_GROUND]->textureID = LoadTGA("Image//floorTile.tga");

	meshList[GEO_BPORTAL] = MeshBuilder::GenerateQuad("bportal", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BPORTAL]->textureID = LoadTGA("Image//bluePortal.tga");

	meshList[GEO_OPORTAL] = MeshBuilder::GenerateQuad("oportal", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_OPORTAL]->textureID = LoadTGA("Image//orangePortal.tga");

	meshList[GEO_PERSON] = MeshBuilder::GenerateQuad("person", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_PERSON]->textureID = LoadTGA("Image//Portalperson.tga");

	meshList[GEO_EXIT] = MeshBuilder::GenerateQuad("person", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_EXIT]->textureID = LoadTGA("Image//Portalexit.tga");

	meshList[GEO_WALL] = MeshBuilder::GenerateWall("wall", Color(1, 1, 1), 1.f, 1.f, 1.f);
	meshList[GEO_WALL]->textureID = LoadTGA("Image//wall5.tga");

	meshList[GEO_DOOR] = MeshBuilder::GenerateCube("door", Color(1, 1, 1), 1.f, 1.f, 1.f);
	meshList[GEO_DOOR]->textureID = LoadTGA("Image//door.tga");

	meshList[GEO_GLASS] = MeshBuilder::GenerateCube("glass", Color(1, 1, 1), 1, 1, 1);
	meshList[GEO_GLASS]->textureID = LoadTGA("Image//glass.tga");

	meshList[GEO_BED] = MeshBuilder::GenerateOBJMTL("mattress", "OBJ//mattress.obj", "OBJ//mattress.mtl");
	meshList[GEO_BED]->textureID = LoadTGA("Image//Mattress_02_UV_H_CM_1.tga");

	meshList[GEO_RADIO] = MeshBuilder::GenerateOBJMTL("radio", "OBJ//Radio.obj", "OBJ//Radio.mtl");
	meshList[GEO_RADIO]->textureID = LoadTGA("Image//Radio.tga");

	meshList[GEO_TOILET] = MeshBuilder::GenerateOBJMTL("toilet", "OBJ//toilet.obj", "OBJ//toilet.mtl");
	meshList[GEO_TOILET]->textureID = LoadTGA("Image//toilet.tga");

	meshList[GEO_SINK] = MeshBuilder::GenerateOBJMTL("sink", "OBJ//sink.obj", "OBJ//sink.mtl");
	meshList[GEO_SINK]->textureID = LoadTGA("Image//sink.tga");

	meshList[GEO_NIGHTSTAND] = MeshBuilder::GenerateOBJMTL("BTG", "OBJ//BTG.obj", "OBJ//BTG.mtl");
	meshList[GEO_NIGHTSTAND]->textureID = LoadTGA("Image//wood.tga");

	meshList[GEO_COMCUBE] = MeshBuilder::GenerateOBJMTL("comcube", "OBJ//cube.obj", "OBJ//cube.mtl");
	meshList[GEO_COMCUBE]->textureID = LoadTGA("Image//DefaultMaterial_albedo.tga");

	meshList[GEO_BUTTON] = MeshBuilder::GenerateCylinder("cylinder", Color(1, 0, 0), 50, 1);



	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	glEnable(GL_DEPTH_TEST);

	Mesh::SetMaterialLoc(m_parameters[U_MATERIAL_AMBIENT], m_parameters[U_MATERIAL_DIFFUSE], m_parameters[U_MATERIAL_SPECULAR], m_parameters[U_MATERIAL_SHININESS]);

	bLightEnabled = true;

	FPS = 0;

	textMaxWidth = 64; //initial value

	//for text spacing (check)
	const char* file_path;
	file_path = "Image//FontData.csv"; //name of font data csv file
	fileStream.open(file_path, std::ios::binary);
	if (!fileStream.is_open())
	{
		std::cout << "Impossible to open " << file_path << ". Are you in the right directory ?\n";
	}
	else {
		while (!fileStream.eof()) { //took from LoadOBJ
			std::string buf;
			std::getline(fileStream, buf, ' ');
			if (buf == "Char") {
				std::getline(fileStream, buf, ' ');
				unsigned i = stoi(buf);
				std::getline(fileStream, buf, ',');
				if (buf == "Base Width") {
					std::getline(fileStream, buf);
					unsigned width = stoi(buf);
					textSpacing[i] = width;
				}
				else {
					std::getline(fileStream, buf);
				}
			}
			else if (buf == "Cell") {
				std::getline(fileStream, buf, ',');
				if (buf == "Width") {
					std::getline(fileStream, buf);
					textMaxWidth = stoi(buf);
				}
				else {
					std::getline(fileStream, buf);
				}
			}
			else {
				std::getline(fileStream, buf);
			}
		}
		fileStream.close();
	}
}

void Assignment2::Update(double dt)
{
	camera.Update(dt, objsPos, objsSize);
	FPS = 1 / (float)dt;

	view = (camera.target - camera.position).Normalized();

	right = view.Cross(camera.up);
	right.y = 0;
	right.Normalize();


	float LSPEED = 10.0;
	static int maxShoulder = 0;
	static int maxThigh = 0;
	static int counter = 0;
	static int spin = 0;
	static int startSpin = 0;
	static int timer = 0;
	static int temp = 0;
	static float CAMERA_SPEED = 30.f;

	/*if (Application::IsKeyPressed('I'))	light[0].position.z -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('K'))	light[0].position.z += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('J'))	light[0].position.x -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('L'))	light[0].position.x += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('O'))	light[0].position.y -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('P'))	light[0].position.y += (float)(LSPEED * dt);*/

	if (Application::IsKeyPressed('1')) glEnable(GL_CULL_FACE);
	if (Application::IsKeyPressed('2')) glDisable(GL_CULL_FACE);
	if (Application::IsKeyPressed('3')) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if (Application::IsKeyPressed('4')) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
	if (Application::IsKeyPressed('5'))
	{
		light[0].type = Light::LIGHT_POINT;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	}
	else if (Application::IsKeyPressed('6'))
	{
		light[0].type = Light::LIGHT_DIRECTIONAL;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	}
	else if (Application::IsKeyPressed('7'))
	{
		light[0].type = Light::LIGHT_SPOT;
		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	}
	if (Application::IsKeyPressed('9'))		 bLightEnabled = false;
	else if (Application::IsKeyPressed('0')) bLightEnabled = true;
	
	//walk forward
	if (Application::IsKeyPressed('W'))
	{
		centerTranslateX = camera.position.x;
		centerTranslateY = camera.position.y;
		centerTranslateZ = camera.position.z;

		//legs
		if (maxThigh == 1)
		{
			LthighRotateZ += (float)(100 * dt);
			if (LkneeRotateZ > -30)
			{
				LkneeRotateZ -= (float)(140 * dt);
			}
			if (RkneeRotateZ < 0)
			{
				RkneeRotateZ += (float)(140 * dt);
			}
			if (LthighRotateZ >= 30)
			{
				maxThigh = 0;
			}
			//arm
			if (LelbowRotateZ > 0)
			{
				LelbowRotateZ -= (float)(50 * dt);
			}
			if (RelbowRotateZ < 30)
			{
				RelbowRotateZ += (float)(50 * dt);
			}
			if (LshoulderRotateZ > -20)
			{
				LshoulderRotateZ -= (float)(50 * dt);
			}
		}
		if (maxThigh == 0)
		{
			LthighRotateZ -= (float)(100 * dt);
			if (LkneeRotateZ < 0)
			{
				LkneeRotateZ += (float)(140 * dt);
			}
			if (RkneeRotateZ > -30)
			{
				RkneeRotateZ -= (float)(140 * dt);
			}
			if (LthighRotateZ <= -30)
			{
				maxThigh = 1;
			}
			//arm
			if (LelbowRotateZ < 30)
			{
				LelbowRotateZ += (float)(50 * dt);
			}
			if (RelbowRotateZ > 0)
			{
				RelbowRotateZ -= (float)(50 * dt);
			}
			if (LshoulderRotateZ < 20)
			{
				LshoulderRotateZ += (float)(50 * dt);
			}
		}
		RthighRotateZ = -LthighRotateZ;
		RshoulderRotateZ = -LshoulderRotateZ;
	}
	//walk left
	else if (Application::IsKeyPressed('A'))
	{
		centerTranslateX = camera.position.x;
		centerTranslateY = camera.position.y;
		centerTranslateZ = camera.position.z;
		//legs
		if (maxThigh == 1)
		{
			LthighRotateZ += (float)(100 * dt);
			if (LkneeRotateZ > -30)
			{
				LkneeRotateZ -= (float)(140 * dt);
			}
			if (RkneeRotateZ < 0)
			{
				RkneeRotateZ += (float)(140 * dt);
			}
			if (LthighRotateZ >= 30)
			{
				maxThigh = 0;
			}
			//arm
			if (LelbowRotateZ > 0)
			{
				LelbowRotateZ -= (float)(50 * dt);
			}
			if (RelbowRotateZ < 30)
			{
				RelbowRotateZ += (float)(50 * dt);
			}
			if (LshoulderRotateZ > -20)
			{
				LshoulderRotateZ -= (float)(50 * dt);
			}
		}
		if (maxThigh == 0)
		{
			LthighRotateZ -= (float)(100 * dt);
			if (LkneeRotateZ < 0)
			{
				LkneeRotateZ += (float)(140 * dt);
			}
			if (RkneeRotateZ > -30)
			{
				RkneeRotateZ -= (float)(140 * dt);
			}
			if (LthighRotateZ <= -30)
			{
				maxThigh = 1;
			}
			//arm
			if (LelbowRotateZ < 30)
			{
				LelbowRotateZ += (float)(50 * dt);
			}
			if (RelbowRotateZ > 0)
			{
				RelbowRotateZ -= (float)(50 * dt);
			}
			if (LshoulderRotateZ < 20)
			{
				LshoulderRotateZ += (float)(50 * dt);
			}
		}
		RthighRotateZ = -LthighRotateZ;
		RshoulderRotateZ = -LshoulderRotateZ;
	}
	//moonwalk backwards
	else if (Application::IsKeyPressed('S'))
	{
		centerTranslateX = camera.position.x;
		centerTranslateY = camera.position.y;
		centerTranslateZ = camera.position.z;
		//legs
		if (maxThigh == 1)
		{
			LthighRotateZ += (float)(100 * dt);
			if (LkneeRotateZ > -30)
			{
				LkneeRotateZ -= (float)(140 * dt);
			}
			if (RkneeRotateZ < 0)
			{
				RkneeRotateZ += (float)(140 * dt);
			}
			if (LthighRotateZ >= 30)
			{
				maxThigh = 0;
			}
			//arm
			if (LelbowRotateZ > 0)
			{
				LelbowRotateZ -= (float)(50 * dt);
			}
			if (RelbowRotateZ < 30)
			{
				RelbowRotateZ += (float)(50 * dt);
			}
			if (LshoulderRotateZ > -20)
			{
				LshoulderRotateZ -= (float)(50 * dt);
			}
		}
		if (maxThigh == 0)
		{
			LthighRotateZ -= (float)(100 * dt);
			if (LkneeRotateZ < 0)
			{
				LkneeRotateZ += (float)(140 * dt);
			}
			if (RkneeRotateZ > -30)
			{
				RkneeRotateZ -= (float)(140 * dt);
			}
			if (LthighRotateZ <= -30)
			{
				maxThigh = 1;
			}
			//arm
			if (LelbowRotateZ < 30)
			{
				LelbowRotateZ += (float)(50 * dt);
			}
			if (RelbowRotateZ > 0)
			{
				RelbowRotateZ -= (float)(50 * dt);
			}
			if (LshoulderRotateZ < 20)
			{
				LshoulderRotateZ += (float)(50 * dt);
			}
		}
		RthighRotateZ = -LthighRotateZ;
		RshoulderRotateZ = -LshoulderRotateZ;
	}
	//sidestep right
	else if (Application::IsKeyPressed('D'))
	{
		centerTranslateX = camera.position.x;
		centerTranslateY = camera.position.y;
		centerTranslateZ = camera.position.z;

		//legs
		if (maxThigh == 1)
		{
			LthighRotateZ += (float)(100 * dt);
			if (LkneeRotateZ > -30)
			{
				LkneeRotateZ -= (float)(140 * dt);
			}
			if (RkneeRotateZ < 0)
			{
				RkneeRotateZ += (float)(140 * dt);
			}
			if (LthighRotateZ >= 30)
			{
				maxThigh = 0;
			}
			//arm
			if (LelbowRotateZ > 0)
			{
				LelbowRotateZ -= (float)(50 * dt);
			}
			if (RelbowRotateZ < 30)
			{
				RelbowRotateZ += (float)(50 * dt);
			}
			if (LshoulderRotateZ > -20)
			{
				LshoulderRotateZ -= (float)(50 * dt);
			}
		}
		if (maxThigh == 0)
		{
			LthighRotateZ -= (float)(100 * dt);
			if (LkneeRotateZ < 0)
			{
				LkneeRotateZ += (float)(140 * dt);
			}
			if (RkneeRotateZ > -30)
			{
				RkneeRotateZ -= (float)(140 * dt);
			}
			if (LthighRotateZ <= -30)
			{
				maxThigh = 1;
			}
			//arm
			if (LelbowRotateZ < 30)
			{
				LelbowRotateZ += (float)(50 * dt);
			}
			if (RelbowRotateZ > 0)
			{
				RelbowRotateZ -= (float)(50 * dt);
			}
			if (LshoulderRotateZ < 20)
			{
				LshoulderRotateZ += (float)(50 * dt);
			}
		}
		RthighRotateZ = -LthighRotateZ;
		RshoulderRotateZ = -LshoulderRotateZ;
	}
	
	if (Application::IsKeyPressed(VK_LEFT))
	{
		float yaw = 90.f * static_cast<float>(dt);
		centerRotateY += yaw;
	}
	if (Application::IsKeyPressed(VK_RIGHT))
	{
		float yaw = -90.f * static_cast<float>(dt);
		centerRotateY += yaw;
	}

	static bool pickupState = false;
	if (camera.isInRange(objsPos, objsSize, 18) == true)
	{
		if (Application::IsKeyPressed('E') && !pickupState)
		{
			pickupState = true;
			pickup = !pickup;
		}
		else if (!Application::IsKeyPressed('E') && pickupState)
		{
			pickupState = false;
		}
	}

	if (pickup == true)
	{
		objsPos[18] = camera.target.x + 3.1;
		objsPos[20] = camera.target.z + 3.1;
	}

	static bool pickupState1 = false;
	if (camera.isInRange(objsPos, objsSize, 60) == true)
	{
		if (Application::IsKeyPressed('E') && !pickupState1)
		{
			pickupState1 = true;
			pickup1 = !pickup1;
		}
		else if (!Application::IsKeyPressed('E') && pickupState1)
		{
			pickupState1 = false;
		}
	}

	if (pickup1 == true)
	{
		objsPos[60] = camera.target.x + 3.1;
		objsPos[62] = camera.target.z + 3.1;
	}
	// door 1
	{
		static bool doorState = false;
		if (camera.isInRange(objsPos, objsSize, 21) == true)
		{
			doorState = true;
		}
		else
			doorState = false;
		if (doorState == true)
		{
			if (objsPos[21] > -15.f)
			{
				objsPos[21] -= 10.f * dt;
			}
			if (objsPos[21] < -15.f)
			{
				objsPos[21] = -15.f;
			}
			if (objsPos[24] < 15.f)
			{
				objsPos[24] += 10.f * dt;
			}
			if (objsPos[24] > 15.f)
			{
				objsPos[24] = 15.f;
			}
		}
		else if (doorState == false)
		{
			if (objsPos[21] < -5.f)
			{
				objsPos[21] += 10.f * dt;
			}
			if (objsPos[21] > -5.f)
			{
				objsPos[21] = -5.f;
			}
			if (objsPos[24] > 5.f)
			{
				objsPos[24] -= 10.f * dt;
			}
			if (objsPos[24] < 5.f)
			{
				objsPos[24] = 5.f;
			}
		}
	}
	// button
	{
		static bool doorState1 = false;
		static bool buttonPressed = false;
		if (camera.isOnButton(buttonPos, buttonSize, 0) == true || camera.ObjIsOnButton(buttonPos, buttonSize, 0, objsPos[18], objsPos[20]) == true)
		{
			buttonPressed = true;
			doorState1 = true;
		}
		else if (camera.isOnButton(buttonPos, buttonSize, 0) == false && camera.ObjIsOnButton(buttonPos, buttonSize, 0, objsPos[18], objsPos[20]) == false)
		{
			buttonPressed = false;
			doorState1 = false;
		}
		if (buttonPressed == true)
		{
			if (buttonPos[1] > -2.5f)
			{
				buttonPos[1] -= 5.f * dt;
			}
			if (buttonPos[1] < -2.5f)
			{
				buttonPos[1] = -2.5f;
			}
		}
		else if (buttonPressed == false)
		{
			if (buttonPos[1] < 0.f)
			{
				buttonPos[1] += 5.f * dt;
			}
			if (buttonPos[1] > 0.f)
			{
				buttonPos[1] = 0.f;
			}
		}
		if (doorState1 == true)
		{
			if (objsPos[44] > -115.f)
			{
				objsPos[44] -= 10.f * dt;
			}
			if (objsPos[44] < -115.f)
			{
				objsPos[44] = -115.f;
			}
			if (objsPos[47] < -85.f)
			{
				objsPos[47] += 10.f * dt;
			}
			if (objsPos[47] > -85.f)
			{
				objsPos[47] = -85.f;
			}
		}
		else if (doorState1 == false)
		{
			if (objsPos[44] < -105.f)
			{
				objsPos[44] += 10.f * dt;
			}
			if (objsPos[44] > -105.f)
			{
				objsPos[44] = -105.f;
			}
			if (objsPos[47] > -95.f)
			{
				objsPos[47] -= 10.f * dt;
			}
			if (objsPos[47] < -95.f)
			{
				objsPos[47] = -95.f;
			}
		}
	}

	//portal
	{
		if (camera.inPortal(portalPos, portalSize, 0) == true)
		{
			camera.position.z = -55.f;
			camera.position.x = -20.f;
		}
		else if (camera.inPortal(portalPos, portalSize, 3) == true)
		{
			camera.position.z = 15.f;
			camera.position.x = -8.f;
		}
	}
}
void Assignment2::RenderSkybox() {
	const float OFFSET = 499;
	modelStack.PushMatrix();
	modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, -OFFSET);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_FRONT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, OFFSET);
	modelStack.Rotate(180, 0, 1, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_BACK], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-OFFSET, 0, 0);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_LEFT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(OFFSET, 0, 0);
	modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_RIGHT], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, OFFSET, 0);
	modelStack.Rotate(90, 1, 0, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_TOP], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, -OFFSET, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_BOTTOM], false);
	modelStack.PopMatrix();

	modelStack.PopMatrix();

}
void Assignment2::RenderMesh(Mesh* mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
	if (enableLight && bLightEnabled)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}
	if (mesh->textureID > 0) {
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else {
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	mesh->Render();
	if (mesh->textureID > 0) {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
void Assignment2::RenderText(Mesh* mesh, std::string text, Color color)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	float offset = 0.f;
	for (unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(offset, 0, i * 0.001f); //slightly increase z val
		offset += (textSpacing[(int)(text[i])] / (float)textMaxWidth);
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
}
void Assignment2::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if (!mesh || mesh->textureID <= 0) //Proper error check
		return;
	glDisable(GL_DEPTH_TEST); //uncomment for RenderTextOnScreen
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Translate(x, y, 0);
	modelStack.Scale(size, size, size);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	float offset = 0.f;
	for (unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(0.5f + offset, 0.5f, 0);
		offset += (textSpacing[(int)(text[i])] / (float)textMaxWidth);
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST); //uncomment for RenderTextOnScreen
}
void Assignment2::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (light[0].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if (light[0].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	}

	if (light[1].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(light[1].position.x, light[1].position.y, light[1].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if (light[1].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
	}

	if (light[2].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(light[2].position.x, light[2].position.y, light[2].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if (light[2].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[2].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
	}

	if (light[3].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(light[3].position.x, light[3].position.y, light[3].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT3_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if (light[3].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[3].position;
		glUniform3fv(m_parameters[U_LIGHT3_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * light[3].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT3_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * light[3].position;
		glUniform3fv(m_parameters[U_LIGHT3_POSITION], 1, &lightPosition_cameraspace.x);
	}

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	RenderSkybox();

	//RenderMesh(meshList[GEO_AXES], false);

	modelStack.PushMatrix();
	modelStack.Translate(light[0].position.x, light[0].position.y, light[0].position.z);
	modelStack.Scale(1, 1, 1);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(light[1].position.x, light[1].position.y, light[1].position.z);
	modelStack.Scale(1, 1, 1);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(light[2].position.x, light[2].position.y, light[2].position.z);
	modelStack.Scale(1, 1, 1);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(light[3].position.x, light[3].position.y, light[3].position.z);
	modelStack.Scale(1, 1, 1);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	
	//model
	modelStack.PushMatrix();
	{
		modelStack.Translate(centerTranslateX, centerTranslateY, centerTranslateZ);
		modelStack.Rotate(centerRotateX, 1, 0, 0);
		modelStack.Rotate(centerRotateY, 0, 1, 0);
		modelStack.Rotate(centerRotateZ, 0, 0, 1);
		modelStack.Scale(.8, .8, .8);


		// left shoulder mount
		modelStack.PushMatrix();
		meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		modelStack.Translate(0, 3, -2.5);
		modelStack.Rotate(0, 0, 0, 1);
		modelStack.Scale(1.6, 3.5, 0.3);
		RenderMesh(meshList[GEO_CUBE], true);
		modelStack.PopMatrix();

		// left connector
		modelStack.PushMatrix();
		meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
		meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		modelStack.Translate(0, 3.4, -3.);
		modelStack.Rotate(90, 90, 0, 1);
		modelStack.Scale(0.2, 1., 0.2);
		RenderMesh(meshList[GEO_CYLINDER], true);
		modelStack.PopMatrix();

		// left shoulder lower plate
		modelStack.PushMatrix();
		meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		modelStack.Translate(0, 1., -2.5);
		modelStack.Rotate(45, 0.5, 0, 1);
		modelStack.Scale(2., 2., 0.3);
		RenderMesh(meshList[GEO_CUBE], true);
		modelStack.PopMatrix();
		// right shoulder mount
		modelStack.PushMatrix();
		meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		modelStack.Translate(0, 3, 2.5);
		modelStack.Rotate(0, 0, 0, 1);
		modelStack.Scale(1.6, 3.5, 0.3);
		RenderMesh(meshList[GEO_CUBE], true);
		modelStack.PopMatrix();

		// right shoulder lower plate
		modelStack.PushMatrix();
		meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		modelStack.Translate(0, 1., 2.5);
		modelStack.Rotate(45, -0.5, 0, 1);
		modelStack.Scale(2., 2., 0.3);
		RenderMesh(meshList[GEO_CUBE], true);
		modelStack.PopMatrix();

		// right connector
		modelStack.PushMatrix();
		meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
		meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
		modelStack.Translate(0, 3.4, 3.);
		modelStack.Rotate(90, 90, 0, 1);
		modelStack.Scale(0.2, 1., 0.2);
		RenderMesh(meshList[GEO_CYLINDER], true);
		modelStack.PopMatrix();

		// head brace
		modelStack.PushMatrix();
		meshList[GEO_TORUS]->material.kDiffuse.Set(1.f, 1.f, 1.f);
		meshList[GEO_TORUS]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
		modelStack.Translate(-0.75, -1.45, 0);
		modelStack.Rotate(-30, 0, 0, 1);
		modelStack.Scale(.15, .15, .15);
		RenderMesh(meshList[GEO_TORUS], true);
		modelStack.PopMatrix();

		// head skeleton
		modelStack.PushMatrix();
		{
			meshList[GEO_SPHERE]->material.kDiffuse.Set(0.f, 1.f, 0.f);
			meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
			modelStack.Translate(headTranslateX, headTranslateY, headTranslateZ);
			modelStack.Rotate(headRotateX, 1, 0, 0);
			modelStack.Rotate(headRotateY, 0, 1, 0);
			modelStack.Rotate(headRotateZ, 0, 0, 1);
			modelStack.Scale(0.5, 0.5, 0.5);
			//RenderMesh(meshList[GEO_SPHERE], true);

			// eye
			modelStack.PushMatrix();
			meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(0.f, 1.f, 1.f);
			meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.0f, .6f, .6f);
			modelStack.Translate(4.99, 0, 0);
			modelStack.Rotate(270, 0, 0, 1);
			modelStack.Scale(1.5, 1.5, 1.5);
			//RenderMesh(meshList[GEO_HEMISPHERE], true);
			modelStack.PopMatrix();

			// eyelids
			modelStack.PushMatrix();
			meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
			modelStack.Translate(2.3, -1.1, 0);
			modelStack.Rotate(0, 0, 0, 1);
			modelStack.Scale(3, .9, 3);
			//RenderMesh(meshList[GEO_HEMISPHERE], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
			modelStack.Translate(2.3, 1.1, 0);
			modelStack.Rotate(180, 0, 0, 1);
			modelStack.Scale(3, .9, 3);
			//RenderMesh(meshList[GEO_HEMISPHERE], true);
			modelStack.PopMatrix();

			// head
			modelStack.PushMatrix();
			meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_SPHERE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
			meshList[GEO_SPHERE]->material.kShininess = 10.f;
			modelStack.Translate(0, 0, 0);
			modelStack.Rotate(0, 0, 0, 1);
			modelStack.Scale(5., 5., 5.);
			//RenderMesh(meshList[GEO_SPHERE], true);
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();// head end

		// left shoulder
		modelStack.PushMatrix();
		{
			meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
			modelStack.Translate(0, 3.5, -4);
			modelStack.Rotate(LshoulderRotateX, 1, 0, 0);
			modelStack.Rotate(LshoulderRotateY, 0, 1, 0);
			modelStack.Rotate(LshoulderRotateZ, 0, 0, 1);
			modelStack.Scale(.5, .5, .5);
			RenderMesh(meshList[GEO_SPHERE], true);

			// left shoulder plate
			modelStack.PushMatrix();
			meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
			modelStack.Translate(0, -0.5, -0.75);
			modelStack.Rotate(0, 0, 0, 1);
			modelStack.Scale(3, 5, 0.5);
			RenderMesh(meshList[GEO_CUBE], true);
			modelStack.PopMatrix();

			// left arm
			modelStack.PushMatrix();
			meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
			modelStack.Translate(0, -4., 0);
			modelStack.Rotate(0, 0, 0, 1);
			modelStack.Scale(0.5, 8., 0.5);
			RenderMesh(meshList[GEO_CYLINDER], true);
			modelStack.PopMatrix();

			// left elbow
			modelStack.PushMatrix();
			{
				meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
				modelStack.Translate(0, -8, 0);
				modelStack.Rotate(LelbowRotateX, 1, 0, 0);
				modelStack.Rotate(LelbowRotateY, 0, 1, 0);
				modelStack.Rotate(LelbowRotateZ, 0, 0, 1);
				modelStack.Scale(1, 1, 1);
				RenderMesh(meshList[GEO_SPHERE], true);

				// left forearm
				modelStack.PushMatrix();
				meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
				modelStack.Translate(0, -5.5, 0);
				modelStack.Rotate(0, 0, 0, 1);
				modelStack.Scale(0.5, 11., 0.5);
				RenderMesh(meshList[GEO_CYLINDER], true);
				modelStack.PopMatrix();

				//left hand
				modelStack.PushMatrix();
				{
					meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
					modelStack.Translate(0, -11, 0);
					modelStack.Rotate(LhandRotateX, 1, 0, 0);
					modelStack.Rotate(LhandRotateY, 0, 1, 0);
					modelStack.Rotate(LhandRotateZ, 0, 0, 1);
					modelStack.Scale(1, 1, 1);
					RenderMesh(meshList[GEO_SPHERE], true);

					//middle palmar digital
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(0, -0.9, -0.9);
						modelStack.Rotate(-Lmiddle1Rotate, 1, 0, 0);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -2.3, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 3.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -4.5, 0);
							modelStack.Rotate(-Lmiddle2Rotate, 1, 0, 0);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							// middle phalanx
							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -2.1, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 2.5, .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							// distal interphalangeal
							modelStack.PushMatrix();
							{
								meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
								modelStack.Translate(0, -4., 0);
								modelStack.Rotate(-Lmiddle3Rotate, 1, 0, 0);
								modelStack.Scale(1., 1., 1.);
								RenderMesh(meshList[GEO_SPHERE], true);

								// finger tip
								modelStack.PushMatrix();
								meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
								modelStack.Translate(0, -1.5, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(0.9, 1.5, .9);
								RenderMesh(meshList[GEO_CYLINDER], true);
								modelStack.PopMatrix();

								modelStack.PushMatrix();
								meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
								modelStack.Translate(0, -2.25, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(.9, .9, .9);
								RenderMesh(meshList[GEO_HEMISPHERE], true);
								modelStack.PopMatrix();

							}
							modelStack.PopMatrix();
						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();

					//index palmar digital
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(0.6, -0.7, -0.85);
						modelStack.Rotate(-Lindex1Rotate, 1, 0, 0);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -2.3, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 3.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -4.5, 0);
							modelStack.Rotate(-Lindex2Rotate, 1, 0, 0);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							// middle phalanx
							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -2.1, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 2.5, .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							// distal interphalangeal
							modelStack.PushMatrix();
							{
								meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
								modelStack.Translate(0, -4., 0);
								modelStack.Rotate(-Lindex3Rotate, 1, 0, 0);
								modelStack.Scale(1., 1., 1.);
								RenderMesh(meshList[GEO_SPHERE], true);

								// finger tip
								modelStack.PushMatrix();
								meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
								modelStack.Translate(0, -1.5, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(0.9, 1.5, .9);
								RenderMesh(meshList[GEO_CYLINDER], true);
								modelStack.PopMatrix();

								modelStack.PushMatrix();
								meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
								modelStack.Translate(0, -2.25, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(.9, .9, .9);
								RenderMesh(meshList[GEO_HEMISPHERE], true);
								modelStack.PopMatrix();

							}
							modelStack.PopMatrix();
						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();

					//ring palmar digital
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(-0.6, -0.7, -0.85);
						modelStack.Rotate(-Lring1Rotate, 1, 0, 0);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -2.3, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 3.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -4.5, 0);
							modelStack.Rotate(-Lring2Rotate, 1, 0, 0);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							// middle phalanx
							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -2.1, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 2.5, .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							// distal interphalangeal
							modelStack.PushMatrix();
							{
								meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
								modelStack.Translate(0, -4., 0);
								modelStack.Rotate(-Lring3Rotate, 1, 0, 0);
								modelStack.Scale(1., 1., 1.);
								RenderMesh(meshList[GEO_SPHERE], true);

								// finger tip
								modelStack.PushMatrix();
								meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
								modelStack.Translate(0, -1.5, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(0.9, 1.5, .9);
								RenderMesh(meshList[GEO_CYLINDER], true);
								modelStack.PopMatrix();

								modelStack.PushMatrix();
								meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
								modelStack.Translate(0, -2.25, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(.9, .9, .9);
								RenderMesh(meshList[GEO_HEMISPHERE], true);
								modelStack.PopMatrix();

							}
							modelStack.PopMatrix();
						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();

					//thumb
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(1.2, -0.4, 0);
						modelStack.Rotate(-Lthumb1Rotate, 0, 0, 1);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -1.7, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 2.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -3.4, 0);
							modelStack.Rotate(-Lthumb2Rotate, 0, 0, 1);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -1.5, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 1.5, .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							modelStack.PushMatrix();
							meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
							modelStack.Translate(0, -2.25, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(.9, .9, .9);
							RenderMesh(meshList[GEO_HEMISPHERE], true);
							modelStack.PopMatrix();
						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();
				}
				modelStack.PopMatrix(); // left hand end
			}
			modelStack.PopMatrix(); // left elbow end
		}
		modelStack.PopMatrix(); // left shoulder end

		modelStack.PushMatrix();// right shoulder
		{
			meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
			modelStack.Translate(0, 3.5, 4);
			modelStack.Rotate(RshoulderRotateX, 1, 0, 0);
			modelStack.Rotate(RshoulderRotateY, 0, 1, 0);
			modelStack.Rotate(RshoulderRotateZ, 0, 0, 1);
			modelStack.Scale(.5, .5, .5);
			RenderMesh(meshList[GEO_SPHERE], true);


			modelStack.PushMatrix();// right shoulder plate
			{
				meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
				modelStack.Translate(0, -0.5, 0.75);
				modelStack.Rotate(0, 0, 0, 1);
				modelStack.Scale(3, 5, 0.5);
				RenderMesh(meshList[GEO_CUBE], true);
			}
			modelStack.PopMatrix();

			modelStack.PushMatrix();// right arm
			{
				meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
				modelStack.Translate(0, -4., 0);
				modelStack.Rotate(0, 0, 0, 1);
				modelStack.Scale(0.5, 8., 0.5);
				RenderMesh(meshList[GEO_CYLINDER], true);
			}
			modelStack.PopMatrix();

			modelStack.PushMatrix();// right elbow
			{
				meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
				modelStack.Translate(0, -8, 0);
				modelStack.Rotate(RelbowRotateX, 1, 0, 0);
				modelStack.Rotate(RelbowRotateY, 0, 1, 0);
				modelStack.Rotate(RelbowRotateZ, 0, 0, 1);
				modelStack.Scale(1, 1, 1);
				RenderMesh(meshList[GEO_SPHERE], true);

				modelStack.PushMatrix();// right forearm
				{
					meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
					modelStack.Translate(0, -5.5, 0);
					modelStack.Rotate(0, 0, 0, 1);
					modelStack.Scale(0.5, 11., 0.5);
					RenderMesh(meshList[GEO_CYLINDER], true);
				}
				modelStack.PopMatrix();

				modelStack.PushMatrix();//right hand
				{
					meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
					modelStack.Translate(0, -11, 0);
					modelStack.Rotate(RhandRotateX, 1, 0, 0);
					modelStack.Rotate(RhandRotateY, 0, 1, 0);
					modelStack.Rotate(RhandRotateZ, 0, 0, 1);
					modelStack.Scale(1, 1, 1);
					RenderMesh(meshList[GEO_SPHERE], true);

					//middle palmar digital
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(0, -0.9, 0.9);
						modelStack.Rotate(Rmiddle1Rotate, 1, 0, 0);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -2.3, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 3.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -4.5, 0);
							modelStack.Rotate(Rmiddle2Rotate, 1, 0, 0);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							// middle phalanx
							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -2.1, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 2.5, .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							// distal interphalangeal
							modelStack.PushMatrix();
							{
								meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
								modelStack.Translate(0, -4., 0);
								modelStack.Rotate(Rmiddle3Rotate, 1, 0, 0);
								modelStack.Scale(1., 1., 1.);
								RenderMesh(meshList[GEO_SPHERE], true);

								// finger tip
								modelStack.PushMatrix();
								meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
								modelStack.Translate(0, -1.5, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(0.9, 1.5, .9);
								RenderMesh(meshList[GEO_CYLINDER], true);
								modelStack.PopMatrix();

								modelStack.PushMatrix();
								meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
								modelStack.Translate(0, -2.25, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(.9, .9, .9);
								RenderMesh(meshList[GEO_HEMISPHERE], true);
								modelStack.PopMatrix();

							}
							modelStack.PopMatrix();
						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();

					//index palmar digital
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(0.6, -0.7, 0.9);
						modelStack.Rotate(Rindex1Rotate, 1, 0, 0);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -2.3, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 3.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -4.5, 0);
							modelStack.Rotate(Rindex2Rotate, 1, 0, 0);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							// middle phalanx
							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -2.1, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 2.5, .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							// distal interphalangeal
							modelStack.PushMatrix();
							{
								meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
								modelStack.Translate(0, -4., 0);
								modelStack.Rotate(Rindex3Rotate, 1, 0, 0);
								modelStack.Scale(1., 1., 1.);
								RenderMesh(meshList[GEO_SPHERE], true);

								// finger tip
								modelStack.PushMatrix();
								meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
								modelStack.Translate(0, -1.5, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(0.9, 1.5, .9);
								RenderMesh(meshList[GEO_CYLINDER], true);
								modelStack.PopMatrix();

								modelStack.PushMatrix();
								meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
								modelStack.Translate(0, -2.25, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(.9, .9, .9);
								RenderMesh(meshList[GEO_HEMISPHERE], true);
								modelStack.PopMatrix();

							}
							modelStack.PopMatrix();
						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();

					//ring palmar digital
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(-0.6, -0.7, 0.9);
						modelStack.Rotate(Rring1Rotate, 1, 0, 0);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -2.3, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 3.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -4.5, 0);
							modelStack.Rotate(Rring2Rotate, 1, 0, 0);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							// middle phalanx
							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -2.1, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 2.5, .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							// distal interphalangeal
							modelStack.PushMatrix();
							{
								meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
								modelStack.Translate(0, -4., 0);
								modelStack.Rotate(Rring3Rotate, 1, 0, 0);
								modelStack.Scale(1., 1., 1.);
								RenderMesh(meshList[GEO_SPHERE], true);

								// finger tip
								modelStack.PushMatrix();
								meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
								modelStack.Translate(0, -1.5, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(0.9, 1.5, .9);
								RenderMesh(meshList[GEO_CYLINDER], true);
								modelStack.PopMatrix();

								modelStack.PushMatrix();
								meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
								meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
								modelStack.Translate(0, -2.25, 0);
								modelStack.Rotate(0, 0, 0, 1);
								modelStack.Scale(.9, .9, .9);
								RenderMesh(meshList[GEO_HEMISPHERE], true);
								modelStack.PopMatrix();

							}
							modelStack.PopMatrix();
						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();

					//thumb
					modelStack.PushMatrix();
					{
						meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
						modelStack.Translate(1.2, -0.4, 0);
						modelStack.Rotate(Rthumb1Rotate, 0, 0, 1);
						modelStack.Scale(0.3, 0.3, 0.3);
						RenderMesh(meshList[GEO_SPHERE], true);

						// middle proximal phalanx
						modelStack.PushMatrix();
						meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
						meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
						modelStack.Translate(0, -1.7, 0);
						modelStack.Rotate(0, 0, 0, 1);
						modelStack.Scale(0.9, 2.0, 0.9);
						RenderMesh(meshList[GEO_CYLINDER], true);
						modelStack.PopMatrix();

						// proximal interphalangeal
						modelStack.PushMatrix();
						{
							meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
							modelStack.Translate(0, -3.4, 0);
							modelStack.Rotate(-Rthumb2Rotate, 0, 0, 1);
							modelStack.Scale(1., 1., 1.);
							RenderMesh(meshList[GEO_SPHERE], true);

							// middle phalanx
							modelStack.PushMatrix();
							meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_CYLINDER]->material.kAmbient.Set(0.9f, 0.9f, 0.9f);
							modelStack.Translate(0, -1.7, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(0.9, 2., .9);
							RenderMesh(meshList[GEO_CYLINDER], true);
							modelStack.PopMatrix();

							modelStack.PushMatrix();
							meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
							meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
							modelStack.Translate(0, -2.75, 0);
							modelStack.Rotate(0, 0, 0, 1);
							modelStack.Scale(.9, .9, .9);
							RenderMesh(meshList[GEO_HEMISPHERE], true);
							modelStack.PopMatrix();


						}
						modelStack.PopMatrix();
					}
					modelStack.PopMatrix();
				}
				modelStack.PopMatrix(); // right hand end
			}
			modelStack.PopMatrix(); // right elbow end
		}
		modelStack.PopMatrix(); // right shoulder end

		modelStack.PushMatrix();// left thigh joint
		{
			meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
			modelStack.Translate(0, -1.5, -2.6);
			modelStack.Rotate(LthighRotateX, 1, 0, 0);
			modelStack.Rotate(LthighRotateY, 0, 1, 0);
			modelStack.Rotate(LthighRotateZ, 0, 0, 1);
			modelStack.Scale(.5, .5, .5);
			RenderMesh(meshList[GEO_SPHERE], true);

			modelStack.PushMatrix();// left thigh plate
			meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
			modelStack.Translate(0, -2., 1.3);
			modelStack.Rotate(-20, 45, -10, 1);
			modelStack.Scale(3., 7., 0.6);
			RenderMesh(meshList[GEO_CUBE], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();// left thigh
			{
				meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
				modelStack.Translate(0, -5., 0);
				modelStack.Rotate(0, 0, 0, 1);
				modelStack.Scale(0.5, 10., 0.5);
				RenderMesh(meshList[GEO_CYLINDER], true);
			}
			modelStack.PopMatrix();

			modelStack.PushMatrix();// left knee
			{
				meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
				modelStack.Translate(0, -10, 0);
				modelStack.Rotate(LkneeRotateX, 1, 0, 0);
				modelStack.Rotate(LkneeRotateY, 0, 1, 0);
				modelStack.Rotate(LkneeRotateZ, 0, 0, 1);
				modelStack.Scale(1., 1., 1.);
				RenderMesh(meshList[GEO_SPHERE], true);

				modelStack.PushMatrix();// left calf
				{
					meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
					modelStack.Translate(0, -5., 0);
					modelStack.Rotate(0, 0, 0, 1);
					modelStack.Scale(0.5, 10., 0.5);
					RenderMesh(meshList[GEO_CYLINDER], true);
				}
				modelStack.PopMatrix();

				modelStack.PushMatrix();// left foot
				{
					meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
					modelStack.Translate(0, -10, 0);
					modelStack.Rotate(LfootRotate, 0, 0, 1);
					modelStack.Scale(1., 1., 1.);
					RenderMesh(meshList[GEO_SPHERE], true);

					modelStack.PushMatrix(); //foot
					meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
					modelStack.Translate(1.5, 0, 0);
					modelStack.Rotate(90, 0, 0, 1);
					modelStack.Scale(1.8, 4.5, 2.5);
					RenderMesh(meshList[GEO_CUBE], true);
					modelStack.PopMatrix();
				}
				modelStack.PopMatrix(); // left foot end
			}
			modelStack.PopMatrix(); // left knee end
		}
		modelStack.PopMatrix(); // left thigh joint end

		modelStack.PushMatrix();// right thigh joint
		{
			meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
			modelStack.Translate(0, -1.5, 2.6);
			modelStack.Rotate(RthighRotateX, 1, 0, 0);
			modelStack.Rotate(RthighRotateY, 0, 1, 0);
			modelStack.Rotate(RthighRotateZ, 0, 0, 1);
			modelStack.Scale(.5, .5, .5);
			RenderMesh(meshList[GEO_SPHERE], true);

			modelStack.PushMatrix();// right thigh
			{
				meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
				modelStack.Translate(0, -5., 0);
				modelStack.Rotate(0, 0, 0, 1);
				modelStack.Scale(0.5, 10., 0.5);
				RenderMesh(meshList[GEO_CYLINDER], true);
			}
			modelStack.PopMatrix();

			modelStack.PushMatrix();// Right thigh plate
			meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
			modelStack.Translate(0, -2., -1.3);
			modelStack.Rotate(20, 45, -10, 1);
			modelStack.Scale(3., 7., 0.6);
			RenderMesh(meshList[GEO_CUBE], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();// right knee
			{
				meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
				meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
				modelStack.Translate(0, -10, 0);
				modelStack.Rotate(RkneeRotateX, 1, 0, 0);
				modelStack.Rotate(RkneeRotateY, 0, 1, 0);
				modelStack.Rotate(RkneeRotateZ, 0, 0, 1);
				modelStack.Scale(1., 1., 1.);
				RenderMesh(meshList[GEO_SPHERE], true);

				modelStack.PushMatrix();// right calf
				{
					meshList[GEO_CYLINDER]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_CYLINDER]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
					modelStack.Translate(0, -5., 0);
					modelStack.Rotate(0, 0, 0, 1);
					modelStack.Scale(0.5, 10., 0.5);
					RenderMesh(meshList[GEO_CYLINDER], true);
				}
				modelStack.PopMatrix();

				modelStack.PushMatrix();// right foot
				{
					meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_SPHERE]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
					modelStack.Translate(0, -10, 0);
					modelStack.Rotate(RfootRotate, 0, 0, 1);
					modelStack.Scale(1., 1., 1.);
					RenderMesh(meshList[GEO_SPHERE], true);

					modelStack.PushMatrix(); //foot
					meshList[GEO_CUBE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
					meshList[GEO_CUBE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
					modelStack.Translate(1.5, 0, 0);
					modelStack.Rotate(90, 0, 0, 1);
					modelStack.Scale(1.8, 4.5, 2.5);
					RenderMesh(meshList[GEO_CUBE], true);
					modelStack.PopMatrix();
				}
				modelStack.PopMatrix(); // right foot end
			}
			modelStack.PopMatrix(); // right knee end
		}
		modelStack.PopMatrix(); // right thigh end joint
	}
	modelStack.PopMatrix(); /// center



	modelStack.PushMatrix();
	modelStack.Translate(0, -1, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_GROUND], true);
	modelStack.PopMatrix();

	// com cube
	if (pickup == true)
	{
		modelStack.PushMatrix();
		modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);
		modelStack.Rotate(centerRotateY, 0, 1, 0);
		modelStack.PushMatrix();
		modelStack.Translate(10, -5, 0);
		modelStack.Scale(objsSize[18] * 300, objsSize[19] * 300, objsSize[20] * 300);
		RenderMesh(meshList[GEO_COMCUBE], true);
		modelStack.PopMatrix();
		modelStack.PopMatrix();

	}
	else
	{
		modelStack.PushMatrix();
		modelStack.Translate(objsPos[18], objsPos[19], objsPos[20]);
		modelStack.Scale(objsSize[18] * 300, objsSize[19] * 300, objsSize[20] * 300);
		RenderMesh(meshList[GEO_COMCUBE], true);
		modelStack.PopMatrix();
	}


	//relaxation chamber
	{
		//toilet
		modelStack.PushMatrix();
		modelStack.Translate(objsPos[12], objsPos[13], objsPos[14]);
		modelStack.Scale(objsSize[12] * 500, objsSize[13] * 500, objsSize[14] * 500);
		RenderMesh(meshList[GEO_TOILET], true);
		modelStack.PopMatrix();

		//sink
		modelStack.PushMatrix();
		modelStack.Translate(objsPos[63], objsPos[64], objsPos[65]);
		modelStack.Scale(objsSize[63], objsSize[64], objsSize[65]);
		RenderMesh(meshList[GEO_SINK], true);
		modelStack.PopMatrix();

		//mattress
		modelStack.PushMatrix();
		modelStack.Translate(15, 0.2, 9);
		modelStack.Rotate(90, 0, 1, 0);
		modelStack.Scale(0.1, 0.1, 0.1);
		RenderMesh(meshList[GEO_BED], true);
		modelStack.PopMatrix();

		//night stand
		modelStack.PushMatrix();
		modelStack.Translate(objsPos[15], objsPos[16], objsPos[17]);
		modelStack.Rotate(45, 0, 1, 0);
		modelStack.Scale(objsSize[15] * 0.1, objsSize[16] * 0.1, objsSize[17] * 0.1);
		RenderMesh(meshList[GEO_NIGHTSTAND], true);
		modelStack.PopMatrix();
		
		//radio
		modelStack.PushMatrix();
		modelStack.Translate(-15, 4.5, -15);
		modelStack.Rotate(30, 0, 1, 0);
		modelStack.Scale(1, 1, 1);
		RenderMesh(meshList[GEO_RADIO], true);
		modelStack.PopMatrix();

		if (pickup1 == true)
		{
			modelStack.PushMatrix();
			modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);
			modelStack.Rotate(centerRotateY, 0, 1, 0);
			modelStack.PushMatrix();
			modelStack.Translate(10, -5, 0);
			modelStack.Scale(objsSize[60] * 300, objsSize[61] * 300, objsSize[62] * 300);
			RenderMesh(meshList[GEO_COMCUBE], true);
			modelStack.PopMatrix();
			modelStack.PopMatrix();

		}
		else
		{
			modelStack.PushMatrix();
			modelStack.Translate(objsPos[60], objsPos[61], objsPos[62]);
			modelStack.Scale(objsSize[60] * 300, objsSize[61] * 300, objsSize[62] * 300);
			RenderMesh(meshList[GEO_COMCUBE], true);
			modelStack.PopMatrix();
		}

		//ceiling 1
		modelStack.PushMatrix();
		modelStack.Translate(0, 40, 0);
		modelStack.Rotate(0, 1, 0, 0);
		modelStack.Scale(40, 1, 40);
		RenderMesh(meshList[GEO_CUBE], true);
		modelStack.PopMatrix();

		//ceiling 2
		modelStack.PushMatrix();
		modelStack.Translate(0, 80, 0);
		modelStack.Rotate(0, 1, 0, 0);
		modelStack.Scale(120, 1, 120);
		RenderMesh(meshList[GEO_CUBE], true);
		modelStack.PopMatrix();
		//walls
		{
			modelStack.PushMatrix();
			modelStack.Translate(objsPos[27], objsPos[28], objsPos[29]);
			modelStack.Scale(objsSize[27], objsSize[28], objsSize[29]);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(objsPos[30], objsPos[31], objsPos[32]);
			modelStack.Scale(objsSize[30], objsSize[31], objsSize[32]);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(objsPos[33], objsPos[34], objsPos[35]);
			modelStack.Scale(objsSize[33], objsSize[34], objsSize[35]);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(objsPos[36], objsPos[37], objsPos[38]);
			modelStack.Scale(objsSize[36], objsSize[37], objsSize[38]);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(0, 50, -60);
			modelStack.Scale(20, 60, 1);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(objsPos[39], objsPos[40], objsPos[41]);
			modelStack.Scale(objsSize[39], objsSize[40], objsSize[41]);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			//door left
			modelStack.PushMatrix();
			modelStack.Translate(objsPos[21], objsPos[22], objsPos[23]);
			modelStack.Scale(objsSize[21], objsSize[22], objsSize[23]);
			RenderMesh(meshList[GEO_DOOR], true);
			modelStack.PopMatrix();

			//door right
			modelStack.PushMatrix();
			modelStack.Translate(objsPos[24], objsPos[25], objsPos[26]);
			modelStack.Scale(objsSize[24], objsSize[25], objsSize[26]);
			RenderMesh(meshList[GEO_DOOR], true);
			modelStack.PopMatrix();

			//exit sign
			modelStack.PushMatrix();
			modelStack.Translate(59.4, 25, -97.5);
			modelStack.Rotate(-90, 0, 1, 0);
			modelStack.Scale(5, 5, 5);
			RenderMesh(meshList[GEO_EXIT], false);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(59.4, 25, -102.5);
			modelStack.Rotate(-90, 0, 1, 0);
			modelStack.Scale(5, 5, 5);
			RenderMesh(meshList[GEO_PERSON], false);
			modelStack.PopMatrix();
		}

		//blue portal
		modelStack.PushMatrix();
		modelStack.Translate(portalPos[0], portalPos[1], portalPos[2]);
		modelStack.Rotate(180, 0, 1, 0);
		modelStack.Scale(portalSize[0], portalSize[1], portalSize[2]);
		RenderMesh(meshList[GEO_BPORTAL], false);
		modelStack.PopMatrix();

		//orange portal
		modelStack.PushMatrix();
		modelStack.Translate(portalPos[3], portalPos[4], portalPos[5]);
		modelStack.Scale(portalSize[3], portalSize[4], portalSize[5]);
		RenderMesh(meshList[GEO_OPORTAL], false);
		modelStack.PopMatrix();
		
	}

	// test chamber 00
	{
		// button
		modelStack.PushMatrix();
		modelStack.Translate(buttonPos[0], buttonPos[1], buttonPos[2]);
		modelStack.Scale(buttonSize[0], buttonSize[1], buttonSize[2]);
		RenderMesh(meshList[GEO_BUTTON], true);
		modelStack.PopMatrix();
		
		//walls
		{
			modelStack.PushMatrix();
			modelStack.Translate(20, 40, -120);
			modelStack.Scale(80, 80, 1);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(-20, 40, -90);
			modelStack.Scale(1, 80, 60);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(60, 40, -115);
			modelStack.Scale(1, 80, 10);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(60, 40, -70);
			modelStack.Scale(1, 80, 40);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			modelStack.Translate(60, 50, -100);
			modelStack.Scale(1, 60, 20);
			RenderMesh(meshList[GEO_WALL], true);
			modelStack.PopMatrix();

		}
		//door left 1
		modelStack.PushMatrix();
		modelStack.Translate(objsPos[42], objsPos[43], objsPos[44]);
		modelStack.Scale(objsSize[42], objsSize[43], objsSize[44]);
		RenderMesh(meshList[GEO_DOOR], true);
		modelStack.PopMatrix();

		//door right 1
		modelStack.PushMatrix();
		modelStack.Translate(objsPos[45], objsPos[46], objsPos[47]);
		modelStack.Scale(objsSize[45], objsSize[46], objsSize[47]);
		RenderMesh(meshList[GEO_DOOR], true);
		modelStack.PopMatrix();

		//exit sign
		modelStack.PushMatrix();
		modelStack.Translate(-2.5, 25, -59.4);
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_EXIT], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(2.5, 25, -59.4);
		modelStack.Scale(5, 5, 5);
		RenderMesh(meshList[GEO_PERSON], false);
		modelStack.PopMatrix();
	}

	
	

	//Glass
	{
		modelStack.PushMatrix();
		modelStack.Translate(objsPos[0], objsPos[1], objsPos[2]);
		modelStack.Scale(objsSize[0], objsSize[1], objsSize[2]);
		RenderMesh(meshList[GEO_GLASS], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(objsPos[3], objsPos[4], objsPos[5]);
		modelStack.Scale(objsSize[3], objsSize[4], objsSize[5]);
		RenderMesh(meshList[GEO_GLASS], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(objsPos[6], objsPos[7], objsPos[8]);
		modelStack.Scale(objsSize[6], objsSize[7], objsSize[8]);
		RenderMesh(meshList[GEO_GLASS], false);
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		modelStack.Translate(objsPos[9], objsPos[10], objsPos[11]);
		modelStack.Scale(objsSize[9], objsSize[10], objsSize[11]);
		RenderMesh(meshList[GEO_GLASS], false);
		modelStack.PopMatrix();
	}
	modelStack.PushMatrix();
	modelStack.Translate(-15, 10, -19.4);
	modelStack.Scale(3, 3, 3);
	RenderText(meshList[GEO_TEXT], "Welcome to the relaxation vault", Color(1, 0, 0));
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-19.4, 10, 10);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Scale(3, 3, 3);
	RenderText(meshList[GEO_TEXT], "Objective: Reach the exit", Color(1, 0, 0));
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-19.4, 7, 10);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.Scale(3, 3, 3);
	RenderText(meshList[GEO_TEXT], "Press E to pick up cubes", Color(1, 0, 0));
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(80, 7, -120);
	modelStack.Rotate(0, 0, 1, 0);
	modelStack.Scale(3, 3, 3);
	RenderText(meshList[GEO_TEXT], "CONGRATS YOU PASSED THE TEST", Color(0, 1, 1));
	modelStack.PopMatrix();

	std::ostringstream ss;
	ss.str("");
	ss.precision(4);
	ss << "FPS: " << FPS;
	RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0, 1, 0), 4, 0, 0);
}

void Assignment2::Exit()
{
	// Cleanup VBO here
	delete meshList[GEO_QUAD];
	delete meshList[GEO_AXES];
	delete meshList[GEO_CUBE];
	delete meshList[GEO_CIRCLE];
	delete meshList[GEO_SPHERE];
	delete meshList[GEO_TORUS];
	delete meshList[GEO_CYLINDER];
	delete meshList[GEO_HEMISPHERE];
	delete meshList[GEO_CONE];
	delete meshList[GEO_LEFT];
	delete meshList[GEO_RIGHT];
	delete meshList[GEO_TOP];
	delete meshList[GEO_BOTTOM];
	delete meshList[GEO_FRONT];
	delete meshList[GEO_BACK];
	delete meshList[GEO_GLASS];
	delete meshList[GEO_BPORTAL];
	delete meshList[GEO_OPORTAL];
	delete meshList[GEO_TEXT];
	delete meshList[GEO_TOILET];
	delete meshList[GEO_COMCUBE];
	delete meshList[GEO_BED];
	delete meshList[GEO_NIGHTSTAND];
	delete meshList[GEO_WALL];
	delete meshList[GEO_DOOR];
	delete meshList[GEO_BUTTON];
	delete meshList[GEO_PERSON];
	delete meshList[GEO_EXIT];
	delete meshList[GEO_RADIO];
	delete meshList[GEO_SINK];
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}