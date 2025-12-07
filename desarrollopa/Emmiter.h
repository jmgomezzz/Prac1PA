#pragma once
#include "Solid.h"
#include <vector>
#include "EmmiterConfiguration.h"
#include <chrono>
using namespace std;
class Emmiter :public Solid
{
private:
	EmmiterConfiguration configuracion;
	vector<Solid*> particulasGeneradas;
	std::chrono::milliseconds initialMilliseconds;
	long long lastUpdatedTime;
public:
	Emmiter() {
		this->configuracion = EmmiterConfiguration();
		this->particulasGeneradas = {};
		this->initialMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		this->lastUpdatedTime = 0;

	}
void Render();
void Update();
};

