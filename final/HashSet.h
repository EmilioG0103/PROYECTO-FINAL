#ifndef HASHSET_H
#define HASHSET_H

#include "HashTableChaining.h"

template <typename T>
class HashSet
{
private:
    HashTableChaining<T> data;

public:
    HashSet(unsigned int size) : data(size) {}

    void Add(T element) {
        if (!data.Contains(element)) {
            data.Add(element);
        }
    }

    void Remove(T element) {
        data.Remove(element);
    }

    bool Contains(T element) {
        return data.Contains(element);
    }

    void Print() {
        data.Print();
    }
};

#endif
