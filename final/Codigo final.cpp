// Emilio Gonzalez Rosete
// Franco Emmanuel Ortega Cervantes

#include <iostream>
#include <cmath>
#include "BinarySearchTree.h"
#include "HashSet.h"
using namespace std;

double logBase(double valor, double base) {
    return log(valor) / log(base);
}

int calcularAlturaMinima(int nodos, int hijosMax) {
    int formula = (hijosMax - 1) * nodos + 1;
    int altura = ceil(logBase(formula, hijosMax)) - 1;
    return altura;
}

int main() {
    cout << "Altura mínima con 9 nodos y max 2 hijos: "
         << calcularAlturaMinima(9, 2) << endl;

    // Prueba BinarySearchTree
    BinarySearchTree<int> arbol;
    arbol.Insert(5);
    arbol.Insert(3);
    arbol.Insert(8);
    arbol.Insert(2);
    arbol.Insert(4);
    arbol.Insert(7);
    arbol.Insert(9);

    cout << "Busqueda de 7: " << (arbol.Search(7) ? "Encontrado" : "No encontrado") << endl;

    cout << "Post-order iterativo: ";
    arbol.PostOrderIterativo();

    // Prueba HashSet
    HashSet<int> conjunto(5);
    conjunto.Add(10);
    conjunto.Add(20);
    conjunto.Add(10); // repetido
    cout << "Contenido de HashSet:\n";
    conjunto.Print();

    return 0;
}


// Utilizamos un video de YT para apoyarnos: Hash Tables and Hash Functions
// Y tambien utilizamos la IA para poyarnos a encontrar el error en el codigo que dejo usted
// primero lo checamos nosotros y ya que creiamos haberlo encontrado lo confirmamos con Chatgpt y nos dio algunas recomendaciones
// creo que si si entendimos bien lo que nos pide, ya quedó bien profe

