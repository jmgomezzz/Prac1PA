#pragma once
#include <vector>
#include "Solid.h"
#include "Camera.h"
using namespace std;
class Scene
{
private:
	vector<Solid*> gameObjects;
	Camera camara;
	Vector3D boundary;

	void checkBoundary();//Implementada en Scene.cpp, no recordaba haberla puesto aquí (seguro que lo hicimos en clase en algun momento) pero la he implementado de vuelta en el cpp asi que todo guay

public:
	Scene() {
		this->boundary = Vector3D(8.0,6.0,4.0);
		this->gameObjects = {};
		this->camara = Camera(Vector3D(0.0,0.0,16.0));
	}

	inline Vector3D GetBoundary() { return this->boundary; }

	//Devuelve el número de objetos en la escena
	inline int GetObjectCount() { return this->gameObjects.size(); }

	void AddGameObject(Solid* objeto);
	void Render();
	void Update();
};

