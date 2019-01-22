#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};

Node *swapHeadAndTail(Node *head){
    Node *temp,*prev;
    temp = head;
    for(prev = head; prev != NULL; prev = prev -> next){
        head = head->next;
        prev->next = temp;
        temp->next = NULL;
    }
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

void Print(Node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node *head = NULL;
    head = addNode(head, 3);
    head = addNode(head, 9);
    head = addNode(head, 2);
    head = addNode(head, 4);
    head = addNode(head, 31);
    Print(head);
    cout<<endl;
    head = swapHeadAndTail(head);
    Print(head);
    cout<<endl;
    return 0;
}