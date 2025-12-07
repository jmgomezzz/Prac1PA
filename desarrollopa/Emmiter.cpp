#include "Emmiter.h"
#include <chrono>
using namespace std::chrono;

void Emmiter::Render() {
	for (int i = 0; i < particulasGeneradas.size(); i++) {
		particulasGeneradas[i]->Render();
	}
}
void Emmiter::Update() {
	for (int i = 0; i < this->configuracion.GetMaxParticulas();i++) {
		this->particulasGeneradas[i]->Update();

	}
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

}