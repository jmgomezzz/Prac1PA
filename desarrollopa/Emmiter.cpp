#include "Emmiter.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std::chrono;

float RandomFloat(float min, float max) {
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

Emmiter::Emmiter() {
	this->configuracion = EmmiterConfiguration();
	this->particulasGeneradas = {};
	this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	this->lastUpdatedTime = 0;
	srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Emmiter::Render() {
	for (int i = 0; i < particulasGeneradas.size(); i++) {
		particulasGeneradas[i]->Render();
	}
}

Solid* Emmiter::Clone() {
	return new Emmiter(*this);
}

void Emmiter::Update() {
	for (int i = 0; i < particulasGeneradas.size(); i++) {
		this->particulasGeneradas[i]->Update();
	}

	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
	long elapsedTime = currentTime.count() - this->initialMilliseconds.count();

	if ((elapsedTime - this->lastUpdatedTime) >= this->configuracion.GetPeriodoEmision()) {

		if (this->particulasGeneradas.size() >= this->configuracion.GetMaxParticulas()) {
			delete this->particulasGeneradas[0];
			this->particulasGeneradas.erase(this->particulasGeneradas.begin());
		}

		if (this->configuracion.GetParticula() != nullptr) {
			Solid* newParticle = this->configuracion.GetParticula()->Clone();

			Vector3D emitterPos = this->GetCoord();
			float jitter = 0.5f;


			newParticle->SetCoordinates(Vector3D(
				emitterPos.GetX() + RandomFloat(-jitter, jitter),
				emitterPos.GetY() + RandomFloat(-jitter, jitter),
				emitterPos.GetZ() + RandomFloat(-jitter, jitter)
			));

			Vector3D baseForce = this->configuracion.GetAceleracion();
			float spread = 2.0f;

			newParticle->SetSpeed(Vector3D(
				baseForce.GetX() + RandomFloat(-spread, spread),
				baseForce.GetY() + RandomFloat(0.0f, 2.0f),
				baseForce.GetZ() + RandomFloat(-spread, spread)
			));

			newParticle->SetRot(Orientation(Vector3D(
				RandomFloat(0.0f, 90.0f),
				RandomFloat(0.0f, 90.0f),
				RandomFloat(0.0f, 90.0f)
			)));

			newParticle->SetColor(Color(
				RandomFloat(0.2f, 1.0f),
				RandomFloat(0.2f, 1.0f),
				RandomFloat(0.2f, 1.0f)
			));

			newParticle->SetOrientationSpeed(Vector3D(
				RandomFloat(-5.0f, 5.0f),
				RandomFloat(-5.0f, 5.0f),
				RandomFloat(-5.0f, 5.0f)
			));

			this->particulasGeneradas.push_back(newParticle);
		}
		this->lastUpdatedTime = elapsedTime;
	}
}