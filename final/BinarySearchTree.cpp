// Corregir el error del insert
template <typename T>
void BinarySearchTree<T>::Insert(Node*& node, T data)
{
    if (node == nullptr)
    {
        node = new Node{ data, nullptr, nullptr };
    }
    else
    {
        if (data < node->data)
            Insert(node->left, data);
        else if (data > node->data)
            Insert(node->right, data);
        // Si data == node->data, no se inserta para evitar duplicados
    }
}
