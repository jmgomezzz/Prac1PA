#pragma once
#include "Solid.h"

class Particle
{
private:
	Solid* modelo;
	long tiempoCreacion;

public:
	Particle(Solid* modelo, long tiempoCreacion) {
		this->modelo = modelo;
		this->tiempoCreacion = tiempoCreacion;
	}

	//Destructor
	~Particle() {
		if (this->modelo != nullptr) {
			delete this->modelo;
			this->modelo = nullptr;
		}
	}
	//Delegamos el renderizado y update al modelo interno
	void Render() {
		if (this->modelo != nullptr) this->modelo->Render();
	}

	void Update() {
		if (this->modelo != nullptr) this->modelo->Update();
	}

	long GetTiempoCreacion() { return this->tiempoCreacion; }
};