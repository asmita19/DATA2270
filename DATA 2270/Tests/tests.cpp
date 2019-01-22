#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

//creates a node
struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        this->key = k;
        this->left = this->right = NULL;
    }
}; 

void print(Node* n){
    if(n == NULL){
        return;
    }
    cout<<n->key<<" ";
    print(n->left);
    print(n->right);
}


// //Class to organize the linked list
// class List{
//     Node *head,*tail;
// public:
//     List(){
//         //assign head and tail to NULL to avoid garbage values
//         head = NULL; 
//         tail = NULL;
//     }
//     //create functions to interact with the list
    
//     //insert a new node at the end of the linked list
//     void addNode(int);
//     //pring all the elements of the list onto the screen
//     void transverse();
// };

// //appending an element
// void List::addNode(int value){
//     Node *temp = new Node; //creating a new node which is temporary and assigning a new address to it by saying new Node
//     temp->data = value; //setting the value of its data member to the value passed as parameter 
//     temp-> link = NULL; //setting its link equal to NULL b/c this will be made the new tail of our list 
    
//     //if head equals to NULL, create a new node, if only one element then
//     // the element is the head and tail of the list
//     if(head == NULL){
//         head = temp;
//         tail = temp;
//         temp = NULL;//optional
//     }else{
//         //if the list isnt empty
//         tail ->link = temp;
//         tail = temp;
//         temp = NULL;
//     }
// }

// void List::transverse(){
//     Node *temp = head; //declare a new element called head
//     while(temp != NULL){ //while the temporary node isn't equal to NULL continue to print the value
//         cout<<temp->data<<endl;//points to the first node and print out the value in the first node
//         temp = temp->link; //point to the next element and check if the next element is NULL
        
    //}
    
int main(){
    Node* root = new Node(12);
    root->left = new Node(6);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    print(root);
    
    // List mylist;
    
    // //create a loop to insert values 1 to 10 inside the list
    // for(int i = 1; i<=20; i++){
    //     mylist.addNode(i);//loop to add all th elements
    // }
    
    // //omce the loop has finished adding up the elements call the transverse funation
    // //to print all the elements on the screen
    // mylist.transverse();
    // //system('pause');//optional to pause 
    // return 0;
}