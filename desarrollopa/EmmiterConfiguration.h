#pragma once
#include "Solid.h"
class EmmiterConfiguration
{
private:
	int maxParticulas;
	int periodoEmision;
	Solid* particula;
	Vector3D aceleracion;
	int tiempoVida;
public:
	EmmiterConfiguration(int mP=15,int pE=25,Solid*part,Vector3D a=Vector3D(),int t=10000){
		this->maxParticulas =mP;
		this->periodoEmision =pE;
		this->particula = part;
		this->aceleracion = a;
		this->tiempoVida = t;
	}
	inline int GetMaxParticulas() { return this->maxParticulas; }
	inline int GetPeriodoEmision() { return this->periodoEmision; }
	inline Solid* GetParticula() { return this->particula; }
	inline Vector3D GetAceleracion() { return this->aceleracion; }
	inline int GetTiempoVida() { return this->tiempoVida; }

	void SetMaxParticulas(int maxParticulasToSet) { this->maxParticulas = maxParticulasToSet; }
	void SetPeriodoEmision(int periodoEmisionToSet) { this->periodoEmision = periodoEmisionToSet; }
	void SetParticula(Solid* particulaToSet) { this->particula = particulaToSet; }
	void SetParticula(Vector3D aceleracionToSet) { this->aceleracion = aceleracionToSet; }
	void SetTiempoVida(int tiempoVidaToSet) { this->tiempoVida = tiempoVidaToSet; }

};

