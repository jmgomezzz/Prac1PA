#pragma once
#include "Teapot.h"
#include "Cube.h"
#include "Cuboid.h"
#include "Sphere.h"
#include "Solid.h"
#include "Scene.h"
#include "Toroid.h"
#include "Cylinder.h"
#include "Emmiter.h"
using namespace std;

class Game
{
private:
	Scene escena;
	Teapot teapot;
	Cube cube;
	Cuboid cuboid;
	Sphere sphere;
	Cylinder cylinder;
	Toroid toroid;
	Emmiter* emisor;

public:

	Game(); //Podemos borrar todos los objetos ya que no los vamos a usar como objetos fijos


	void Init();
	void Render();
	void Update();
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
};

/*Teapot teapot;
	Cube cube;
	Cuboid cuboid;
	Sphere sphere;
	Cuboid prisma1;
	Cuboid prisma2;
	Cuboid prisma3;
	Cuboid prisma4;
	Cuboid prisma5;
	Cuboid prisma6;
	Cuboid prisma7;
	
	
		teapot.SetCoordinates(Vector3D(-1.6, 1.3, -3.0));
		teapot.SetColor(Color(0.2f, 0.4f, 0.6f));
		
		cube.SetCoordinates(Vector3D(1.6, 1.3, -3.0));
		cube.SetColor(Color(0.8f, 0.7f, 0.4f));

		sphere.SetCoordinates(Vector3D(1.6, -1.3, -3.0));
		sphere.SetColor(Color(0.1f, 0.5f, 0.2f));

		cuboid.SetCoordinates(Vector3D(-1.6, -1.3, -3.0));
		cuboid.SetColor(Color(0.3f, 0.1f, 0.3f));

		prisma1.SetHeight(0.05f);
		prisma1.SetLength(0.3f);
		prisma1.SetWidth(2.0f);
		prisma1.SetCoordinates(Vector3D(0.0,0.3,-2.0));
		prisma1.SetOrientation(Orientation(0.0,0.0,0.0));
		prisma1.SetColor(Color(1.0f,1.0f,1.0f));

		prisma2.SetHeight(0.05f);
		prisma2.SetLength(0.3f);
		prisma2.SetWidth(2.0f);
		prisma2.SetCoordinates(Vector3D(0.0, 0.0, -2.0));
		prisma2.SetOrientation(Orientation(0.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0f, 1.0f, 1.0f));

		prisma3.SetHeight(0.05f);
		prisma3.SetLength(0.3f);
		prisma3.SetWidth(2.0f);
		prisma3.SetCoordinates(Vector3D(0.0, -0.3, -2.0));
		prisma3.SetOrientation(Orientation(0.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0f, 1.0f, 1.0f));

		prisma4.SetHeight(0.05f);
		prisma4.SetLength(0.3f);
		prisma4.SetWidth(2.0f);
		prisma4.SetCoordinates(Vector3D(0.2, -0.15, -2.0));
		prisma4.SetOrientation(Orientation(0.0, 0.0, 90.0));
		prisma4.SetColor(Color(1.0f, 1.0f, 1.0f));

		prisma5.SetHeight(0.05f);
		prisma5.SetLength(0.3f);
		prisma5.SetWidth(2.0f);
		prisma5.SetCoordinates(Vector3D(-0.2, -0.15, -2.0));
		prisma5.SetOrientation(Orientation(0.0, 0.0, 90.0));
		prisma5.SetColor(Color(1.0f, 1.0f, 1.0f));

		prisma6.SetHeight(0.05f);
		prisma6.SetLength(0.3f);
		prisma6.SetWidth(2.0f);
		prisma6.SetCoordinates(Vector3D(0.2, 0.15, -2.0));
		prisma6.SetOrientation(Orientation(0.0, 0.0, 90.0));
		prisma6.SetColor(Color(1.0f, 1.0f, 1.0f));

		prisma7.SetHeight(0.05f);
		prisma7.SetLength(0.3f);
		prisma7.SetWidth(2.0f);
		prisma7.SetCoordinates(Vector3D(-0.2, 0.15, -2.0));
		prisma7.SetOrientation(Orientation(0.0, 0.0, 90.0));
		prisma7.SetColor(Color(1.0f, 1.0f, 1.0f));

	
	*/