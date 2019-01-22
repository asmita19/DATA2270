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

MovieTree::search( std::string title){
	MovieNode *node;
	bool fini = false;
	if(node){
		while(!fini){
			if(title < node->title){
				if(node->leftChild) node=node->leftChild;
				else fini = true;
			}else if(title > node->title){
				if(node->rightChild) node=node->rightChild;
				else fini = true;
			}else{
				fini = true;
				return node;
			}
		}
	}
	return NULL;
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

int cHelper(MovieNode *test){
   int temp = 1;
   if(test->leftChild != NULL){
   	temp += cHelper(test->leftChild);
   }
   if(test->rightChild != NULL){
   	temp += cHelper(test->rightChild);
   }
   return temp;
}

void MovieTree::countMovies(){
	MovieNode *i = root;
	int incre;
	if(i == NULL){ 
       incre = 0;
   }else{
   	incre = cHelper(i);
   }
	cout << "Count = " << count << endl;
}

void MovieTree::deleteMovie(std::string title){
    MovieNode* aim = search(title);

    if(aim != NULL){
        if(aim->leftChild == NULL && aim->rightChild == NULL){ // aim has no children
            if(aim == root){
                root = NULL;
            }else{
                aim = NULL;
            }
        }else if(aim->leftChild != NULL && aim->rightChild == NULL){ //aim with left child
            if(aim == root){
                root = aim->leftChild;
            }
            else{
                aim->leftChild->parent = aim->parent;
                aim->parent->leftChild = aim->leftChild;
            }  
        }else if(aim->leftChild == NULL && aim->rightChild != NULL){ //aim with right child
            if(aim == root){
                root = aim->rightChild;
            }else{
                aim->rightChild->parent = aim->parent;
                aim->parent->rightChild = aim->rightChild;
            }  
        }
        else if(aim->leftChild != NULL && aim->rightChild != NULL){ //aim with two children  replace with left
            if(aim == root){
                root = aim->leftChild;
                root->rightChild = aim->rightChild;
            }else{
                aim->leftChild->parent = aim->parent;
                aim->parent->leftChild = aim->leftChild;
            }  
        }
     }else{
        cout<<"Movie not found."<<endl;

     }
     delete aim;
     aim = NULL;
}
