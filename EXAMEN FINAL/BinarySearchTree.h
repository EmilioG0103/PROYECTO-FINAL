#pragma once
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;

    TreeNode<T>* AddRecursive(TreeNode<T>* node, T data);

public:
    BinarySearchTree();

    void Add(T data);
    void InOrder(TreeNode<T>* node);
    void InOrder();
    bool Search(T data);
    void PostOrderIterativo();

    TreeNode<T>* GetRoot() { return root; }
};
