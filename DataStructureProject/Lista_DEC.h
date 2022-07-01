#pragma once

#include <iostream>

using namespace std;

struct Nodo {
	int Dato;
	Nodo* Siguiente;
	Nodo* Anterior;
};

Nodo* Primero = nullptr;
Nodo* Ultimo = nullptr;


/*
ejemplo:
	dato: 5
primero = 5		ultimo = 5
5 <- 5 -> 5

	dato: 7
primero = 5		ultimo = 7
7 <- 5 -> <- 7 -> 5

	dato: 9
primero = 5		ultimo = 9
9 <- 5 -> <- 7 -> <- 9 -> 5
*/


void ingresar_datos() {
	Nodo* Nuevo_Nodo = new Nodo();
	cout << "Digite el dato que desea guardar: ";
	cin >> Nuevo_Nodo->Dato;
	if (Primero == nullptr)
	{
		Primero = Nuevo_Nodo;
		Primero->Siguiente = Primero;
		Primero->Anterior = Primero;
		Ultimo = Primero;
	}
	else {
		Ultimo->Siguiente = Nuevo_Nodo;
		Nuevo_Nodo->Siguiente = Primero;
		Nuevo_Nodo->Anterior = Ultimo;
		Ultimo = Nuevo_Nodo;
		Primero->Anterior = Ultimo;
	}
}


void mostrar() {
	Nodo* aux = new Nodo();
	aux = Primero;
	if (Primero != nullptr) {
		do {
			cout << " [" << aux->Dato << "] ";
			aux->Siguiente;
		} while (aux!=Primero);
	}
	else {
		cout << "La Lista está VACIA!!!\n";
	}
}
