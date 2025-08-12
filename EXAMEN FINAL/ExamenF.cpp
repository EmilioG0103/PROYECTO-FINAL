// Emilio Gonzalez Rosete
// Franco Emmanuel Ortega Cervantes

#include <iostream>
#include "BinarySearchTree.h"
#include "HashTableChaining.h"
using namespace std;

int main() {
    cout << "=== Prueba BinarySearchTree ===" << endl;
    BinarySearchTree<int> arbol;
    arbol.Add(5);
    arbol.Add(3);
    arbol.Add(8);
    arbol.Add(3); // duplicado, debe ir a la izquierda
    arbol.Add(7);
    arbol.Add(9);

    cout << "InOrder: ";
    arbol.InOrder();

    cout << "Busqueda de 7: " << (arbol.Search(7) ? "Encontrado" : "No encontrado") << endl;

    cout << "PostOrder Iterativo: ";
    arbol.PostOrderIterativo();

    cout << "\n=== Prueba HashSet ===" << endl;
    HashSet<int> conjunto(5);
    conjunto.Add(10);
    conjunto.Add(20);
    conjunto.Add(10); // repetido, no se agrega
    conjunto.Print();

    return 0;
}

// Utilizamos un video de YT para apoyarnos: Hash Tables and Hash Functions
// Y tambien utilizamos la IA para poyarnos a encontrar el error en el codigo que dejo usted
// primero lo checamos nosotros y ya que creiamos haberlo encontrado lo confirmamos con Chatgpt y nos dio algunas recomendaciones
// creo que si si entendimos bien lo que nos pide, ya quedó bien profe
