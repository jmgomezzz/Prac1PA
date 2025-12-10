#pragma once
#include "Solid.h"
#include <vector>
#include "EmmiterConfiguration.h"
#include <chrono>
#include "Scene.h" //Para el tema de las partículas y límites

using namespace std;
class Emmiter :public Solid
{
private:
	EmmiterConfiguration configuracion;
	vector<Solid*> particulasGeneradas;
	std::chrono::milliseconds initialMilliseconds;
	long lastUpdatedTime;
	Scene* scene; //Referenciamos la escena
public:
	Emmiter(Scene* sc, EmmiterConfiguration config = EmmiterConfiguration()) {
		this->scene = sc;
		this->configuracion = config;
		this->particulasGeneradas = {};
		this->initialMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		this->lastUpdatedTime = 0;

	}
	// Getters
	inline EmmiterConfiguration& GetConfiguracion() { return this->configuracion; }
void Render();
void Update();
Solid* Clone() override {
		return new Emmiter(this->scene, this->configuracion);
}
};

