#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};


//#2:
/*Write a program that creates a linked list of integers, and a function that takes an index and deletes the node at that index, if it exists.
Requirements:
1. Implement the deleteIndex function:
Node *deleteIndex(Node *head, int index);
This function takes a linked list and an index in that list (indices start at 0). The function should delete the node at that index. If the index is outside the bounds of
the list, it should not delete anything. The function should return the new head of the list. It must delete the nodes from memory, rather than just removing them
from the list.
Examples:
If the list is 6 -> 3 -> 9 -> 6 -> NULL , calling deleteIndex(head, 2) should change the list to be 6 -> 3 -> 6 -> NULL and return the old head.
If the list is 6 -> 3 -> NULL , calling deleteIndex(head, 2) should keep the list the same and return the old head.
If the list is 6 -> NULL , calling deleteIndex(head, 0) should change the list to be NULL and return NULL .
1. Write a main function that creates a linked list of integers, then calls the function defined in part (1) to delete various indices from that list. It should call the
function multiple times, to show that your function can handle any possible index.
2. Test your function to make sure that it w orks in every case, no matter w hich index the user passes in!*/

Node *deleteIndex(Node * head, int index){
    Node *temp = head;
    Node *prev = NULL;
    if(head == NULL){
        return NULL;
    }
    if(index == 0){
        head = temp->next;
        delete temp;
        return head;
    }else{
        for(int i = 0; ((temp->next != NULL)&&(i<index - 1)); i++){
            prev = temp;
            temp = temp->next;
        }
        prev ->next = temp->next;
        delete temp;
        return head;
    }
    return NULL;
}

Node* addNode(Node *head, int num){
    Node* tmp = new Node;
    if(head == NULL){
        tmp->data = num;
        tmp->next = NULL;
        head=tmp;
    }else{
        Node* newNode = new Node;
        newNode->data = num;
        newNode->next = NULL;
        tmp = head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }   
        tmp->next=newNode;
    }
    return head;
}

void Print(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    
    //Testcase #1: deleting a value from the list
    head = addNode(head, 22);
    head = addNode(head, 30);
    head = addNode(head, 1);
    head = addNode(head, 9);
    Print(head);
    
    cout<<endl;
    
    head = deleteIndex(head, 22);
    head = deleteIndex(head, 0);
    
    Print(head);
    cout<<endl;
}
 