// Emilio Gonzalez Rosete
// Franco Emmanuel Ortega Cervantes

#include <iostream>
#include "BinarySearchTree.h"
#include "HashTableChaining.h"

using namespace std;

int main()
{
    cout << "=== Prueba BinarySearchTree ===" << endl;
    BinarySearchTree<int> bst;
    bst.Add(10);
    bst.Add(5);
    bst.Add(15);
    bst.Add(5); // duplicado

    cout << "Árbol cargado (no hay impresión visual en este ejemplo)." << endl;

    cout << "\n=== Prueba HashTableChaining ===" << endl;
    HashTableChainingExample();

    return 0;
}



// Utilizamos un video de YT para apoyarnos: Hash Tables and Hash Functions
// Y tambien utilizamos la IA para poyarnos a encontrar el error en el codigo que dejo usted
// primero lo checamos nosotros y ya que creiamos haberlo encontrado lo confirmamos con Chatgpt y nos dio algunas recomendaciones
// creo que si si entendimos bien lo que nos pide, ya quedó bien profe
