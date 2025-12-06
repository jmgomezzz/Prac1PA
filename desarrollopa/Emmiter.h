#pragma once
#include "Solid.h"
#include <vector>
#include "EmmiterConfiguration.h"
using namespace std;
class Emmiter :public Solid
{
private:
	EmmiterConfiguration configuracion;
	vector<Solid*> particulasGeneradas;
public:
	Emmiter() {
		this->configuracion = EmmiterConfiguration();
		this->particulasGeneradas = {};
	}
void Render();
void Update();
};

