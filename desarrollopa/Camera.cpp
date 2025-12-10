#include "Camera.h"
void Camera::Render() {
	gluLookAt(this->posicion.GetX(), this->posicion.GetY(), this->posicion.GetZ(),
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
}
//Lo arreglé ya no deberia de ser clonable, que quedaba feo jeje :D 
Solid* Camera::Clone() {
	return nullptr;
}