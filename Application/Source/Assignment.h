
#ifndef SCENE_Assignment_H
#define SCENE_Assignment_H

#include "Scene.h"
#include "Camera.h"
#include "Camera2.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"

class Assignment : public Scene
{
	MS modelStack, viewStack, projectionStack;

	enum GEOMETRY_TYPE
	{
		GEO_TRIANGLE_1 = 0,
		GEO_TRIANGLE_2,
		GEO_AXES,
		GEO_QUAD,
		GEO_CUBE,
		GEO_CIRCLE,
		GEO_SPHERE,
		GEO_TORUS,
		GEO_CYLINDER,
		GEO_HEMISPHERE,
		GEO_CONE,
		GEO_LIGHTBALL,

		NUM_GEOMETRY,
	};

	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHTENABLED,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,
		U_NUMLIGHTS,
		U_TOTAL,
	};
private:
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	//center
	float centerRotateX, centerRotateY, centerRotateZ,
		centerTranslateX, centerTranslateY, centerTranslateZ;

	//head
	float headRotateX, headRotateY, headRotateZ,
		headTranslateX, headTranslateY, headTranslateZ;

	//left
	float LshoulderRotateX, LshoulderRotateY, LshoulderRotateZ, 
		LelbowRotateX, LelbowRotateY, LelbowRotateZ, 
		LhandRotateX, LhandRotateY, LhandRotateZ, 
		Lthumb1Rotate, 
		Lthumb2Rotate, 
		Lindex1Rotate, 
		Lindex2Rotate, 
		Lindex3Rotate, 
		Lmiddle1Rotate, 
		Lmiddle2Rotate, 
		Lmiddle3Rotate, 
		Lring1Rotate, 
		Lring2Rotate, 
		Lring3Rotate;

	float LthighRotateX, LthighRotateY, LthighRotateZ, 
		LkneeRotateX, LkneeRotateY, LkneeRotateZ,
		LfootRotate;

	//right
	float RshoulderRotateX, RshoulderRotateY, RshoulderRotateZ,
		RelbowRotateX, RelbowRotateY, RelbowRotateZ,
		RhandRotateX, RhandRotateY, RhandRotateZ, 
		Rthumb1Rotate, 
		Rthumb2Rotate, 
		Rindex1Rotate, 
		Rindex2Rotate, 
		Rindex3Rotate, 
		Rmiddle1Rotate, 
		Rmiddle2Rotate, 
		Rmiddle3Rotate, 
		Rring1Rotate, 
		Rring2Rotate, 
		Rring3Rotate;

	float RthighRotateX, RthighRotateY, RthighRotateZ, 
		RkneeRotateX, RkneeRotateY, RkneeRotateZ, 
		RfootRotate;

	void RenderMesh(Mesh* mesh, bool enableLight);

	Camera2 camera;
	Light light[2];

public:
	Assignment();
	~Assignment();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
};

#endif