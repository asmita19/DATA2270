#include"HashTable.h"

/*
Inserts an item in the hash table.
Use the hash function on the key to get the slot.
Insert the key in that slot of hash table.
*/
void Hash::insertItem(int key){
     // TODO
     int index = hashFunc(key);
     hashTable[index].push_back(key); //inserting into index
}

/*
Given a key, search if the key exists in the hash table.
*/
void Hash::searchItem(int key)
{
     //Compute the index by using the hash function
     int index = hashFunc(key);
    //Search the list at that specific index, write print statements to justify if you did/didn't find the key

    bool found = false;

    // TODO

    vector<int>::iterator i;
    for(i=hashTable[index].begin(); i!=hashTable[index].end(); i++)
    {
      if(*i==key){
        cout << key << " found in has table!!"<<endl;
        found = true;
      }
    }

    if(!found)
    {
      cout<<key<<"  not found in the hash table"<<endl;
    }
}

// main program
int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12, 7, 18};
  int n = 7;

  // Creates a hash table of size 7
  Hash h(7);

  // insert the keys into the hash table
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]);

  h.searchItem(8);
  h.searchItem(10);
  cout<<endl<<endl;

  cout<<"Contents of the hash table are"<<endl;
  // display the Hash table
  h.displayHash();

  return 0;
}
