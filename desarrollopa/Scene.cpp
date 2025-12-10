#include "Scene.h"
#include <iostream>
#include <vector>
void Scene::AddGameObject(Solid* objeto)
{
	gameObjects.push_back(objeto);
}
void Scene::Render() {
//Nueva config de camara para que se vea todo bien
	this->camara.Render();

//Resto de objs
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}
void Scene::Update() {
	checkBoundary();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update();
	}
	
}
void Scene::checkBoundary() {
	vector<Solid*> newClones; //Almacenará los clones para añadirlos después
	const int maxGameObjects = 200; //Para no pasarnos

	for (int i = 0; i < gameObjects.size(); i++) {
		Solid* currentObject = gameObjects[i];
		Vector3D pos = currentObject->GetCoord();
		Vector3D speed = currentObject->GetSpeed();
		bool hasCollided = false;

		//Comprobamos colision y aplicamos rebote
		if (pos.GetX() > this->GetBoundary().GetX() || pos.GetX() < -this->GetBoundary().GetX()) {
			speed.SetX(speed.GetX() * -1);
			hasCollided = true;
		}
		if (pos.GetY() > this->GetBoundary().GetY() || pos.GetY() < -this->GetBoundary().GetY()) {
			speed.SetY(speed.GetY() * -1);
			hasCollided = true;
		}
		if (pos.GetZ() > this->GetBoundary().GetZ() || pos.GetZ() < -this->GetBoundary().GetZ()) {
			speed.SetZ(speed.GetZ() * -1);
			hasCollided = true;
		}

		currentObject->SetSpeed(speed);

		//Si colisiona sin pasarse del limite de objs, clonamos
		if (hasCollided && gameObjects.size() + newClones.size() < maxGameObjects) {
			Solid* clone = currentObject->Clone();
			if (clone) {
				clone->SetSpeed(speed.Product(-1)); //Velocidad opuesta
				newClones.push_back(clone);
			}
		}
	}
	//Añadimos los clones generados
	if (!newClones.empty()) {
		gameObjects.insert(gameObjects.end(), newClones.begin(), newClones.end());
	}
};

