#pragma once
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class BinarySearchTree
{
public:
    struct TreeNode
    {
        T data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    void Add(T value)
    {
        root = AddRecursive(root, value);
    }

private:
    TreeNode* AddRecursive(TreeNode* node, T value)
    {
        if (node == nullptr)
        {
            return new TreeNode(value);
        }

        // Permitir duplicados pero mandarlos a la izquierda
        if (value <= node->data)
        {
            node->left = AddRecursive(node->left, value);
        }
        else
        {
            node->right = AddRecursive(node->right, value);
        }

        return node;
    }
};
