#include "Assignment.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "shader.hpp"
#include "Application.h"
#include "MeshBuilder.h"
#include "Utility.h"


Assignment::Assignment()
{
}

Assignment::~Assignment()
{
}

void Assignment::Init()
{
	// Init VBO here

	//center
	centerRotateX = 0;
	centerRotateY = 0;
	centerRotateZ = 0;
	centerTranslateX = 0;
	centerTranslateY = 9.5;
	centerTranslateZ = 0;

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



	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	m_programID = LoadShaders("Shader//Shading.vertexshader", "Shader//LightSource.fragmentshader");
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
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
	glUseProgram(m_programID);
	glUniform1i(m_parameters[U_NUMLIGHTS], 2);

	light[0].type = Light::LIGHT_POINT;
	light[0].position.Set(0, 35, 0);
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


	camera.Init(Vector3(40, 30, 30), Vector3(0, 0, 0), Vector3(0, 1, 0));

	for (int i = 0; i < NUM_GEOMETRY; i++)
	{
		meshList[i] = nullptr;
	}
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("axes", 1000, 1000, 1000);

	meshList[GEO_SPHERE] = MeshBuilder::GenerateSphere("sphere", Color(1, 1, 1), 50, 100);

	meshList[GEO_HEMISPHERE] = MeshBuilder::GenerateHemiSphere("hemisphere", Color(1, 1, 1), 50, 100);

	meshList[GEO_TORUS] = MeshBuilder::GenerateTorus("torus", Color(0.7, 0.7, 0.7), 50, 50, 15, 1);

	meshList[GEO_CYLINDER] = MeshBuilder::GenerateCylinder("cylinder", Color(0.1, 0.1, 0.1), 50, 1);

	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("light ball", Color(1, 1, 1), 50, 100);

	meshList[GEO_CUBE] = MeshBuilder::GenerateCube("cube", Color(1., 1., 1.), 1, 1, 1);

	meshList[GEO_CONE] = MeshBuilder::GenerateCone("cone", Color(1, 0.8196, 0.8627), 50, 1, 1);

	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("floor", Color(0.5, 0.5, 0.5), 100, 100);
	meshList[GEO_QUAD]->material.kAmbient.Set(0.3f, 0.3f, 0.3f);
	meshList[GEO_QUAD]->material.kDiffuse.Set(0.3f, 0.3f, 0.3f);
	meshList[GEO_QUAD]->material.kSpecular.Set(1.f, 1.f, 1.f);
	meshList[GEO_QUAD]->material.kShininess = 1.f;

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	glEnable(GL_DEPTH_TEST);

}

void Assignment::Update(double dt)
{
	float LSPEED = 10.0;

	if (Application::IsKeyPressed('1'))
		glEnable(GL_CULL_FACE);
	if (Application::IsKeyPressed('2'))
		glDisable(GL_CULL_FACE);
	if (Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if (Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
	if (Application::IsKeyPressed('I'))
		light[0].position.z -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('K'))
		light[0].position.z += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('J'))
		light[0].position.x -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('L'))
		light[0].position.x += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('O'))
		light[0].position.y -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('P'))
		light[0].position.y += (float)(LSPEED * dt);
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

	camera.Update(dt);

	static int maxShoulder = 0;
	static int maxThigh = 0;
	static int counter = 0;
	static int spin = 0;
	static int startSpin = 0;
	static int timer = 0;
	static int temp = 0;
	//walk forward
	if (Application::IsKeyPressed('W'))
	{
		centerRotateY = 0;
		centerTranslateX += (float)(10 * dt);


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
		centerRotateY = 90;
		centerTranslateZ -= (float)(10 * dt);

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
		centerRotateY = 0;
		centerTranslateX -= (float)(20 * dt);
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
		centerRotateY = -90;
		centerTranslateZ += (float)(10 * dt);

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
	//atlas roll
	else if (Application::IsKeyPressed(VK_SPACE))
	{
		//squat
		if (counter == 0)
		{
			if (centerTranslateY > 4)
			{
				centerTranslateY -= (float)(20 * dt);
			}
			if (LthighRotateX < 10)
			{
				LthighRotateX += (float)(300 * dt);
				RthighRotateX = -LthighRotateX;
			}
			if (LthighRotateZ < 80)
			{
				LthighRotateZ += (float)(300 * dt);
				RthighRotateZ = LthighRotateZ;
			}
			if (LkneeRotateX > 10)
			{
				LkneeRotateX -= (float)(600 * dt);
				RkneeRotateX = -LkneeRotateX;
			}
			if (LkneeRotateZ > -140)
			{

				LkneeRotateZ -= (float)(700 * dt);
				RkneeRotateZ = LkneeRotateZ;
			}
			if (LfootRotate < 55)
			{
				LfootRotate += (float)(400 * dt);
				RfootRotate = LfootRotate;
			}
		}
		//arms
		if (counter == 0)
		{
			if (RshoulderRotateZ <= 85)
			{
				RshoulderRotateZ += (float)(400 * dt);
			}
			if (Rthumb1Rotate < 70)
			{
				Rthumb1Rotate += (float)(500 * dt);
			}
			if (Rindex2Rotate >= 0)
			{
				Rindex2Rotate -= (float)(200 * dt);
				Rindex3Rotate -= (float)(200 * dt);
			}
			if (Rmiddle1Rotate < 60)
			{
				Rmiddle1Rotate += (float)(500 * dt);
			}
			if (Rmiddle2Rotate < 60)
			{
				Rmiddle2Rotate += (float)(500 * dt);
			}
			if (Rmiddle3Rotate < 60)
			{
				Rmiddle3Rotate += (float)(500 * dt);
			}
			if (Rring1Rotate < 60)
			{
				Rring1Rotate += (float)(500 * dt);
			}
			if (Rring2Rotate < 60)
			{
				Rring2Rotate += (float)(500 * dt);
			}
			if (Rring3Rotate < 60)
			{
				Rring3Rotate += (float)(500 * dt);
			}
			if (LshoulderRotateX <= 45)
			{
				LshoulderRotateX += (float)(300 * dt);
			}
			if (LshoulderRotateZ <= 45)
			{
				LshoulderRotateZ += (float)(300 * dt);
			}
			if (LelbowRotateZ < 120)
			{
				LelbowRotateZ += (float)(500 * dt);
			}
			if (LhandRotateY <= 80)
			{
				LhandRotateY += (float)(250 * dt);
				if (LhandRotateY >= 80)
					counter = 1;
			}
		}
		// head spin
		if (counter == 1)
		{
			if (spin == 0)
			{
				LelbowRotateY += (float)(60 * dt);
				if (LelbowRotateY >= 30)
					spin = 1;
			}
			if (spin == 1)
			{
				if (LelbowRotateZ > 20)
				{
					LelbowRotateZ -= (float)(300 * dt);
				}
				if (LelbowRotateY > -80)
				{
					LelbowRotateY -= (float)(700 * dt);
					if (LelbowRotateY <= -65)
					{
						if (LelbowRotateZ > 20)
						{
							LelbowRotateZ -= (float)(300 * dt);
						}
						startSpin = 1;
					}
				}
			}
			if (startSpin == 1)
			{
				if (spin == 1 || spin == 2)
				{
					headRotateZ -= (float)(1400 * dt);
				}

				if (-headRotateZ * 0.0027777 > 3)
				{
					if (centerTranslateY < 12 && spin == 1)
					{
						centerTranslateY += (float)(50 * dt);
						if (centerTranslateY > 6 && spin == 1)
						{
							LthighRotateX = 0;
							LthighRotateZ = 0;
							LkneeRotateX = 0;
							LkneeRotateZ = 0;
							LfootRotate = 0;
							LshoulderRotateX = 0;
							LshoulderRotateZ = 0;
							LelbowRotateX = 0;
							LelbowRotateZ = 0;
							LhandRotateX = 0;
							LhandRotateZ = 0;

							spin = 2;
						}
					}
					if (centerTranslateY < 13 && spin == 2)
					{
						centerTranslateY += (float)(20 * dt);
					}
					if (spin == 2)
					{
						centerRotateZ -= (float)(1400 * dt);
						temp = centerRotateZ;
						headRotateZ -= (float)(1400 * dt);
						if (centerTranslateY > 7)
						{
							if (LthighRotateX < 10)
							{
								LthighRotateX += (float)(300 * dt);
								RthighRotateX = -LthighRotateX;
							}
							if (LthighRotateZ < 50)
							{
								LthighRotateZ += (float)(300 * dt);
								RthighRotateZ = LthighRotateZ;
							}
							if (LkneeRotateX > 10)
							{
								LkneeRotateX -= (float)(600 * dt);
								RkneeRotateX = -LkneeRotateX;
							}
							if (LkneeRotateZ > -140)
							{
								LkneeRotateZ -= (float)(700 * dt);
								RkneeRotateZ = LkneeRotateZ;
							}
							if (LfootRotate < 20)
							{
								LfootRotate += (float)(400 * dt);
								RfootRotate = LfootRotate;
							}
							if (LshoulderRotateZ <= 180)
							{
								LshoulderRotateZ += (float)(400 * dt);
							}
							if (LhandRotateY >= -90)
							{
								LhandRotateY -= (float)(700 * dt);
							}
							if (LhandRotateZ >= -45)
							{
								LhandRotateZ -= (float)(700 * dt);
							}
							if (LhandRotateX >= -45)
							{
								LhandRotateX -= (float)(700 * dt);
							}
							if (Lthumb1Rotate >= -90)
							{
								Lthumb1Rotate -= (float)(400 * dt);
							}
						}
					}
					if (-centerRotateZ * 0.002777 > 2.5)
					{
						spin = 3;

						Lthumb2Rotate = 0;
						Lindex1Rotate = 0;
						Lindex2Rotate = 0;
						Lindex3Rotate = 0;
						Lmiddle1Rotate = 0;
						Lmiddle2Rotate = 0;
						Lmiddle3Rotate = 0;
						Lring1Rotate = 0;
						Lring2Rotate = 0;
						Lring3Rotate = 0;

						if (LshoulderRotateX >= -20)
						{
							LshoulderRotateX -= (float)(500 * dt);
						}
						if (LelbowRotateZ < 80)
						{
							LelbowRotateZ += (float)(900 * dt);
						}

						if (RshoulderRotateZ >= -90)
						{
							RshoulderRotateZ -= (float)(700 * dt);
						}
						if (centerTranslateY > 7.8)
						{
							centerTranslateY -= (float)(20 * dt);
						}
						if (centerTranslateY <= 7.8)
						{
							headRotateZ = 180;
							spin = 4;
							startSpin = 2;
						}
					}

				}
			}
			if (startSpin == 2)
			{
				if (timer < 90)
				{
					timer += (float)(60 * dt);
				}
				if (timer >= 90)
				{
					if (spin == 4)
					{
						if (centerTranslateY < 15)
						{
							centerTranslateY += (float)(30 * dt);
							centerTranslateX -= (float)(10 * dt);
						}
						if (centerRotateZ < temp + 90)
							centerRotateZ += (float)(400 * dt);

						if (LthighRotateX > 0)
						{
							LthighRotateX -= (float)(200 * dt);
							RthighRotateX = -LthighRotateX;
						}
						if (LthighRotateZ > 0)
						{
							LthighRotateZ -= (float)(200 * dt);
							RthighRotateZ = LthighRotateZ;
						}
						if (LkneeRotateX > 0)
						{
							LkneeRotateX -= (float)(200 * dt);
							RkneeRotateX = -LkneeRotateX;
						}
						if (LkneeRotateZ < 0)
						{
							LkneeRotateZ += (float)(400 * dt);
							RkneeRotateZ = LkneeRotateZ;
						}
						if (LfootRotate > 0)
						{
							LfootRotate -= (float)(200 * dt);
							RfootRotate = LfootRotate;
						}
						if (centerTranslateY >= 15)
							spin = 5;

					}
					if (spin == 5)
					{
						if (centerTranslateY >= 9.5)
						{
							centerTranslateY -= (float)(20 * dt);
							centerTranslateX -= (float)(10 * dt);

							if (centerRotateZ < temp + 180)
							{
								centerRotateZ += (float)(400 * dt);
							}
						}
						if (headRotateZ > 0)
						{
							headRotateZ -= (float)(200 * dt);
							
						}


						if (LthighRotateX > 0)
						{
							LthighRotateX -= (float)(100 * dt);
							RthighRotateX = -LthighRotateX;
						}
						if (LthighRotateZ > 0)
						{
							LthighRotateZ -= (float)(100 * dt);
							RthighRotateZ = LthighRotateZ;
						}
						if (LkneeRotateX > 0)
						{
							LkneeRotateX -= (float)(100 * dt);
							RkneeRotateX = -LkneeRotateX;
						}
						if (LkneeRotateZ < 0)
						{

							LkneeRotateZ += (float)(100 * dt);
							RkneeRotateZ = LkneeRotateZ;
						}
						if (LfootRotate > 0)
						{
							LfootRotate -= (float)(100 * dt);
							RfootRotate = LfootRotate;
						}
						if (RshoulderRotateZ < 85)
						{
							RshoulderRotateZ += (float)(400 * dt);
						}
						
						if (LshoulderRotateX > 45)
						{
							LshoulderRotateX -= (float)(300 * dt);
						}
						if (LshoulderRotateZ < 90)
						{
							LshoulderRotateZ += (float)(300 * dt);
						}
						if (LelbowRotateZ > 0)
						{
							LelbowRotateZ -= (float)(500 * dt);
						}
						if (LelbowRotateX > 0)
						{
							LelbowRotateX -= (float)(500 * dt);
						}
						if (headRotateZ <= 0)
						{
							LthighRotateX = 0;
							LthighRotateZ = 0;
							LkneeRotateX = 0;
							LkneeRotateZ = 0;
							LfootRotate = 0;

							RthighRotateX = 0;
							RthighRotateZ = 0;
							RkneeRotateX = 0;
							RkneeRotateZ = 0;
							RfootRotate = 0;

							if (timer < 180)
							{
								timer += (float)(60 * dt);
							}
							if (timer >= 180)
							{
								spin = 6;
							}
						}

					}

					if (spin == 6)
					{
						if (LshoulderRotateZ > 0)
							LshoulderRotateZ -= (float)(200 * dt);
						if (LshoulderRotateZ < 0)
							LshoulderRotateZ += (float)(200 * dt);

						if (RshoulderRotateZ > 0)
							RshoulderRotateZ -= (float)(200 * dt);
						if (RshoulderRotateZ < 0)
							RshoulderRotateZ += (float)(200 * dt);

						if (LshoulderRotateX > 0)
							LshoulderRotateX -= (float)(200 * dt);
						if (LshoulderRotateX < 0)
							LshoulderRotateX += (float)(200 * dt);

						if (RshoulderRotateX > 0)
							RshoulderRotateX -= (float)(200 * dt);
						if (RshoulderRotateX < 0)
							RshoulderRotateX += (float)(200 * dt);

						if (LelbowRotateZ > 0)
							LelbowRotateZ -= (float)(200 * dt);
						if (LelbowRotateZ < 0)
							LelbowRotateZ += (float)(200 * dt);

						if (LelbowRotateY > 0)
							LelbowRotateY -= (float)(200 * dt);
						if (LelbowRotateY < 0)
							LelbowRotateY += (float)(200 * dt);

						if (RelbowRotateZ > 0)
							RelbowRotateZ -= (float)(200 * dt);
						if (RelbowRotateZ < 0)
							RelbowRotateZ += (float)(200 * dt);

						if (LhandRotateX > 0)
							LhandRotateX -= (float)(200 * dt);
						if (LhandRotateX < 0)
							LhandRotateX += (float)(200 * dt);

						if (LhandRotateY > 0)
							LhandRotateY -= (float)(200 * dt);
						if (LhandRotateY < 0)
							LhandRotateY += (float)(200 * dt);

						if (LhandRotateZ > 0)
							LhandRotateZ -= (float)(200 * dt);
						if (LhandRotateZ < 0)
							LhandRotateZ += (float)(200 * dt);
												
					}
				}
			}
		}
	}

	//come to rest
	else if (Application::IsKeyPressed('B'))
	{
		if (counter == 0)
		{
			if (LshoulderRotateX < 130)
			{
				LshoulderRotateX += (float)(100 * dt);
			}
			RshoulderRotateX = -LshoulderRotateX;

			if (LshoulderRotateZ < 60)
			{
				LshoulderRotateZ += (float)(100 * dt);
			}
			RshoulderRotateZ = -LshoulderRotateZ;
			if (RelbowRotateZ > -125)
			{
				RelbowRotateZ -= (float)(100 * dt);
			}
			LelbowRotateZ = -RelbowRotateZ;
			if (RhandRotateY < 90)
			{
				RhandRotateY += (float)(100 * dt);
			}
			if (LhandRotateY < 90)
			{
				LhandRotateY += (float)(100 * dt);
			}
			if (RelbowRotateZ <= -125)
			{
				counter = 2;
			}
			
		}
		if (counter == 2)
		{
			timer += (float)(100 * dt);
			if (timer >= 15)
			{
				headRotateY += (float)(1000 * dt);
				if (headTranslateY < 15)
				{
					headTranslateY += (float)(10 * dt);
				}
				if (LshoulderRotateZ > 0)
				{
					LshoulderRotateZ -= (float)(400 * dt);
				}
				RshoulderRotateZ = -LshoulderRotateZ;

				if (headTranslateY >= 15)
				{
					counter = 3;
					timer = 0;
				}
			}
		}
		if (counter == 3)
		{
			if(spin == 0)
				headRotateY += (float)(1000 * dt);
			if (headTranslateY > 0)
			{
				headTranslateY -= (float)(10 * dt);
			}
			if (headTranslateY <= 0)
			{
				timer += (float)(100 * dt);
				if (timer >= 15)
				{
					if (LshoulderRotateZ < 60)
					{
						LshoulderRotateZ += (float)(100 * dt);
					}
					RshoulderRotateZ = -LshoulderRotateZ;
				
					if (LshoulderRotateZ >= 60)
					{
						spin = 1;
						headRotateY = 0;
						counter = 4;
						timer = 0;
					}
				}
			}
		}
		if (counter == 4)
		{
			timer += (float)(100 * dt);
			if (timer >= 15)
			{
				if (LshoulderRotateZ > 0)
				{
					LshoulderRotateZ -= (float)(100 * dt);
				}
				RshoulderRotateZ = -LshoulderRotateZ;
				if (LshoulderRotateX > 0)
				{
					LshoulderRotateX -= (float)(100 * dt);
				}
				RshoulderRotateX = -LshoulderRotateX;
				if (RelbowRotateZ < 0)
				{
					RelbowRotateZ += (float)(100 * dt);
				}
				LelbowRotateZ = -RelbowRotateZ;
				if (RhandRotateY > 0)
				{
					RhandRotateY -= (float)(100 * dt);
				}
				if (LhandRotateY > 0)
				{
					LhandRotateY -= (float)(100 * dt);
				}
				if (LshoulderRotateX <= 0)
				{
					timer = 0;
					counter = 0;
					spin = 0;
				}
			}
		}
	}
	//reset pos
	if (Application::IsKeyPressed('R'))
	{
		maxShoulder = 0;
		maxThigh = 0;
		counter = 0;
		spin = 0;
		startSpin = 0;
		timer = 0;

		//center
		centerRotateX = 0;
		centerRotateY = 0;
		centerRotateZ = 0;
		centerTranslateX = 0;
		centerTranslateY = 9.5;
		centerTranslateZ = 0;

		//head
		headRotateX = 0;
		headRotateY = 0;
		headRotateZ = 0;
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
		Rthumb2Rotate = 10;
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
}
void Assignment::RenderMesh(Mesh* mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
	if (enableLight)
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
	mesh->Render();
}
void Assignment::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Mtx44 MVP;

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

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	RenderMesh(meshList[GEO_AXES], false);

	modelStack.PushMatrix();
	modelStack.Translate(light[0].position.x, light[0].position.y, light[0].position.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	//center
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
			RenderMesh(meshList[GEO_SPHERE], true);

			// eye
			modelStack.PushMatrix();
			meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(0.f, 1.f, 1.f);
			meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.0f, .6f, .6f);
			modelStack.Translate(4.99, 0, 0);
			modelStack.Rotate(270, 0, 0, 1);
			modelStack.Scale(1.5, 1.5, 1.5);
			RenderMesh(meshList[GEO_HEMISPHERE], true);
			modelStack.PopMatrix();

			// eyelids
			modelStack.PushMatrix();
			meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
			modelStack.Translate(2.3, -1.1, 0);
			modelStack.Rotate(0, 0, 0, 1);
			modelStack.Scale(3, .9, 3);
			RenderMesh(meshList[GEO_HEMISPHERE], true);
			modelStack.PopMatrix();

			modelStack.PushMatrix();
			meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.9f, .9f, .9f);
			modelStack.Translate(2.3, 1.1, 0);
			modelStack.Rotate(180, 0, 0, 1);
			modelStack.Scale(3, .9, 3);
			RenderMesh(meshList[GEO_HEMISPHERE], true);
			modelStack.PopMatrix();

			// head
			modelStack.PushMatrix();
			meshList[GEO_SPHERE]->material.kDiffuse.Set(1.f, 1.f, 1.f);
			meshList[GEO_SPHERE]->material.kAmbient.Set(0.8f, 0.8f, 0.8f);
			meshList[GEO_SPHERE]->material.kShininess = 10.f;
			modelStack.Translate(0, 0, 0);
			modelStack.Rotate(0, 0, 0, 1);
			modelStack.Scale(5., 5., 5.);
			RenderMesh(meshList[GEO_SPHERE], true);
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


	//companion cube
	modelStack.PushMatrix();
	{
		meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
		modelStack.Translate(20, 2.5, 20);
		modelStack.Rotate(30, 0, 1, 0);
		modelStack.Scale(1, 1, 1);
		RenderMesh(meshList[GEO_CUBE], true);

		modelStack.PushMatrix();
		{
			meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
			modelStack.Translate(0, 0, 0);
			modelStack.Rotate(0, 1, 0, 0);
			modelStack.Scale(5, 5, 5);
			RenderMesh(meshList[GEO_CUBE], true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		{
			modelStack.Rotate(0, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(180, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(270, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(360, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 0, 1);
			
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
	}
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	{
		meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
		modelStack.Translate(25, 2.5, 25);
		modelStack.Rotate(-70, 0, 1, 0);
		modelStack.Scale(1, 1, 1);
		RenderMesh(meshList[GEO_CUBE], true);

		modelStack.PushMatrix();
		{
			meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
			modelStack.Translate(0, 0, 0);
			modelStack.Rotate(0, 1, 0, 0);
			modelStack.Scale(5, 5, 5);
			RenderMesh(meshList[GEO_CUBE], true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		{
			modelStack.Rotate(0, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(180, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(270, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(360, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 0, 1);

			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
	}
	modelStack.PopMatrix();
	modelStack.PushMatrix();
	{
		meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
		modelStack.Translate(22.5, 7.5, 22.5);
		modelStack.Rotate(45, 0, 1, 0);
		modelStack.Scale(1, 1, 1);
		RenderMesh(meshList[GEO_CUBE], true);

		modelStack.PushMatrix();
		{
			meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
			modelStack.Translate(0, 0, 0);
			modelStack.Rotate(0, 1, 0, 0);
			modelStack.Scale(5, 5, 5);
			RenderMesh(meshList[GEO_CUBE], true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		{
			modelStack.Rotate(0, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(180, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(270, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(360, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 0, 1);

			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
	}
	modelStack.PopMatrix();



	modelStack.PushMatrix();
	{
		meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
		modelStack.Translate(-20, 2.5, -10);
		modelStack.Rotate(45, 0, 1, 0);
		modelStack.Scale(1, 1, 1);
		RenderMesh(meshList[GEO_CUBE], true);

		modelStack.PushMatrix();
		{
			meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
			modelStack.Translate(0, 0, 0);
			modelStack.Rotate(0, 1, 0, 0);
			modelStack.Scale(5, 5, 5);
			RenderMesh(meshList[GEO_CUBE], true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		{
			modelStack.Rotate(0, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(180, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(270, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(360, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 0, 1);

			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
	}
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	{
		meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
		meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
		modelStack.Translate(10, 2.5, -15);
		modelStack.Rotate(30, 0, 1, 0);
		modelStack.Scale(1, 1, 1);
		RenderMesh(meshList[GEO_CUBE], true);

		modelStack.PushMatrix();
		{
			meshList[GEO_CUBE]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
			meshList[GEO_CUBE]->material.kAmbient.Set(0.6f, 0.6f, 0.6f);
			modelStack.Translate(0, 0, 0);
			modelStack.Rotate(0, 1, 0, 0);
			modelStack.Scale(5, 5, 5);
			RenderMesh(meshList[GEO_CUBE], true);
		}
		modelStack.PopMatrix();

		modelStack.PushMatrix();
		{
			modelStack.Rotate(0, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(180, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(270, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(360, 0, 1, 0);
			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
		modelStack.PushMatrix();
		{
			modelStack.Rotate(90, 0, 0, 1);

			modelStack.PushMatrix();
			{
				meshList[GEO_CONE]->material.kAmbient.Set(.8f, .8f, 0.8f);
				modelStack.Translate(2.5, -0.5, 0);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 1., 1.);
				RenderMesh(meshList[GEO_CONE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, -0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
			modelStack.PushMatrix();
			{
				meshList[GEO_HEMISPHERE]->material.kDiffuse.Set(1.f, 0.8196f, 0.8627f);
				meshList[GEO_HEMISPHERE]->material.kAmbient.Set(.65f, .57f, 0.58f);
				modelStack.Translate(2.5, 0, 0.5);
				modelStack.Rotate(180, 0, 0, 1);
				modelStack.Scale(.1, 0.5, 0.5);
				RenderMesh(meshList[GEO_HEMISPHERE], true);
			}
			modelStack.PopMatrix();
		}
		modelStack.PopMatrix();
	}
	modelStack.PopMatrix();


	//floor
	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 0);
	modelStack.Rotate(-90, 1, 0, 0);
	modelStack.Scale(1000, 1000, 1000);
	RenderMesh(meshList[GEO_QUAD], true);
	modelStack.PopMatrix();

}

void Assignment::Exit()
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

	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}