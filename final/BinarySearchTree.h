#pragma once

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

double log_base_n(double x, double base);
int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo);

template <typename T>
class BinarySearchTree
{
	template <typename T>
	class TreeNode
	{
	public:
		TreeNode()
		{
			parent = leftChild = rightChild = nullptr;
			data = {};
		}

		TreeNode(T data)
		{
			parent = leftChild = rightChild = nullptr;
			this->data = data;
		}

		T data;
		TreeNode<T>* parent;
		TreeNode<T>* leftChild;
		TreeNode<T>* rightChild;
	};

public:
	BinarySearchTree()
	{
		root = nullptr;
		count = 0;
	}

	void AddWithAddRecursive(T value)
	{
		if (root == nullptr)
		{
			root = new TreeNode<T>(value);
			count++;
			return;
		}
		AddRecursive(value, root);
	}

	void InsertarNode(TreeNode<T>* currentNode, bool isLeftChild, T value)
	{
		TreeNode<T>* newNode = new TreeNode<T>(value);
		newNode->parent = currentNode;
		if (isLeftChild)
			currentNode->leftChild = newNode;
		else
			currentNode->rightChild = newNode;
		count++;
	}

	void AddRecursive(T value, TreeNode<T>* currentNode)
	{
		if (value > currentNode->data)
		{
			if (currentNode->rightChild == nullptr)
			{
				InsertarNode(currentNode, false, value);
				return;
			}
			else
			{
				return AddRecursive(value, currentNode->rightChild);
			}
		}
		else if (value < currentNode->data)
		{
			if (currentNode->leftChild == nullptr)
			{
				InsertarNode(currentNode, true, value);
				return;
			}
			else
			{
				return AddRecursive(value, currentNode->leftChild);
			}
		}
	}

	void Add(T value)
	{
		if (root == nullptr)
		{
			root = new TreeNode<T>(value);
			count++;
			return;
		}

		TreeNode<T>* currentNode = root;

		while (currentNode != nullptr)
		{
			if (value > currentNode->data)
			{
				if (currentNode->rightChild == nullptr)
				{
					InsertarNode(currentNode, false, value);
					return;
				}
				else
				{
					currentNode = currentNode->rightChild;
				}
			}
			else if (value < currentNode->data)
			{
				if (currentNode->leftChild == nullptr)
				{
					InsertarNode(currentNode, true, value);
					return;
				}
				else
				{
					currentNode = currentNode->leftChild;
				}
			}
		}
	}

	void InOrderWithRecursive()
	{
		InOrderRecursive(root);
	}

	int MinimaAltura()
	{
		return MinimaAlturaDeArbol(count, 2);
	}

	TreeNode<T>* root;
	int count;

	bool SearchWithRecursive(T value)
	{
		TreeNode<T>* resultNode = SearchRecursive(root, value);
		return resultNode != nullptr;
	}

	// NUEVA: Search iterativo
	bool Search(T value)
	{
		TreeNode<T>* current = root;
		while (current != nullptr)
		{
			if (current->data == value)
				return true;
			else if (value < current->data)
				current = current->leftChild;
			else
				current = current->rightChild;
		}
		return false;
	}

	// NUEVA: Borrar todo el árbol
	void ClearTree()
	{
		ClearRecursive(root);
		root = nullptr;
		count = 0;
	}

	// NUEVA: PostOrder iterativo
	void PostOrderIterative()
	{
		if (root == nullptr) return;

		stack<TreeNode<T>*> s1, s2;
		s1.push(root);

		while (!s1.empty())
		{
			TreeNode<T>* node = s1.top(); s1.pop();
			s2.push(node);

			if (node->leftChild) s1.push(node->leftChild);
			if (node->rightChild) s1.push(node->rightChild);
		}

		while (!s2.empty())
		{
			cout << s2.top()->data << endl;
			s2.pop();
		}
	}

	void Delete(T value)
	{
		TreeNode<T>* nodeToDelete = SearchRecursive(root, value);

		if (nodeToDelete == nullptr)
		{
			cout << "no existe el valor value en este árbol." << endl;
			return;
		}

		if (nodeToDelete->leftChild == nullptr &&
			nodeToDelete->rightChild == nullptr)
		{
			if (nodeToDelete->parent->leftChild == nodeToDelete)
				nodeToDelete->parent->leftChild = nullptr;
			else
				nodeToDelete->parent->rightChild = nullptr;

			count--;
			delete nodeToDelete;
			return;
		}

		if (nodeToDelete->leftChild == nullptr && nodeToDelete->rightChild != nullptr)
		{
			if (nodeToDelete->parent->leftChild == nodeToDelete)
				nodeToDelete->parent->leftChild = nodeToDelete->rightChild;
			else
				nodeToDelete->parent->rightChild = nodeToDelete->rightChild;

			nodeToDelete->rightChild->parent = nodeToDelete->parent;
			delete nodeToDelete;
			count--;
			return;
		}
		else if (nodeToDelete->leftChild != nullptr && nodeToDelete->rightChild == nullptr)
		{
			if (nodeToDelete->parent->leftChild == nodeToDelete)
				nodeToDelete->parent->leftChild = nodeToDelete->leftChild;
			else
				nodeToDelete->parent->rightChild = nodeToDelete->leftChild;

			nodeToDelete->leftChild->parent = nodeToDelete->parent;
			delete nodeToDelete;
			count--;
			return;
		}

		TreeNode<T>* successorNode = Successor(nodeToDelete);
		successorNode->leftChild = nodeToDelete->leftChild;
		nodeToDelete->leftChild->parent = successorNode;

		if (successorNode->parent->leftChild == successorNode)
			successorNode->parent->leftChild = successorNode->rightChild;
		else
			successorNode->parent->rightChild = successorNode->rightChild;

		// FIX: evitar acceso a nullptr
		if (successorNode->rightChild != nullptr)
			successorNode->rightChild->parent = successorNode->parent;

		successorNode->rightChild = nodeToDelete->rightChild;
		nodeToDelete->rightChild->parent = successorNode;

		successorNode->parent = nodeToDelete->parent;
		if (nodeToDelete->parent->leftChild == nodeToDelete)
			nodeToDelete->parent->leftChild = successorNode;
		else
			nodeToDelete->parent->rightChild = successorNode;

		count--;
		delete nodeToDelete;
	}

private:
	TreeNode<T>* TreeMaximum() { return Maximum(root); }
	TreeNode<T>* Maximum(TreeNode<T>* node)
	{
		TreeNode<T>* maximum = node;
		while (maximum->rightChild != nullptr)
			maximum = maximum->rightChild;
		return maximum;
	}

	TreeNode<T>* TreeMinimum() { return Minimum(root); }
	TreeNode<T>* Minimum(TreeNode<T>* node)
	{
		TreeNode<T>* minimum = node;
		while (minimum->leftChild != nullptr)
			minimum = minimum->leftChild;
		return minimum;
	}

	TreeNode<T>* MinimumRecursive(TreeNode<T>* currentNode)
	{
		if (currentNode->leftChild == nullptr)
			return currentNode;
		return MinimumRecursive(currentNode->leftChild);
	}

	TreeNode<T>* Successor(TreeNode<T>* node)
	{
		if (node->rightChild != nullptr)
			return Minimum(node->rightChild);

		TreeNode<T>* ancestor = node->parent;
		while (ancestor != nullptr && node == ancestor->rightChild)
		{
			node = ancestor;
			ancestor = node->parent;
		}
		return ancestor;
	}

	TreeNode<T>* Predecessor(TreeNode<T>* node)
	{
		if (node->leftChild != nullptr)
			return Maximum(node->leftChild);

		TreeNode<T>* ancestor = node->parent;
		while (ancestor != nullptr && node == ancestor->leftChild)
		{
			node = ancestor;
			ancestor = node->parent;
		}
		return ancestor;
	}

	TreeNode<T>* SearchRecursive(TreeNode<T>* currentNode, T value)
	{
		if (currentNode == nullptr)
			return nullptr;
		if (currentNode->data == value)
			return currentNode;
		if (value < currentNode->data)
			return SearchRecursive(currentNode->leftChild, value);
		return SearchRecursive(currentNode->rightChild, value);
	}

	void InOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			InOrderRecursive(node->leftChild);
			cout << node->data << endl;
			InOrderRecursive(node->rightChild);
		}
	}

	void PreOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			cout << node->data << endl;
			PreOrderRecursive(node->leftChild);
			PreOrderRecursive(node->rightChild);
		}
	}

	void PostOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			PostOrderRecursive(node->leftChild);
			PostOrderRecursive(node->rightChild);
			cout << node->data << endl;
		}
	}

	void ClearRecursive(TreeNode<T>* node)
	{
		if (node == nullptr) return;
		ClearRecursive(node->leftChild);
		ClearRecursive(node->rightChild);
		delete node;
	}
};
