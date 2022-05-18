#include "Pila.h"
#include "Cola.h"
#include <iostream>

using namespace std;

int main() {
	Pila<int>ps(5);
	ps.Push(45);
	ps.Push(12);

	ps.VerPila();


	ColaCircular<string>cs(5);
	cs.Push("Hola");
	cs.Push("hey");

	cs.VerCola();
}
