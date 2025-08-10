// Emilio Gonzalez Rosete
// Franco Emmanuel Ortega Cervantes

#include <iostream>
#include "BinarySearchTree.h"
#include "HashTableChaining.h"

using namespace std;

int main() {
    cout << "Altura minima con 9 nodos y max 2 hijos: "
         << MinimaAlturaDeArbol(9, 2) << endl;

    // Crea árbol binario usando BinarySearchTree
    BinarySearchTree<int> arbol;
    arbol.Add(5);
    arbol.Add(3);
    arbol.Add(8);
    arbol.Add(2);
    arbol.Add(4);
    arbol.Add(7);
    arbol.Add(9);

    cout << "Busqueda de 7: " << (arbol.SearchWithRecursive(7) ? "Encontrado" : "No encontrado") << endl;

    cout << "Post-order iterativo: ";
    arbol.PostOrderIterativo();  

    // HashSet que hereda de HashTableChaining
    HashSet<int> conjunto(5);
    conjunto.Add(10);
    conjunto.Add(20);
    conjunto.Add(10);  // No se añade porque ya existe
    cout << "Contenido de HashSet:\n";
    conjunto.Print();

    return 0;
}

