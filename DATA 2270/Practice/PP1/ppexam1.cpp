#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct Node{
    int data;
    Node *next;
};


//#1:
/*1. Implement the maximum function:
int maximum(Node *head);
This function should find and return the maximum value in w hichever linked list is passed in. If it is called on an empty list, this function should return 0 .
Examples:
If the list is 3 -> 9 -> 2 -> 4 -> NULL , calling maximum(head) should return 9 .
If the list is NULL , calling maximum(head) should return 0 .
1. Write a main function that creates a linked list of integers, then calls the function defined in part (1) to find the maximum value of that list. Call it on multiple lists
to show that it w orks on any possible list.
2. Test your function to make sure that it w orks in every case, no matter how many nodes are in the linked list or w here the maximum value is w ithin the list.*/


int maximum(Node *head){
    int maxNum = -1;
    while(head!=NULL){
        if((head->data)>maxNum){
            maxNum = head->data;
        }
        head = head->next;
    }
    return maxNum;
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

// Node* insert(Node* head, int data){
//     Node *temp = (Node*)malloc(sizeof(Node));
//     temp->data = data;
//     temp->next = NULL;
//     if(head == NULL){
//         head = temp;
//     }else{
//         Node* temp1 = head;
//         while(temp1->next != NULL){
//             temp1 = temp1->next;
//         }
//         temp1->next = temp;
//     }
//     return head;
// }

void Print(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
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
    
    int max = maximum(head);
    cout<<max<<endl;
    
    return 0;
}

