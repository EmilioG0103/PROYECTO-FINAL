#include "HashTableChaining.h"
#include <cstdlib>

void HashTableChainingExample()
{
    HashTableChaining<int> myHashTableChaining(4);
    myHashTableChaining.Add(39);
    myHashTableChaining.Add(252);
    myHashTableChaining.Add(40);
    myHashTableChaining.Add(0);
    myHashTableChaining.Add(24);

    myHashTableChaining.Print();

    if (!myHashTableChaining.Contains(1234))
    {
        cout << "No contiene 1234, intento de borrado seguro." << endl;
    }
    if (myHashTableChaining.Contains(40))
    {
        cout << "Contiene 40, borrando..." << endl;
        myHashTableChaining.Remove(40);
    }

    myHashTableChaining.Print();

    HashTableChaining<int> hashTableChainingExample(10);
    for (int i = 0; i < 100; i++)
    {
        int randNumber = rand() % 100;
        hashTableChainingExample.Add(randNumber);
    }
    hashTableChainingExample.Print();
}
