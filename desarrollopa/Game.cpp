#include "Game.h"
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>  


// Constructor
Game::Game() : emisor(nullptr) {}


void Game::Init()
{

	srand(time(NULL)); //Semilla para aleatorios

	//EMSIOR DE PARTICULAS
	//Creamos el emisor
	emisor = new Emmiter(&escena);
	emisor->SetCoordinates(Vector3D(0.0, 0.0, 0.0));

	//Propiedades de las parts
	EmmiterConfiguration& config = emisor->GetConfiguracion();
	config.SetParticula(&sphere);
	config.SetMaxParticulas(200);
	config.SetPeriodoEmision(2000);
	//config.SetTiempoVida(8000); por ahora no lo usamos

	//Añadimos el emisor
	escena.AddGameObject(emisor);
}

void Game::Render()
{
	//cout << "[GAME] Render..." << endl;
	this->escena.Render();
	
}

void Game::Update()
{
	//cout << "[GAME] Update..." << endl;
	this->escena.Update();
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
