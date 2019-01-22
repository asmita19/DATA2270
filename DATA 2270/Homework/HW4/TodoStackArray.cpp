#include <iostream>
#include "HW4-Todo-StackArray.hpp"
using namespace std;

TodoStackArray::TodoStackArray(){
  stackTop = -1;
}

bool TodoStackArray::isEmpty(){
  if (stackTop < 0){
    return true;
  }else{
    return false;
  }
}

bool TodoStackArray::isFull(){
  if (stackTop == MAX_STACK_SIZE-1){
    return true;
  }else{
    return false;
  }
}


void TodoStackArray::push(string todoItem){
  if(isFull()){
    cout << "Stack full, cannot add new todo item." <<endl;
    return;
  }else{
    stackTop+=1; 
    stack[stackTop].todo = todoItem;
    // stackTop+=1;
  }

}

void TodoStackArray::pop(){
  if (!isEmpty()){
    //TodoItem temp; 
    //temp = stack[stackTop];
    stackTop--;
  }else{
    cout <<"Stack empty, cannot pop an item." <<endl;
  }
}

TodoItem TodoStackArray::peek(){
  if (!isEmpty()){
    return stack[stackTop];
  }else{
    cout <<"Empty" <<endl;
  }
  TodoItem t;
  return t;
}

