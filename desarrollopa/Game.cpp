#include "Game.h"
#include <iostream>

// En Game.cpp
void Game::Init() {
	this->particulaBase = new Cube();
	// Dale un color base visible (aunque el randomizador lo cambie luego)
	this->particulaBase->SetColor(Color(1.0, 0.0, 0.0));

	// Configuración potente: 300 partículas, muy rápido
	EmmiterConfiguration config(300, 10, this->particulaBase, Vector3D(0.0, 7.0, 0.0), 5000);

	this->emisor = new Emmiter();
	this->emisor->SetConfiguration(config);

	// POSICIÓN VISIBLE: En el centro (0,0) y profundidad (-3.0) igual que la tetera
	this->emisor->SetCoordinates(Vector3D(0.0, 0.0, -3.0));
}

void Game::Render() {
	// Decoración
	this->teapot.Render();
	this->cube.Render();
	this->sphere.Render();
	this->cuboid.Render();
	this->cylinder.Render();
	this->toroid.Render();

	// Emisor
	if (this->emisor != nullptr) {
		this->emisor->Render();
	}
}

void Game::Update() {
	// Decoración
	this->teapot.Update();
	this->cube.Update();
	this->sphere.Update();
	this->cuboid.Update();
	this->cylinder.Update();
	this->toroid.Update();

	// Emisor
	if (this->emisor != nullptr) {
		this->emisor->Update();
	}
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "[GAME] Key:" << key << endl;
	/*if (key == '0') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
		prisma7.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma5.SetColor(Color(1.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 1.0,1.0));
	}
	if (key == '1') {
		prisma1.SetColor(Color(1.0, 1.0, 1.0));
		prisma2.SetColor(Color(1.0, 1.0, 1.0));
		prisma3.SetColor(Color(1.0, 1.0, 1.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma5.SetColor(Color(1.0, 1.0, 1.0));
		prisma7.SetColor(Color(1.0, 1.0, 1.0));
	}
	if (key == '2') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 0.0, 0.0));
		prisma5.SetColor(Color(1.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 1.0, 1.0));
		prisma7.SetColor(Color(1.0, 1.0, 1.0));
	}
	if (key == '3') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0, 0.0, 0.0));
		prisma5.SetColor(Color(1.0, 1.0, 1.0));
		prisma7.SetColor(Color(1.0, 1.0, 1.0));
	}
	if (key == '4') {
		prisma7.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma1.SetColor(Color(1.0, 1.0, 1.0));
		prisma3.SetColor(Color(1.0, 1.0, 1.0));
		prisma5.SetColor(Color(1.0, 1.0, 1.0));
	}
	if (key == '5') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma7.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0, 0.0, 0.0));
		prisma5.SetColor(Color(1.0, 1.0, 1.0));
		prisma6.SetColor(Color(1.0, 1.0, 1.0));
	}
	if (key == '6') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma7.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0, 0.0, 0.0));
		prisma5.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 1.0, 1.0));
	}
	if (key == '7') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 1.0, 1.0));
		prisma3.SetColor(Color(1.0, 1.0, 1.0));
		prisma5.SetColor(Color(1.0, 1.0, 1.0));
		prisma7.SetColor(Color(1.0, 1.0, 1.0));
	}
	if (key == '8') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma7.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0, 0.0, 0.0));
		prisma5.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
	}
	if (key == '9') {
		prisma1.SetColor(Color(1.0, 0.0, 0.0));
		prisma7.SetColor(Color(1.0, 0.0, 0.0));
		prisma2.SetColor(Color(1.0, 0.0, 0.0));
		prisma6.SetColor(Color(1.0, 0.0, 0.0));
		prisma4.SetColor(Color(1.0, 0.0, 0.0));
		prisma3.SetColor(Color(1.0, 1.0, 1.0));
		prisma5.SetColor(Color(1.0, 1.0, 1.0));
	}*/
	
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;
	/*srand(time(NULL));
	int obj = rand() % 4 + 1;//el objeto que se va a cambiar
	int atr = rand() % 4 + 1;//el atributo a modificar
	if (button==0 && state==0) {
		Color c((rand() % 10 + 1) / 10, (rand() % 10 + 1) / 10, (rand() % 10 + 1) / 10);
		Vector3D p((rand() % 2)+((rand() % 60)/10), (rand() % 2)+((rand() % 30) / 10), -3.0);
		Orientation r((rand() % 100), (rand() % 100), (rand() % 100));
		float s = rand() % 3 + 1;
		if (obj == 1) {
			if (atr == 1) {
				teapot.SetCoordinates(p);
			}else if (atr == 2) {
				teapot.SetColor(c);
			}else if (atr == 3) {
				teapot.SetOrientation(r);
			}else if (atr == 4) {
				teapot.SetSize(s);
			}
		}
		else if (obj == 2) {
			if (atr == 1) {
				cube.SetCoordinates(p);
			}
			else if (atr == 2) {
				cube.SetColor(c);
			}
			else if (atr == 3) {
				cube.SetOrientation(r);
			}
			else if (atr == 4) {
				cube.SetSize(s);
			}
		}
		else if (obj == 3) {
			if (atr == 1) {
				cuboid.SetCoordinates(p);
			}
			else if (atr == 2) {
				cuboid.SetColor(c);
			}
			else if (atr == 3) {
				cuboid.SetOrientation(r);
			}
		}
		else if (obj == 4) {
			if (atr == 1) {
				sphere.SetCoordinates(p);
			}
			else if (atr == 2) {
				sphere.SetColor(c);
			}
			else if (atr == 3) {
				sphere.SetOrientation(r);
			}
		}
	}*/
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
}
