#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct wordItem{
    string word;
    int count;
};

//#1:DONE
void getStopWords(char *ignoreWordFileName, string ignoreWords[]){
    ifstream myfile(ignoreWordFileName);
    int index = 0;
    if(myfile.is_open()){
        string line;
        string unique;
        while(getline(myfile, line)){
            stringstream ss(line);
            ss>>unique;
            ignoreWords[index] = unique;
            index++;
        }
    }
    myfile.close();
}

//#2:DONE
bool isStopWord(string word, string ignoreWords[]){
    bool words = false;
    for(int i = 0; i < 50; i++){
        if(word == ignoreWords[i]){
            words = true;
            //return words;
            break;
        }
    }
    return words;
}
//#3:DONE
int getTotalNumberNonStopWords(wordItem list[],int length){
    int index = 0;
	for(int i = 0; i < length; i++){
		index=index+list[i].count;
	}
	return index;
}

//#4:DONE
void arraySort(wordItem list[], int length){
    for(int i = 0; i < length; i++){
        for(int j = 1 + i; j < length; j++){
            if(list[j].count > list[i].count){
                wordItem tempo;
                tempo = list[j];
                list[j] = list[i];
                list[i] = tempo;
            }
        }
    }
}

//#5:DONE
void printTopN(wordItem wordItemList[], int topN){
    for(int i = 0; i < topN; i++){
        cout<<wordItemList[i].count<<" - "<<wordItemList[i].word<<endl;
    }
}

int doubleCount = 0;
 
//main function:
int main(int argc, char *argv[1]){
    int sizeOfArray = 100;
    bool stop;
    
    wordItem *wordArray = new wordItem[100];
    int topN = atoi(argv[1]), uniqueWords = 0, nonStopNum = 0;
    string ignoreWords[50], word;
    getStopWords(argv[3], ignoreWords);
    
    ifstream hungergamesfile(argv[2]);
    if(hungergamesfile.is_open()){
        while(getline(hungergamesfile, word)){
            istringstream ss(word);
            while(ss >> word){
                bool find = false;
                stop = isStopWord(word, ignoreWords);
                if(stop == false){
                    for(int i = 0; i < uniqueWords; i++){
                        if(word == wordArray[i].word){
                            find = true;
                            wordArray[i].count++;
                            break;
                        }
                    }
                    if(find == false){
                        wordArray[uniqueWords].word = word;
                        wordArray[uniqueWords].count = 1;
                        uniqueWords++;
                        
                        if((sizeOfArray - 1) == uniqueWords){
                            wordItem *nayaArray = new wordItem[sizeOfArray*2];
                            for(int j = 0; j < sizeOfArray; j++){
                                nayaArray[j] = wordArray[j];
                            }
                            delete [] wordArray;
                            wordArray = nayaArray;
                            sizeOfArray = sizeOfArray*2;
                            doubleCount++;
                        }
                    }
                }
            }
        }
        nonStopNum = getTotalNumberNonStopWords(wordArray, uniqueWords);
        arraySort(wordArray, uniqueWords);
        printTopN(wordArray, topN);
        
        cout<<"#"<<endl;
        cout<<"Array doubled: "<<doubleCount<<endl;
        cout<<"#"<<endl;
        cout<<"Unique non-common words: "<<uniqueWords<<endl;
        cout<<"#"<<endl;
        cout<<"Total non-common words: "<<nonStopNum<<endl;
    }
    return 0;
}