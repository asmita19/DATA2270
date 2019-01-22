#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <node.h>

using namespace std;

 void passbyvalue(int a){
     a++;
 }
 void PassbyPointer(int *ptr){
     cout<<"address stored in ptr:"<<ptr<<endl;
 }
 
 struct node{
     int key;
     node = *next;
     node(int k, node *n){
         key = k;
         next = n;
     }
 };
 int main(){
     node *x = new node(5, NULL);//using the constuctor to create a node
     cout<<->key<<endl; // (Xx).key
     cout<<(*x)<<endl;//(*x).key
     //Both the satement abouve perform thr same task
     
     node *x2 = new node(6, NULL);//creating another node
     x ->next = x2;//setting the next pointer of x to x2
     //cout<<x2<<endl;//should print the address of x2
     //cout<<x->next<<endl;//should also print the address of x2
     
     x2 ->key = 10;//assiging a value to the key of x2
     
     //Traversal
     
     node *p = x;
     while(p != NULL){
         //cout<<p->key<<endl;
         p = p->next;
     }
 }