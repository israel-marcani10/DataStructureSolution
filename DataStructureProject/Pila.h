#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Pila {
private:
	T* Data; // datos
	int tope; // cima
	const int NumberElements; // numero de elementos

public:
	Pila(int _NumberElements); // constructor
	void Push(T Value); // metodo para insertar
	T Pop(); // metodo para quitar
	bool PilaLlena();
	bool PilaVacia();
	void VerPila();
};

template<typename T>
inline Pila<T>::Pila(int _NumberElements):NumberElements(_NumberElements) {
	Data = new T[NumberElements];
	tope = -1;
}

template<typename T>
inline void Pila<T>::Push(T Value) {
	if (!PilaLlena()) {
		tope++;
		Data[tope] = Value;
		cout << "Se ha insertado satisfactoriamente un elemento en la pila" << endl;
	}
	else {
		cout << "Pila esta llena, no se pueden agregar mas datos" << endl;
	}
}

template<typename T>
inline T Pila<T>::Pop() {
	if (!PilaVacia()) {
		T ElementosObtenido = Data[tope];
		tope--;
		return ElementosObtenido;
	}
	else
		cout << "No se puede sacar elementos porque la pila esta vacia" << endl;

	return T();
}

template<typename T>
inline bool Pila<T>::PilaLlena() {
	return (tope == (NumberElements - 1));
}

template<typename T>
inline bool Pila<T>::PilaVacia()
{
	return (tope == -1);
}

template<typename T>
inline void Pila<T>::VerPila()
{
	if (!PilaVacia()) {
		cout << "\nLos datos de la pila son:" << endl;
		for (int i = 0; i <= tope; ++i)
			cout << Data[i] << endl;
	}
	else {
		cout << "La pila esta vacía" << endl;
	}
	
}
