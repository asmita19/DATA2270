#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


//#3: reverse function
/*Write a program that creates a linked list of integers, and a function that reverses that list.
Requirements:
1. Implement the reverse function:
Node *reverse(Node *head);
This function should reverse the order of the values in the linked list w hich is passed as an argument, and return a pointer to the new head of the list.
Example:
If the list is 2 -> 7 -> 3 -> 3 -> NULL , calling reverse(head) should change the list to be 3 -> 3 -> 7 -> 2 -> NULL and return a pointer to the new head.
1. Write a main function that creates a linked list of integers, then calls the function defined in part (1) to reverse that list. It should call the function multiple times
on different lists, to show that it can reverse a list of any length.
2. Test your function to make sure that it w orks in every case, no matter w hat list is passed in*/

struct Node{
    int data;
    Node *next;
};

Node* reverse(Node *head){
    Node *prev, *current, *next; 
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;//current-> is the link fiels in the node
        prev = current;
        current = next;//this next is just a local variable
    }
    head = prev;
    return head;
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

void Print(Node* head){
    while(head != NULL){
        cout << head-> data <<endl; 
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* head = NULL;
    head = addNode(head, 22);
    head = addNode(head, 30);
    head = addNode(head, 1);
    head = addNode(head, 9);
    
    Print(head);
    cout<<endl;
    
    head = reverse(head);
    Print(head);
    cout<<endl;

}