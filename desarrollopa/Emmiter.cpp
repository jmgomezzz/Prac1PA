#include "Emmiter.h"
#include <chrono>
using namespace std::chrono;

void Emmiter::Render() {
	//Renderiza las parts
	for (int i = 0; i < particulasGeneradas.size(); i++) {
		particulasGeneradas[i]->Render();
	}
}
void Emmiter::Update() {
	for (int i = 0; i < particulasGeneradas.size();i++) {
		this->particulasGeneradas[i]->Update();

	}
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	long elapsedTime = currentTime.count() - this->initialMilliseconds.count();


	if ((elapsedTime - this->lastUpdatedTime) >= this->configuracion.GetPeriodoEmision()) {
		// Comprueba si no hemos superado el número máximo de partículas
		if (this->particulasGeneradas.size() < this->configuracion.GetMaxParticulas()) {
			// Si se cumplen las condiciones, se emite una nueva partícula
			Solid* newParticle = this->configuracion.GetParticula()->Clone(); // Clona la partícula base
			newParticle->SetCoordinates(this->GetCoord()); // La partícula nace en la posición del emisor
			newParticle->SetSpeed(this->GetSpeed());       // La partícula hereda la velocidad inicial del emisor
			this->particulasGeneradas.push_back(newParticle);

			// Actualiza el tiempo de la última emisión para la siguiente comprobación
			this->lastUpdatedTime = elapsedTime;
		}
	}
}