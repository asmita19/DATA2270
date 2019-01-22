#include <iostream>
#include <string>

using namespace std;


/*A bianary */
struct Node{
    int data;
    struct Node* left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

/**/
void printPostorder(struct Node* node){
    if(node = NULL){
        return;
    }
    
    //
    printPostorder(node->left);
    
    //
    printPostorder(node->right);
    
    //
    cout<<node->data<<" ";
}

//
void printInorder(int Node* node){
    if(node == NULL)
    return;
    
    //
    printInorder(node->left);
}
 
/**/
void printPreorder(int node* node){
    
}


