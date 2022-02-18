#include "SceneGame.h"
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


SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::InitHitbox()
{
	//Hitboxes, pos xyz, scale xyz
	//NPC hitbox
	hitbox.push_back(Hitbox(-80.f, 0.f, -80.f, 10.0f, 20.0f, 10.0f));
	hitbox.push_back(Hitbox(-90.f, 0.f, -70.f, 10.0f, 20.0f, 10.0f));
	hitbox.push_back(Hitbox(70.f, 0.f, -80.f, 10.0f, 20.0f, 10.0f));
	hitbox.push_back(Hitbox(-100.f, 0.f, 120.f, 10.0f, 20.0f, 10.0f));
	hitbox.push_back(Hitbox(0.f, 0.f, -200.f, 10.0f, 20.0f, 10.0f));

	//Building hitbox
	hitbox.push_back(Hitbox(-100.f, 0.f, -300.f, 200.0f, 20.0f, 100.0f));
	hitbox.push_back(Hitbox(100.f, 0.f, -300.f, 200.0f, 20.0f, 100.0f));
	hitbox.push_back(Hitbox(-100.f, 0.f, 300.f, 200.0f, 20.0f, 100.0f));
	hitbox.push_back(Hitbox(100.f, 0.f, 300.f, 200.0f, 20.0f, 100.0f));
	hitbox.push_back(Hitbox(0.f, 0.f, -200.f, 10.0f, 20.0f, 10.0f));
}



void SceneGame::Init()
{
	// Init VBO here
	InitHitbox();


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
	
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	
	glUseProgram(m_programID);

	light[0].type = Light::LIGHT_DIRECTIONAL;
	light[0].position.Set(20, 50, 20);
	light[0].color.Set(1, 1, 1);
	light[0].power = 1;
	light[0].kC = 8.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 3.f;
	light[0].spotDirection.Set(0.f, 1.f, 0.f);

	light[1].type = Light::LIGHT_DIRECTIONAL;
	light[1].position.Set(-20, 50, -20);
	light[1].color.Set(1, 1, 1);
	light[1].power = 1;
	light[1].kC = 8.f;
	light[1].kL = 0.01f;
	light[1].kQ = 0.001f;
	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
	light[1].cosInner = cos(Math::DegreeToRadian(30));
	light[1].exponent = 3.f;
	light[1].spotDirection.Set(0.f, 1.f, 0.f);

	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[1].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[1].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[1].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[1].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[1].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[1].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[1].exponent);
	glUniform1i(m_parameters[U_NUMLIGHTS], 4);

	

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

	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);

	meshList[GEO_CUBE] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);

	meshList[GEO_CONE] = MeshBuilder::GenerateCone("cone", Color(1, 0.8196, 0.8627), 50.f, 1.f, 1.f);

	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//DimboFont.tga");

	meshList[GEO_GROUND] = MeshBuilder::GenerateFloor("floor", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_GROUND]->textureID = LoadTGA("Image//floorTile.tga");

	meshList[GEO_NPC1] = MeshBuilder::GenerateOBJ("npc 1", "OBJ//characterbase.obj");
	meshList[GEO_NPC1]->textureID = LoadTGA("Image//NPC1tex.tga");

	meshList[GEO_NPC2] = MeshBuilder::GenerateOBJ("npc 2", "OBJ//characterbase.obj");
	meshList[GEO_NPC2]->textureID = LoadTGA("Image//NPC2tex.tga");

	meshList[GEO_NPC3] = MeshBuilder::GenerateOBJ("npc 3", "OBJ//characterbase.obj");
	meshList[GEO_NPC3]->textureID = LoadTGA("Image//NPC3tex.tga");

	meshList[GEO_NPC4] = MeshBuilder::GenerateOBJ("npc 4", "OBJ//characterbase.obj");
	meshList[GEO_NPC4]->textureID = LoadTGA("Image//NPC4tex.tga");

	meshList[GEO_NPC5] = MeshBuilder::GenerateOBJ("npc 5", "OBJ//characterbase.obj");
	meshList[GEO_NPC5]->textureID = LoadTGA("Image//NPC5tex.tga");

	meshList[GEO_BUILDING1] = MeshBuilder::GenerateOBJMTL("building 1", "OBJ//large_buildingE.obj", "OBJ//large_buildingE.mtl");
	meshList[GEO_BUILDING2] = MeshBuilder::GenerateOBJMTL("building 1", "OBJ//large_buildingA.obj", "OBJ//large_buildingA.mtl");
	meshList[GEO_BUILDING3] = MeshBuilder::GenerateOBJMTL("building 1", "OBJ//skyscraperE.obj", "OBJ//skyscraperE.mtl");
	meshList[GEO_BUILDING4] = MeshBuilder::GenerateOBJMTL("building 1", "OBJ//small_buildingE.obj", "OBJ//small_buildingE.mtl");

	meshList[GEO_BUTTON] = MeshBuilder::GenerateCylinder("cylinder", Color(1, 0, 0), 50, 1);

	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("sphere", (1, 1, 1), 20, 20, 5);//for testing



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

void SceneGame::Update(double dt)
{
	camera.Update(dt, hitbox);
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

	//Mouse Inputs
	static bool bLButtonState = false;
	if (!bLButtonState && Application::IsMousePressed(0))
	{
		bLButtonState = true;
		std::cout << "LBUTTON DOWN" << std::endl;
		//Converting Viewport space to UI space
		double x, y;
		
		Application::GetCursorPos(&x, &y);
		unsigned w = Application::GetWindowWidth();
		unsigned h = Application::GetWindowHeight();

		float BUTTON_TOP = 1;
		float BUTTON_BOTTOM = 0;
		float BUTTON_LEFT = 0;
		float BUTTON_RIGHT = 1;

		float posX = (x / w) * 80; //convert (0,800) to (0,80)
		float posY = 60 - ((y / h) * 60); //convert (600,0) to (0,60)
		std::cout << "posX:" << posX << " , posY:" << posY << std::endl;
		if (posX > BUTTON_LEFT && posX < BUTTON_RIGHT && posY > BUTTON_BOTTOM && posY < BUTTON_TOP)
		{
			std::cout << "Hit!" << std::endl;
			interact = true;
			//trigger user action or function
		}
		else
		{
			std::cout << "Miss!" << std::endl;
			interact = false;
		}
	}
	else if (bLButtonState && !Application::IsMousePressed(0))
	{
		bLButtonState = false;
		std::cout << "LBUTTON UP" << std::endl;
	}
	static bool bRButtonState = false;
	if (!bRButtonState && Application::IsMousePressed(1))
	{
		bRButtonState = true;
		std::cout << "RBUTTON DOWN" << std::endl;
	}
	else if (bRButtonState && !Application::IsMousePressed(1))
	{
		bRButtonState = false;
		std::cout << "RBUTTON UP" << std::endl;
	}

	
	
}

void SceneGame::RenderSkybox() {
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

void SceneGame::RenderInvestigationScene()
{

	//NPC clues
	modelStack.PushMatrix();
	modelStack.Translate(-80, -1, -80);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_NPC4], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-90, -1, -70);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_NPC4], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(70, -1, -80);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_NPC1], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-100, -1, 120);
	modelStack.Rotate(-90, 0, -90, 0);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_NPC2], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, -1, -200);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_NPC2], false);
	modelStack.PopMatrix();

	//building rendering

	modelStack.PushMatrix();
	modelStack.Translate(-100, -1, -300);
	modelStack.Rotate(-180, 0, 180, 0);
	modelStack.Scale(120, 120, 120);
	RenderMesh(meshList[GEO_BUILDING4], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(100, -1, -300);
	modelStack.Rotate(-180, 0, 180, 0);
	modelStack.Scale(120, 120, 120);
	RenderMesh(meshList[GEO_BUILDING4], true);
	modelStack.PopMatrix();





	modelStack.PushMatrix();
	modelStack.Translate(-100, -1, 300);
	modelStack.Scale(120, 120, 120);
	RenderMesh(meshList[GEO_BUILDING4], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(100, -1, 310);
	modelStack.Scale(100, 100, 100);
	RenderMesh(meshList[GEO_BUILDING2], true);
	modelStack.PopMatrix();



	modelStack.PushMatrix();
	modelStack.Translate(250, -1, -200);
	modelStack.Rotate(-90, 0, 90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING3], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(250, -1, -70);
	modelStack.Rotate(-90, 0, 90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING3], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(250, -1, 70);
	modelStack.Rotate(-90, 0, 90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING3], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(250, -1, 200);
	modelStack.Rotate(-90, 0, 90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING3], true);
	modelStack.PopMatrix();




	modelStack.PushMatrix();
	modelStack.Translate(-250, -1, -200);
	modelStack.Rotate(-90, 0, 90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-250, -1, -70);
	modelStack.Rotate(-90, 0, 90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-250, -1, 70);
	modelStack.Rotate(-90, 0, 90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING1], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-250, -1, 200);
	modelStack.Rotate(90, 0, -90, 0);
	modelStack.Scale(80, 80, 80);
	RenderMesh(meshList[GEO_BUILDING1], true);
	modelStack.PopMatrix();
}
void SceneGame::RenderMesh(Mesh* mesh, bool enableLight)
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
void SceneGame::RenderText(Mesh* mesh, std::string text, Color color)
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
void SceneGame::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
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
void SceneGame::RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey)
{
	glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity();
	//to do: scale and translate accordingly
	RenderMesh(mesh, false); //UI should not have light
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void SceneGame::Render()
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
	RenderInvestigationScene();
	RenderMesh(meshList[GEO_AXES], false);

	modelStack.PushMatrix();
	modelStack.Translate(0, -1, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_GROUND], true);
	modelStack.PopMatrix();

	//for testing

	modelStack.PushMatrix();
	modelStack.Translate(light[1].position.x, light[1].position.y, light[1].position.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(light[0].position.x, light[0].position.y, light[0].position.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	if (Application::IsKeyPressed('I'))
		light[1].position.y += 3;
	if (Application::IsKeyPressed('J'))
		light[1].position.x -= 3;
	if (Application::IsKeyPressed('L'))
		light[1].position.x += 3;
	if (Application::IsKeyPressed('K'))
		light[1].position.y -= 3;

	modelStack.PushMatrix();
	modelStack.Translate(-15, 10, -19.4);
	modelStack.Scale(3, 3, 3);
	RenderText(meshList[GEO_TEXT], "Scene game", Color(1, 0, 0));
	modelStack.PopMatrix();

	RenderMeshOnScreen(meshList[GEO_QUAD], 40, 30, 20, 10);

	std::ostringstream ss;
	ss.str("");
	ss.precision(4);
	ss << "FPS: " << FPS;
	RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0, 1, 0), 4, 0, 0);
}

void SceneGame::Exit()
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
	delete meshList[GEO_NPC1];
	delete meshList[GEO_NPC2];
	delete meshList[GEO_NPC3];
	delete meshList[GEO_NPC4];
	delete meshList[GEO_NPC5];
	delete meshList[GEO_BUILDING1];
	delete meshList[GEO_BUILDING2];
	delete meshList[GEO_BUILDING3];
	delete meshList[GEO_BUILDING4];
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}