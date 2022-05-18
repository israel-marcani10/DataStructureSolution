#pragma once
#include <iostream>

using namespace std;

template<typename T>
class ColaCircular {
private:
	T* Data; // datos
	int Begin, End; // indices inicio y fin
	const int NumberElements; // numero de elementos

public:
	ColaCircular(int _NumberElements); // constructor
	void Push(T Value); // metodo para insertar
	T Get(); // metodo para quitar
	bool ColaLlena();
	bool ColaVacia();
	void VerCola();
};

template<typename T>
inline ColaCircular<T>::ColaCircular(int _NumberElements):NumberElements(_NumberElements) {
	Data = new T[NumberElements];
	Begin = End = 0;
}

template<typename T>
inline void ColaCircular<T>::Push(T Value) {
	if (!ColaLlena()) {
		End++;
		Data[End] = Value;
		cout << "Se ha insertado satisfactoriamente un elemento en la cola" << endl;
		if (End == NumberElements-1) { End = 0; }
	}
	else {
		cout << "La cola esta llena!!!" << endl;
	}
}

template<typename T>
inline T ColaCircular<T>::Get() {
	if (!ColaVacia()) {
		T ElementosObtenido = Data[Begin];
		Begin++;
		if (Begin == NumberElements - 1) { Begin = 0; }
		return ElementosObtenido;
	}
	else
		cout << "No se puede sacar elementos porque la cola esta vacia" << endl;

	return T();
}

template<typename T>
inline bool ColaCircular<T>::ColaLlena() {
	return ((End + 1) % NumberElements == Begin);
}

template<typename T>
inline bool ColaCircular<T>::ColaVacia()
{
	return (Begin == End);
}

template<typename T>
inline void ColaCircular<T>::VerCola() {
	if (!ColaVacia()) {
		cout << "\nLos datos de la cola son:" << endl;
		for (int i = Begin; i <= End; ++i)
			cout << Data[i] << endl;
	}
	else {
		cout << "La cola esta vacía" << endl;
	}
}
