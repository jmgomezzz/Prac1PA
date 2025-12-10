#include "Emmiter.h"
#include <chrono>
#include <cstdlib> //Para rand
using namespace std::chrono;

void Emmiter::Render() {
	//El emisor no renderiza las partículas, lo hace la escena
	}
	void Emmiter::Update() {
	//Tampoco actualiza las partículas, lo hace la escena

		milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		long elapsedTime = currentTime.count() - this->initialMilliseconds.count();


		if ((elapsedTime - this->lastUpdatedTime) >= this->configuracion.GetPeriodoEmision()) {
			// Comprueba si no hemos superado el número máximo de partículas
			if (this->particulasGeneradas.size() < this->configuracion.GetMaxParticulas()) {
				// Si se cumplen las condiciones, se emite una nueva partícula
				Solid* newParticle = this->configuracion.GetParticula()->Clone(); // Clona la partícula base
				newParticle->SetCoordinates(this->GetCoord()); // La partícula nace en la posición del emisor

				//Velocidad aleatoria
				float speedFactor = 0.5f; // Factor para limitar la velocidad aleatoria
				float x = speedFactor * (((rand() % 200) - 100) / 100.0f); //Valor entre -0.5 y 0.5
				float y = speedFactor * (((rand() % 200) - 100) / 100.0f); //Valor entre -0.5 y 0.5
				float z = 0; //Obviamente no movemos Z
				
				newParticle->SetSpeed(Vector3D(x, y, z));
				
				
				this->particulasGeneradas.push_back(newParticle);

				// Actualiza el tiempo de la última emisión para la siguiente comprobación
				this->lastUpdatedTime = elapsedTime;
			}
		}
	}