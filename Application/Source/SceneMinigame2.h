#ifndef SCENE_SCENEMINIGAME2_H
#define SCENE_SCENEMINIGAME2_H

#include "Scene.h"
#include "SceneInvestigation.h"
#include "Camera.h"
#include "Camera2.h"
#include "Camera3.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"
#include <fstream>
#include <vector>


class SceneMinigame2 : public Scene
{
    enum GEOMETRY_TYPE
    {
        GEO_QUAD,
        GEO_FRONT,
        GEO_TEXT,
        GEO_HEART,
        GEO_INTRO,
        GEO_RESULTS,
        GEO_BASKET,
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
        U_LIGHTENABLED,
        U_LIGHT0_POSITION,
        U_LIGHT0_COLOR,
        U_LIGHT0_POWER,
        U_LIGHT0_KC,
        U_LIGHT0_KL,
        U_LIGHT0_KQ,
        U_LIGHT0_TYPE,
        U_LIGHT0_SPOTDIRECTION,
        U_LIGHT0_COSCUTOFF,
        U_LIGHT0_COSINNER,
        U_LIGHT0_EXPONENT,
        U_NUMLIGHTS,
        U_COLOR_TEXTURE_ENABLED,
        U_COLOR_TEXTURE,
        U_TEXT_ENABLED,
        U_TEXT_COLOR,
        U_TOTAL,
    };
    MS modelStack, viewStack, projectionStack;
    Camera3 camera;
private:
    unsigned m_vertexArrayID;
    unsigned m_programID;
    unsigned m_parameters[U_TOTAL];

    float FPS, timing, coolDown;
    bool bLightEnabled;
    Vector3 view, right;
    Position basketCoord;
    int gameStage, heartScore;
    std::vector <Position> heartCoord;
    float basketLength, heartLength;
    bool nextScene;
    //for timing
    clock_t start = clock();

    Mesh* meshList[NUM_GEOMETRY];
    Light light[1];
    std::ifstream fileStream;
    unsigned textMaxWidth, textSpacing[256];

    bool touch(float alength, float blength, float ax, float ay, float bx, float by);
    void RenderIntro();
    void RenderSkybox();
    void RenderHearts();
    void RenderBasketCatch();
    void RenderResults();
    void RenderMesh(Mesh* mesh, bool enableLight);
    void RenderText(Mesh* mesh, std::string text, Color color);
    void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
    void RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey);

public:
    SceneMinigame2();
    ~SceneMinigame2();
    virtual void Init();
    virtual void Update(double dt);
    virtual void Render();
    virtual void Exit();
    virtual void CurrentScene();
    virtual int NextScene();
};
#endif