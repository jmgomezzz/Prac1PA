#include "Scene.h"
#include <iostream>
#include <vector>
void Scene::AddGameObject(Solid* objeto)
{
	gameObjects.push_back(objeto);
}
void Scene::Render() {
	camara.Render();
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Render();
	}
}
void Scene::Update() {
	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->Update();
	}
	checkBoundary();
}

