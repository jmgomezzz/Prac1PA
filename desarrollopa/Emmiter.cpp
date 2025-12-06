#include "Emmiter.h"
void Emmiter::Render() {
	for (int i = 0; i < particulasGeneradas.size(); i++) {
		particulasGeneradas[i]->Render();
	}
}
void Emmiter::Update() {
	for (int i = 0; i < this->configuracion.GetMaxParticulas();i++) {



	}
}