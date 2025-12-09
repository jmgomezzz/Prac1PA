#include "Solid.h"

void Solid::Update() {

    Vector3D desplazamiento = this->speed.Product(this->incrementoTiempo);
    Vector3D nuevaPosicion = this->coord.Add(desplazamiento);
    this->SetCoordinates(nuevaPosicion);
    Vector3D incrementoRotacion = this->orientationSpeed.Product(this->incrementoTiempo);
    Vector3D rotacionActual = this->rot.GetRotacion();
    Vector3D rotacionFinal = rotacionActual.Add(incrementoRotacion);
    this->SetRot(Orientation(rotacionFinal));
}