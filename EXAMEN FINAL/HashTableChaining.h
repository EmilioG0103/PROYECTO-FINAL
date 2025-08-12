#pragma once
#include <forward_list>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class HashTableChaining {
protected:
    forward_list<T>* data;
    unsigned int arraySize;

public:
    HashTableChaining(unsigned int size) {
        data = new forward_list<T>[size];
        arraySize = size;
    }

    int HashFunction(T key) {
        return key % arraySize;
    }

    virtual void Add(T element) {
        int index = HashFunction(element);
        data[index].push_front(element);
    }

    void Remove(T element) {
        int index = HashFunction(element);
        forward_list<T>& listAtIndex = data[index];
        for (auto i : listAtIndex) {
            if (i == element) {
                listAtIndex.remove(i);
                return;
            }
        }
        throw runtime_error("No element " + to_string(element) + " in this hash table.");
    }

    bool Contains(T element) {
        int index = HashFunction(element);
        forward_list<T>& listAtIndex = data[index];
        for (auto i : listAtIndex) {
            if (i == element) {
                return true;
            }
        }
        return false;
    }

    void Print() {
        for (int i = 0; i < arraySize; i++) {
            cout << "Lista del índice " << i << ": ";
            for (auto j : data[i])
                cout << j << ", ";
            cout << endl;
        }
    }
};

template <typename T>
class HashSet : public HashTableChaining<T> {
public:
    HashSet(unsigned int size) : HashTableChaining<T>(size) {}

    void Add(T element) override {
        if (!this->Contains(element)) {
            HashTableChaining<T>::Add(element);
        }
    }
};

