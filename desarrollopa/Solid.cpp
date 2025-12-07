
#include "Solid.h"
void Solid::Update() {
	Orientation rotacion = this->GetRot().GetRotacion().Add(orientationSpeed.Product(incrementoTiempo));
	this->SetRot(rotacion);
	Vector3D posicion = this->GetCoord().Add(speed.Product(incrementoTiempo));
	this->SetCoordinates(posicion);
	Clone(); // NO SE SI VA AQUI
};