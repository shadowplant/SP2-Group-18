#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "Mesh.h"
#include "Vertex.h"

/******************************************************************************/
/*!
		Class MeshBuilder:
\brief	Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder
{
public:
	static Mesh* GenerateText(const std::string& meshName, unsigned numRow, unsigned numCol);
	static Mesh* GenerateOBJ(const std::string& meshName, const std::string& file_path);
	static Mesh* GenerateOBJMTL(const std::string& meshName, const std::string& file_path, const std::string& mtl_path);
	static Mesh* GenerateAxes(const std::string &meshName, float lengthX, float lengthY, float lengthZ);
	static Mesh* GenerateQuad(const std::string &meshName, Color color, float lengthX, float lengthY);
	static Mesh* GenerateFloor(const std::string& meshName, Color color, float lengthX, float lengthY);
	static Mesh* GenerateCube(const std::string &meshName, Color color, float lengthX, float lengthY, float lengthZ);
	static Mesh* GenerateWall(const std::string& meshName, Color color, float lengthX, float lengthY, float lengthZ);
	static Mesh* GenerateCircle(const std::string &meshName, Color color, unsigned numSlices, float radius);
	static Mesh* GenerateSphere(const std::string &meshName, Color color, unsigned numstacks, unsigned numSlices, float radius = 1.0f);
	static Mesh* GenerateHemiSphere(const std::string& meshName, Color color, unsigned numstacks, unsigned numSlices, float radius = 1.0f);
	static Mesh* GenerateTorus(const std::string& meshName, Color color, unsigned numstacks, unsigned numSlices, float outerR = .55f, float innerR = 0.5f);
	static Mesh* GenerateCylinder(const std::string& meshName, Color color, unsigned numSlices, float height, float radius = 1.0f);
	static Mesh* GenerateCone(const std::string& meshName, Color color, unsigned noOfSlices, float height, float radius);
};

#endif