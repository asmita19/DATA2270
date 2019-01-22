#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(/*int argc, char *argv[]*/){
    cout<<"hello world"<<endl;
    cout<<argc<<endl;
    cout<<argv[0]<<endl;
    
    for(int i = 1; i < argc; i++){
          cout<<argv[1]<<endl;
    }
    
    int a = 5;//regular variable
    cout<<a<<endl;
    int *b = &a; //b is a pointer. It stores the address of a
    cout<<b<<", "<<b<<", "<<endl;
    a = 10;
    cout<<b<<", "<<b<<", "<<b<<", "<<endl;
    int *c = &a;sca
    
    int arrayA[5];
    cout<<arrayA<<endl;
    
}