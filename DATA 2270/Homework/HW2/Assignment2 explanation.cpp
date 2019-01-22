#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void getStopWords(char *ignoreWordFileName, std::string ignoreWords[]);
/*
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param ignoreWords - the array of strings storing ignore/stop words *
@return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(std::string word, std::string ignoreWords[]);
/*
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array
(including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including
repeated words multiple times)
*/
int getTotalNumberNonStopWords(wordItem list[], int length);
/*
* Function name: arraySort
* Purpose: sort an array of wordItems, increasing, by their count
fields * @param list - an array of wordItems to be sorted
* @param length - the length of the words array
*/
void arraySort(wordItem list[], int length);
/*
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of
wordItems * @param topN - the number of top frequency words to print
* @return none
*/
