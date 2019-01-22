#include <iostream>
#include "HW4-Todo-QueueLinkedList.hpp"

TodoQueueLinkedList::TodoQueueLinkedList(){}
TodoQueueLinkedList::~TodoQueueLinkedList(){}

// Check if the list is empty
bool TodoQueueLinkedList::isEmpty(){
	if (queueFront == NULL)
		return true;
	else
		return false;
}
// adds node to end of queue
void TodoQueueLinkedList::enqueue(std::string todoItem){
	TodoItem *add = new TodoItem;
	add->todo = todoItem;
	add->next = NULL;
	if(isEmpty()){
		queueFront = add;
		queueEnd = add;
	}else if(queueEnd != NULL){
		queueEnd->next = add;
		queueEnd = add;
	}
}
// takes out the node from the front of the queue
void TodoQueueLinkedList::dequeue(){
	if(getQueueFront() != NULL){
		queueFront = queueFront->next;
	}else
		cout << "Queue empty, cannot dequeue an item." << endl;
}

// returns the value of the node in the front of the queue. doesn't remove.
TodoItem* TodoQueueLinkedList::peek(){
	if(isEmpty()){
		cout << "Queue empty, cannot peek." << endl;
		return NULL;
	}
	return queueFront;
}