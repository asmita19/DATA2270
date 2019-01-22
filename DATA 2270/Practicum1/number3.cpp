#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
    
    Arr(){}
    Arr(int d){
        data = d;
    }
};

int *storeInArray(Node *head){
    Node *temp = head;
    int index[];
    int tem = 0;
    for(int i = 0; i < tem; i++){
        temp = temp->index[i];
    }
    return temp;
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
    int i;
    Arr myarray[];
    
    myarray[i].data = 
    
    Node *head = NULL;
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 8);
    head = addNode(head, 90);
    head = addNode(head, 17);
    Print(head);
    
    head = storeInArray(head);
    Print(head);
    cout<<endl;
    return 0;
}