#include "SceneHouseGame.h"
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


SceneHouseGame::SceneHouseGame()
{
}

SceneHouseGame::~SceneHouseGame()
{
}

void SceneHouseGame::InitHitbox()
{
	//Hitboxes, pos xyz, scale xyz

	//entities
	entities.push_back(new Object("Passport",	0.f, Vector3(05, 5, 0), Vector3(0, 0, 1), 500.f));
	hitbox.push_back(Hitbox(5.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Documents",	0.f, Vector3(10, 5, 0), Vector3(0, 0, 1), 400.f));
	hitbox.push_back(Hitbox(10.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Clothes",	0.f, Vector3(15, 5, 0), Vector3(0, 0, 1), 100.f));
	hitbox.push_back(Hitbox(15.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Money",		0.f, Vector3(20, 5, 0), Vector3(0, 0, 1), 200.f));
	hitbox.push_back(Hitbox(20.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Hard drive", 0.f, Vector3(25, 5, 0), Vector3(0, 0, 1), 600.f));
	hitbox.push_back(Hitbox(25.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Wallet",		0.f, Vector3(30, 5, 0), Vector3(0, 0, 1), 400.f));
	hitbox.push_back(Hitbox(30.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Phone",		0.f, Vector3(35, 5, 0), Vector3(0, 0, 1), 600.f));
	hitbox.push_back(Hitbox(35.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Evidence1",	0.f, Vector3(40, 5, 0), Vector3(0, 0, 1), 300.f));
	hitbox.push_back(Hitbox(40.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Evidence2",	0.f, Vector3(45, 5, 0), Vector3(0, 0, 1), 300.f));
	hitbox.push_back(Hitbox(45.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	entities.push_back(new Object("Medication", 0.f, Vector3(50, 5, 0), Vector3(0, 0, 1), 200.f));
	hitbox.push_back(Hitbox(50.f, 5.f, 0.f, 3.f, 3.f, 3.f));

	//objs
	//pc [10]
	hitbox.push_back(Hitbox(1.f, 0.f, -1.f, 3.f, 10.f, 3.f));

	//suitcase [11]
	hitbox.push_back(Hitbox(-5.f, 0.f, 0.f, 5.f, 5.f, 5.f));
}


void SceneHouseGame::Init()
{
	// Init VBO here
	InitHitbox();

	canInteractPC = false;
	canPickup = false;
	incomingCall = true;
	gameStart = false;
	canUnload = false;
	index = 0;
	totalScore = 0;
	
	//dialogue
	BossDialogue.push_back("Hey...");
	BossDialogue.push_back("Listen we don't have much time...");
	BossDialogue.push_back("An anonymous tipped our scam off to Melon Tusk.");
	BossDialogue.push_back("Your IP address has been leaked and the cops are on their way.");
	BossDialogue.push_back("Try to dispose of any evidence and pack your bags.");
	BossDialogue.push_back("You have 2 minutes to pack your suitcase.");
	BossDialogue.push_back("*Hangs up...*");
	BossDialogue.push_back(" ");
	
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
	light[0].position.Set(0, 12, 0);
	light[0].color.Set(1, 1, 1);
	light[0].power = 1;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(45));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 3.f;
	light[0].spotDirection.Set(0.f, 1.f, 0.f);


	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

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

	//objs
	meshList[GEO_HOUSE] = MeshBuilder::GenerateOBJMTL("house", "OBJ//house.obj", "OBJ//house.mtl");

	meshList[GEO_PC] = MeshBuilder::GenerateOBJMTL("PC", "OBJ//PC.obj", "OBJ//PC.mtl");
	meshList[GEO_PC]->textureID = LoadTGA("Image//PC.tga");

	meshList[GEO_SUITCASE] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);

	meshList[GEO_GROUND] = MeshBuilder::GenerateFloor("floor", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_GROUND]->textureID = LoadTGA("Image//woodFloor.tga");

	//entities
	meshList[GEO_PASSPORT] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_DOCUMENTS] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_CLOTHES] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_MONEY] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_HARDDRIVE] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_WALLET] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_PHONE] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_EVIDENCE1] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_EVIDENCE2] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);
	meshList[GEO_MEDS] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1.f, 1.f, 1.f);

	//hud
	meshList[GEO_DIALOGUE] = MeshBuilder::GenerateQuad("TextBox", Color(0.0, 0.0, 0.0), 1.f, 1.f);
	meshList[GEO_CROSSHAIR] = MeshBuilder::GenerateQuad("crosshair", Color(0.0, 0.0, 0.0), 1.f, 1.f);
	meshList[GEO_CROSSHAIR]->textureID = LoadTGA("Image//crosshair.tga");

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
void SceneHouseGame::getBossDialogue()
{
	static bool isPressed = false;
	if (Application::IsKeyPressed(VK_RETURN) && playDialogue == true && !isPressed)
	{
		 if(index == 6)
		 {
			 playDialogue = false;
			 gameStart = true;
		 }
		 else
			 index += 1;
		 isPressed = !isPressed;
	}
	else if (!Application::IsKeyPressed(VK_RETURN) && playDialogue == true && isPressed)
	{
		isPressed = false;
	}
}

void SceneHouseGame::pcInteract()
{
	if (camera.PlayerInRange(hitbox, 10) == true)
	{
		canInteractPC = true;
		if (Application::IsKeyPressed('E') && incomingCall == true)
		{
			playDialogue = true;
			incomingCall = false;
		}
	}
	else
		canInteractPC = false;

	getBossDialogue();
}

void SceneHouseGame::unloadInven()
{
	if (camera.PlayerInRange(hitbox, 11) == true)
	{
		canUnload = true;
		static bool isPressed = false;
		if (Application::IsKeyPressed('E') && !isPressed)
		{
			for (int i = 0; i < inventory.size(); i++)
			{
				suitcase.push_back(inventory[i]);
				totalScore += inventory[i]->getPoints();
			}
			inventory.clear();
		}
		else if (!Application::IsKeyPressed('E') && isPressed)
		{
			isPressed = false;
		}
	}
	else
		canUnload = false;
}

void SceneHouseGame::updateEntity(float dt)
{
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->rotate(dt);
	}
}
void SceneHouseGame::pickEntity()
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (camera.PlayerInRange(hitbox, i) == true && entities[i]->getPickup() == false && gameStart == true && inventory.size() < 3)
		{
			canPickup = true;
			if (Application::IsKeyPressed('E'))
			{
				entities[i]->updatePickup(true);
				inventory.push_back(entities[i]);
			}
		}
		else
			canPickup = false;
	}
}
void SceneHouseGame::Update(double dt)
{
	camera.Update(dt, hitbox);
	FPS = 1 / (float)dt;
	view = (camera.target - camera.position).Normalized();

	right = view.Cross(camera.up);
	right.y = 0;
	right.Normalize();

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
			//trigger user action or function
		}
		else
		{
			std::cout << "Miss!" << std::endl;
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

	pcInteract();
	pickEntity();
	updateEntity(dt);
	unloadInven();
}
void SceneHouseGame::RenderSkybox() {
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
void SceneHouseGame::RenderMesh(Mesh* mesh, bool enableLight)
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
void SceneHouseGame::RenderText(Mesh* mesh, std::string text, Color color)
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
void SceneHouseGame::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
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
void SceneHouseGame::RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey)
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
	modelStack.Translate(x, y, 0);
	modelStack.Scale(sizex, sizey, 0);
	RenderMesh(mesh, false); //UI should not have light
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}
void SceneHouseGame::Render()
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

	//RenderSkybox();

	RenderMesh(meshList[GEO_AXES], false);

	modelStack.PushMatrix();
	modelStack.Translate(light[0].position.x, light[0].position.y, light[0].position.z);
	modelStack.Scale(1, 1, 1);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Scale(12, 12, 12);
	RenderMesh(meshList[GEO_HOUSE], true);
	modelStack.PopMatrix();


	
	RenderMeshOnScreen(meshList[GEO_CROSSHAIR], 40, 30, 3, 3);
	//entities
	for (int i = 0; i < entities.size(); i++)
	{
		modelStack.PushMatrix();
		modelStack.Translate(entities[i]->getPosition().x, entities[i]->getPosition().y, entities[i]->getPosition().z);
		modelStack.Rotate(entities[i]->getLookDirection(), 0, 1, 0);
		modelStack.Scale(1, 1, 1);
		if (entities[i]->getRender() == true)
		{
			RenderMesh(meshList[i], true);
		}
		modelStack.PopMatrix();
	}

	modelStack.PushMatrix();
	modelStack.Translate(0, 5, 0);
	modelStack.Rotate(0, 1, 0, 0);
	modelStack.Scale(5, 5, 5);
	RenderMesh(meshList[GEO_PC], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-5, 5, 0);
	modelStack.Rotate(0, 1, 0, 0);
	modelStack.Scale(3, 3, 3);
	RenderMesh(meshList[GEO_SUITCASE], true);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 10, 0);
	modelStack.Scale(3, 3, 3);
	RenderText(meshList[GEO_TEXT], " ", Color(1, 0, 0));
	modelStack.PopMatrix();


	std::ostringstream ss;
	ss.str("");
	ss.precision(4);
	ss << "FPS: " << FPS;
	RenderTextOnScreen(meshList[GEO_TEXT], ss.str(), Color(0, 1, 0), 3, 0, 57);

	std::ostringstream Xcoords;
	Xcoords.str("");
	Xcoords.precision(3);
	Xcoords << "X : " << camera.position.x;
	RenderTextOnScreen(meshList[GEO_TEXT], Xcoords.str(), Color(0, 1, 0), 2, 0, 54);

	std::ostringstream Zcoords;
	Zcoords.str("");
	Zcoords.precision(3);
	Zcoords << "Z : " << camera.position.z;
	RenderTextOnScreen(meshList[GEO_TEXT], Zcoords.str(), Color(0, 1, 0), 2, 0, 52);

	if (canInteractPC == true && incomingCall == true)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], "Press [E] to recieve call", Color(0, 1, 0), 5, 25, 5);
	}
	if (canUnload == true)
	{
		if (inventory.size() > 0)
		{
			RenderTextOnScreen(meshList[GEO_TEXT], "Press [E] to pack suitcase", Color(0, 1, 0), 5, 25, 5);
		}
		else
		{
			RenderTextOnScreen(meshList[GEO_TEXT], "Your hands are empty!", Color(0, 1, 0), 5, 25, 5);
		}
	}
	if (canPickup == true)
	{		
		RenderTextOnScreen(meshList[GEO_TEXT], "Press [E] to pick up object", Color(0, 1, 0), 5, 25, 5);	
	}
	if (inventory.size() >= 3)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], "Inventory Full", Color(0, 1, 0), 5, 25, 5);
	}
	if (incomingCall == true)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], "Current objective: Answer the call", Color(1, 0, 0), 5, 15, 55);
	}

	if (playDialogue == true)
	{
		RenderMeshOnScreen(meshList[GEO_DIALOGUE], 30, 1, 100, 20);
		RenderTextOnScreen(meshList[GEO_TEXT], BossDialogue[index], Color(1, 1, 1), 4, 5, 5);
	}
	std::ostringstream InvenSize;
	InvenSize.str("");
	InvenSize.precision(2);
	InvenSize << "Inventory " << inventory.size() << "/3";
	if (gameStart == true)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], "Current objective: Find all the objects", Color(1, 0, 0), 4, 15, 55);
		RenderTextOnScreen(meshList[GEO_TEXT], InvenSize.str() , Color(1, 1, 1), 4, 5, 5);
	}
	std::ostringstream SuitcaseSize;
	SuitcaseSize.str("");
	SuitcaseSize.precision(2);
	SuitcaseSize << "Suitcase " << suitcase.size() << " / 10";
	if (gameStart == true)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], SuitcaseSize.str(), Color(1, 1, 1), 4, 5, 8);
	}
	std::ostringstream TotalScore;
	TotalScore.str("");
	TotalScore.precision(4);
	TotalScore << "Score: " << totalScore;
	if (gameStart == true)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], TotalScore.str(), Color(1, 1, 1), 4, 65, 55);
	}
	
}

void SceneHouseGame::Exit()
{
	// Cleanup VBO here
	for (int i = 0; i < NUM_GEOMETRY; i++)	delete meshList[i];

	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}