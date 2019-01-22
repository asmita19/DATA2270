 #include <iostream>
 
 using namespace std;
 
 struct node{
     int key;
     node *next;
     node(int k, node *n){
         key = k; 
         node = n;
     }
 };
 
 node *