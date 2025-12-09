#pragma once
#include "Solid.h"
#include <vector>
#include "EmmiterConfiguration.h"
#include <chrono>

using namespace std;

class Emmiter : public Solid
{
private:
	EmmiterConfiguration configuracion;
	vector<Solid*> particulasGeneradas;
	std::chrono::milliseconds initialMilliseconds;
	long lastUpdatedTime;

public:
	Emmiter();
	void Render();
	void Update();

	Solid* Clone();

	void SetConfiguration(EmmiterConfiguration config) { this->configuracion = config; }
};