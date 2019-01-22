#include <iostream>
#include "HW4-Todo-QueueArray.hpp"

using namespace std;

TodoQueueArray::TodoQueueArray(){ //default constructor
    //queueFront = -1;
    //queueEnd = -1;
}

//Function that checks if array is empty
bool TodoQueueArray::isEmpty(){
    if (queueFront == queueEnd){
        return true;
    }
    return false;
}

//Function that checks if array is full
bool TodoQueueArray::isFull(){
    if(queueEnd-queueFront == 5){
        return true;
    }
    return false;
}

void TodoQueueArray::enqueue(string todoItem)
{
    if(isFull() == true){
        cout<< "Queue full, cannot add new todo item."<<endl;
    }
    else{
    queueEnd++;
    //This handles the circular array
    queue[queueEnd%5]= new TodoItem;
    queue[queueEnd%5]->todo=todoItem;
    }
}

void TodoQueueArray::dequeue(){
    if (isEmpty() == true){
        cout<< "Queue empty, cannot dequeue item" << endl;
    }else{
        queueFront++;
        delete queue[queueFront%5];
    }
}
//peeks the front item in the array
TodoItem* TodoQueueArray::peek()
{
    if (isEmpty() == true){
        cout << "Queue empty, cannot peek" << endl;
    }else{
            cout<<queue[(queueFront+1)%5]->todo<<endl;
    return queue[(queueFront+1)%5];
    }
}