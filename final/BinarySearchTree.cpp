// agora si ya corregido bien
template <typename T>
void BinarySearchTree<T>::Insert(Node*& node, T data)
{
    if (node == nullptr)
    {
        node = new Node{ data, nullptr, nullptr };
    }
    else
    {
        if (data <= node->data) 
            Insert(node->left, data);
        else
            Insert(node->right, data);
    }
}
