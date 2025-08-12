#include "BinarySearchTree.h"

// Constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

// Ejercicio 1 corregido
template <typename T>
TreeNode<T>* BinarySearchTree<T>::AddRecursive(TreeNode<T>* node, T data) {
    if (node == nullptr) {
        return new TreeNode<T>(data);
    }
    if (data <= node->data) { 
        node->left = AddRecursive(node->left, data);
    }
    else {
        node->right = AddRecursive(node->right, data);
    }
    return node;
}

template <typename T>
void BinarySearchTree<T>::Add(T data) {
    root = AddRecursive(root, data);
}

// Recorrido in-order recursivo
template <typename T>
void BinarySearchTree<T>::InOrder(TreeNode<T>* node) {
    if (node != nullptr) {
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }
}

template <typename T>
void BinarySearchTree<T>::InOrder() {
    InOrder(root);
    cout << endl;
}

// Búsqueda iterativa
template <typename T>
bool BinarySearchTree<T>::Search(T data) {
    TreeNode<T>* actual = root;
    while (actual) {
        if (data == actual->data) return true;
        actual = (data < actual->data) ? actual->left : actual->right;
    }
    return false;
}

// Post-order iterativo
template <typename T>
void BinarySearchTree<T>::PostOrderIterativo() {
    if (!root) return;
    stack<TreeNode<T>*> pila;
    TreeNode<T>* ultimoVisitado = nullptr;
    TreeNode<T>* actual = root;

    while (!pila.empty() || actual) {
        if (actual) {
            pila.push(actual);
            actual = actual->left;
        }
        else {
            TreeNode<T>* tope = pila.top();
            if (tope->right && ultimoVisitado != tope->right) {
                actual = tope->right;
            }
            else {
                cout << tope->data << " ";
                ultimoVisitado = tope;
                pila.pop();
            }
        }
    }
    cout << endl;
}

template class BinarySearchTree<int>;

