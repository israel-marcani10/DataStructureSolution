#pragma once

#include <iostream>

using namespace std;

struct NodoArbol {
	int dato;
	NodoArbol* der;
	NodoArbol* izq;
	NodoArbol* padre;
};

NodoArbol* arbol = nullptr;

// funcion para crear nodos
NodoArbol* crearNodo(int n, NodoArbol* padre) {
	NodoArbol* nuevoNodo = new NodoArbol();

	nuevoNodo->dato = n;
	nuevoNodo->der = nullptr;
	nuevoNodo->izq = nullptr;
	nuevoNodo->padre = padre;

	return nuevoNodo;
}

// funcion para insertar nodo al arbol
void insertarNodo(NodoArbol*& arbol, int n, NodoArbol* padre) {
	if (arbol==nullptr) { // si el arbol esta vacio
		NodoArbol* nuevoNodo = crearNodo(n, padre);
		arbol = nuevoNodo;
	}
	else {
		int valorRaiz = arbol->dato; // obtenemos al valor de la raiz
		if (n < valorRaiz) { // si el elemento es menor a la raiz, agregamos a la izquierda
			insertarNodo(arbol->izq, n, arbol);
		}
		else { // si el elemento es mayor a la raiz, agregamos a la derecha
			insertarNodo(arbol->der, n, arbol);
		}
	}
}

// funcion mostrar arbol
void mostrarArbol(NodoArbol* arbol, int cont) {
	if (arbol == nullptr)
		return;
	else {
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++)
			cout << "   ";
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont + 1);
	}
}

// buscar un elemento en el arbol
bool busqueda(NodoArbol* arbol, int n) {
	if (arbol == nullptr)
		return false;
	else if(arbol->dato == n) {
		return true;
	}
	else if (n < arbol->dato) {
		return busqueda(arbol->izq, n);
	}
	else {
		return busqueda(arbol->der, n);
	}
}

// recorrer el arbol en preOrden
void preOrden(NodoArbol* arbol) {
	if (arbol == nullptr)
		return;
	else {
		cout << arbol->dato << " - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

// recorrer el arbol en inOrden
void inOrden(NodoArbol* arbol) {
	if (arbol == nullptr)
		return;
	else {
		preOrden(arbol->izq);
		cout << arbol->dato << " - ";
		preOrden(arbol->der);
	}
}

// recorrer el arbol en PostOrden
void postOrden(NodoArbol* arbol) {
	if (arbol == nullptr)
		return;
	else {
		preOrden(arbol->izq);
		preOrden(arbol->der);
		cout << arbol->dato << " - ";
	}
}

// --------- metoos para elimnar un nodo del arbol----------

// metodo para hallar el nodo mas izquierdo posible
NodoArbol* minimo(NodoArbol* arbol) {
	if (arbol == nullptr) // si el arbol esta vacio
		return nullptr; // retornas nulo
	if (arbol->izq) { // si tiene hijo izquierdo
		return minimo(arbol->izq); // buscamos la parte mas izquierda posible
	}
	else { // si no tiene hijo izquierdo
		return arbol; // retornamos el mismo nodo
	}
}

// metodo para reemplazar dos nodos
void reemplazar(NodoArbol* arbol, NodoArbol* nuevoNodo) {
	if (arbol->padre) {
		// arbol->padre ayque asignarle su nuevo hijo
		if (arbol->dato == arbol->padre->izq->dato) {
			arbol->padre->izq = nuevoNodo;
		}
		else if (arbol->dato == arbol->padre->der->dato) {
			arbol->padre->der = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		// procedemos a asignarle su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}

// destruir nodo
void destruirNodo(NodoArbol* nodo) {
	nodo->izq = nullptr;
	nodo->der = nullptr;
	delete nodo;
}

// metodo para eliminar si el nodo tiene dos hijos
void eliminarNodo(NodoArbol* nodoEliminar) {
	if (nodoEliminar->izq && nodoEliminar->der) { // si el nodo tiene dos hijos
		NodoArbol* menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if (nodoEliminar->izq) { // si el nodo tiene hijo izquierdo
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if (nodoEliminar->der) { // si el nodo tiene un hijo derecho
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else { // si un nodo no tiene hijo (nodo hoja)
		reemplazar(nodoEliminar, nullptr);
		destruirNodo(nodoEliminar);
	}
}

// eliminar nodo del arbol
void eliminar(NodoArbol* arbol, int n) {
	if (arbol == nullptr)
		return;
	else if (n < arbol->dato) {
		eliminar(arbol->izq, n);
	}
	else if (n > arbol->dato) {
		eliminar(arbol->der, n);
	}
	else {
		eliminarNodo(arbol);
	}
}

// menu
void Menu() {
	int dato, opcion, contador = 0;
	do {
		cout << "\t.:MENU:." << endl;
		cout << "1. Insertar un nuevo nodo" << endl;
		cout << "2. Mostrar el arbol completo" << endl;
		cout << "3. Buscar un elemento en el arbol" << endl;
		cout << "4. Recorrer el arbol en PreOrden" << endl;
		cout << "5. Recorrer el arbol en InOrden" << endl;
		cout << "6. Recorrer el arbol en PostOrden" << endl;
		cout << "7. Eliminar un nodo del arbol" << endl;
		cout << "8. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1: cout << "\nDigite un numero: ";
			cin >> dato;
			insertarNodo(arbol, dato, nullptr); // insertamos un nuevo nodo
			cout << "\n";
			system("pause");
			break;
		case 2: cout << "Mostrando el arbol completo: \n\n";
			mostrarArbol(arbol, contador);
			cout << "\n";
			system("pause");
			break;
		case 3: cout << "\nDigite el elemento a buscar: ";
			cin >> dato;
			if (busqueda(arbol, dato)) {
				cout << "\nElemento " << dato << " ha sido encontrado en el arbol" << endl;
			}
			else {
				cout << "\nElemento no encontrado" << endl;
				cout << endl;
			}
			system("pause");
			break;
		case 4: cout << "\nRecorrido en PreOrden:";
			preOrden(arbol);
			cout << "\n\n";
			system("pause");
			break;
		case 5: cout << "\nRecorrido en InOrden: ";
			inOrden(arbol);
			cout << "\n\n";
			system("pause");
			break;
		case 6: cout << "\nRerrido en PostOrden" << endl;
			postOrden(arbol);
			cout << "\n\n";
			system("pause");
			break;
		case 7: cout << "\nDigite el numero a eliminar: ";
			cin >> dato;
			eliminar(arbol, dato);
			cout << "\n\n";
			system("pause");
			break;
		}
		system("cls");
	} while (opcion != 8);
}