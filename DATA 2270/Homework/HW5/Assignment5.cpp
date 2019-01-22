#include <iostream>
#include <string>
#include <fstream>
#include "HW5-MovieTree.hpp"

using namespace std;

MovieTree::MovieTree() {
	root = NULL;
}

MovieTree::~MovieTree() {
	//dtor
}

void printMovieHelper(MovieNode *temp){
	if(temp == NULL)
		return;
	printMovieHelper(temp->leftChild);
	cout << "Movie: " << temp->title << " " <<temp->quantity<<endl;
	printMovieHelper(temp->rightChild);

}

void MovieTree::printMovieInventory(){
	MovieNode *m = root;
	printMovieHelper(m);

}

void MovieTree::addMovieNode(int ranking, string title, int year, int quantity){
    MovieNode *temp = new MovieNode();//creating a temp node 
    MovieNode *newMovie = new MovieNode(ranking, title, year, quantity);
    if(root == NULL){
        root = newMovie;
        return;
    }temp = root;
	while(temp != NULL){
		if(title > temp->title){
			if(temp->rightChild == NULL){
				temp->rightChild = newMovie;
				break;
			}
			temp = temp->rightChild;
		}else if(title < temp->title){
			if(temp->leftChild == NULL){
				temp->leftChild = newMovie;
				break;
			}
			temp = temp->leftChild;
		}
	}
}

void MovieTree::findMovie(string title) {
	bool Found = true;
	MovieNode *temp = root;
	while(temp!=NULL) {
		if(temp->title.compare(title) > 0) {
			temp = temp->leftChild;
		} else if(temp->title.compare(title) < 0) { //searching for the movie
			temp = temp->rightChild;
		} else {
			cout << "Movie Info:" << endl;
			cout << "===========" << endl;
			cout << "Ranking:" << temp->ranking << endl; //info
			cout << "Title:" << temp->title << endl;
			cout << "Year:" << temp->year << endl;
			cout << "Quantity:" << temp->quantity << endl;
			Found = false;
			break;
		}
	}
	if(Found) {
		cout << "Movie not found." << endl;
	}
}


void MovieTree::rentMovie(string title) {
	bool notFound = true;
	MovieNode *temp = root;
	while(temp!=NULL) {
		if(temp->title.compare(title) > 0) {
			temp = temp->leftChild;
		} 
		else if(temp->title.compare(title) < 0) { //searching tree for movie
			temp = temp->rightChild;
		}else{//movie found
			notFound = false;
			if(temp->quantity > 0) {
				temp->quantity = temp->quantity-1; //if there are copies available
				cout << "Movie has been rented." << endl;
				cout << "Movie Info:" << endl;
				cout << "===========" << endl;
				cout << "Ranking:" << temp->ranking << endl;
				cout << "Title:" << temp->title << endl;
				cout << "Year:" << temp->year << endl;
				cout << "Quantity:" << temp->quantity << endl;
			} else {
				cout << "Movie out of stock." << endl;//if copies == 0
			}
			break;
		}
	}
	if(notFound) {
		cout << "Movie not found." << endl; //if name not match
	}
}


//search node
// MovieNode* MovieTree::search(MovieNode *node, string title) {
// 	node = root;
// 	while(node != NULL) {
// 		if(title.compare(node->title) < 0) {
// 			node = node->leftChild;
// 		} else if(title.compare(node->title) > 0) {
// 			node = node->rightChild;
// 		} else if(title.compare(node->title) == 0) {
// 			break;
// 		}
// 	}
// 	return node;
// }