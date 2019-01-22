#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.hpp"

using namespace std;

HashTable::HashTable(int hashTableSize){
    HashTable::hashTableSize = hashTableSize;
    //wordItem* myHashTable[hashTableSize] = {};
}

HashTable::~HashTable(){
	for(int i = 0; i < hashTableSize; i++){
        if(hashTable[i] != NULL){
            delete hashTable[i];
        }
    }
}

int HashTable::getHash(string word){
    int hash = 5381;
    for (int i = 0; i < word.length(); i++){
        hash = hash*33 + word[i]; //finding hash code using DJB2
    }
    hash = hash % hashTableSize;
    if(hash < 0){
        hash += hashTableSize;
    }
    return hash;
}

bool HashTable::isStopWord(string word){
    bool isStop = false;
    int i = 0;
    while(i < STOPWORD_LIST_SIZE) {
        if(vecIgnoreWords[i] == word)
            isStop = true;
        i++;
    }
    return isStop;
}

bool HashTable::isInTable(string word){
	bool isTable = true;
    int i = 0;
    while(i < hashTableSize){
        if(vecIgnoreWords[i] == word)
            isTable = false;
        i++;
    }
    return isTable;
}

bool HashTable::isInTable(string word){
	bool isTable = true;
    int i = 0;
    while(i < hashTableSize) {
        if(vecIgnoreWords[i] == word)
            isTable = false;
        i++;
    }
    return isTable;
}


void HashTable::addWord(std::string word){
    bool stopWord = false;
    for(int i = 0; i <STOPWORD_LIST_SIZE; i++){
        if(vecIgnoreWords[i] == word){
            stopWord = true;
        }if(!stopWord){
            int hNum = getHash(word);
            wordItem* wordpointer = nullptr;
            wordpointer = searchTable(word);
            if(wordpointer != nullptr){
                wordpointer->count++;
                numCollisions++;
            }else{
                wordpointer = hashTable[hNum];
                if(wordpointer == nullptr){
                    wordpointer = new wordItem;
                    hashTable[hNum] = wordpointer;
                    wordpointer->word = word;
                    wordpointer->count = 1;
                    wordpointer->next = nullptr;
                }else{
                    while(wordpointer->next != nullptr){
                        wordpointer = wordpointer->next;
                    }
                    wordpointer->next = new wordItem;
                    wordpointer = wordpointer->next;
                    wordpointer->word = word;
                    wordpointer->count = 1;
                    wordpointer->next = nullptr;
                }
            }
        }
    }
}

void HashTable::getStopWords(char *ignoreWordFileName){
    ifstream in;
    string line;
    int index = 0;
    in.open(ignoreWordFileName);
    while(getline(in, line)){
        vecIgnoreWords[index] = line;
        index++;
    }
    in.close();
}

int HashTable::getTotalNumberNonStopWords(){
    wordItem* temp = nullptr;
    int num = 0;
    for(int i = 0; i < STOPWORD_LIST_SIZE; i++){
        temp = hashTable[i];
        while(temp != nullptr){
            num += temp->count;
            temp = temp->next;
        }
    }
    return num;
}

void HashTable::printTopN(int n){
    wordItem* tList = new wordItem[n];
    wordItem* search = nullptr;
    for(int i = 0; i < n; i++){
        tList[i].word = "NULL";
        tList[i].count = -1;
        tList[i].next = nullptr;
    }
    for(int j = 0; j < STOPWORD_LIST_SIZE; j++){
        search = hashTable[j];
        while(search != nullptr){
            int place = 0;
            for(int a = 0; a <= n; a++){
                if(tList[a].count > search->count){
                    place++;
                }
            }
            wordItem insert, temp;
            insert.word = search->word;
            insert.count = search->count;
            insert.next = nullptr;
            temp.word = "NULL";
            temp.count = -1;
            temp.next = nullptr;
            for(int b = place; b < n; b++){
                temp.word = tList[b].word;
                temp.count = tList[b].count;
                tList[b].word = insert.word;
                tList[b].count = insert.count;
                insert.word = temp.word;
                insert.count = temp.count;
            }
            search = search->next;
        }
    }
    for(int s = 0; s < n; s++){
        cout<<tList[s].count<<" - "<<tList[s].word<<endl;
    }
    delete [] tList;
}

int main(int argc, char *argv[]){
    if(argc != 5){
        cout<<
    }
}