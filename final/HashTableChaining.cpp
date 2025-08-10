#include "HashTableChaining.h"


void HashTableChainingExample()
{
	HashTableChaining<int> myHashTableChaining = HashTableChaining<int>(4);
	myHashTableChaining.Add(39);
	myHashTableChaining.Add(252);
	myHashTableChaining.Add(40);
	myHashTableChaining.Add(0);
	myHashTableChaining.Add(24);

	myHashTableChaining.Print();

	// checamos contains y luego remove
	if (!myHashTableChaining.Contains(1234))
	{
		cout << "myHashTableChaining no contiene el valor 1234, lo vamos a intentar borrar, para corroborar que no truena" << endl;
		// myHashTableChaining.Remove(1234);
	}
	if (myHashTableChaining.Contains(40))
	{
		cout << "myHashTableChaining sí contiene el valor 40, ahora lo vamos a borrar" << endl;
		myHashTableChaining.Remove(40);
	}

	myHashTableChaining.Print();


	HashTableChaining<int> hashTableChainingExample = HashTableChaining<int>(100);

	// metemos 100 números aleatoreos.
	for (int i = 0; i < 100; i++)
	{
		int randNumber = rand() % 2;
		hashTableChainingExample.Add(randNumber);
	}
	// esperaríamos, en promedio, que a cada índice de la hash table le añadan 10 elementos, 
	// porque son 10 índices, y 100/100 = 1.
	hashTableChainingExample.Print();



}