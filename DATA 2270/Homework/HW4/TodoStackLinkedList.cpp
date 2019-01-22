#include <iostream>
#include "HW4-Todo-StackLinkedList.hpp"

TodoStackLinkedList::TodoStackLinkedList(){
	stackHead = NULL;
}
TodoStackLinkedList::~TodoStackLinkedList(){
	while(!isEmpty()){
	    pop();
	}
}
bool TodoStackLinkedList::isEmpty(){
	if(!stackHead){
	    return true;
	}else{
	    return false;
	}
}
void TodoStackLinkedList::push(std::string todoItem){
	if(isEmpty()){
		TodoItem* newTodoItem = new TodoItem;
		newTodoItem->todo = todoItem;
		newTodoItem->next = NULL;
		stackHead = newTodoItem;
		// cout << "Stacked: " << todoItem << endl;
	}else{
		TodoItem* newTodoItem = new TodoItem;
		newTodoItem->todo = todoItem;
		newTodoItem->next = stackHead;
		stackHead = newTodoItem;
		// cout << "Stacked: " << todoItem << endl;
	}
}
void TodoStackLinkedList::pop(){
	if(isEmpty()){
	    cout << "Stack empty, cannot pop an item." << endl;
	}else{
		TodoItem* deleteTodoItem = stackHead;
		// cout << "Removed: " << stackHead->todo << endl;
		stackHead = stackHead->next;
		delete deleteTodoItem;
		
	}
}
TodoItem* TodoStackLinkedList::peek(){
	if(isEmpty()){
	    cout << "Stack empty, cannot peek." << endl;
	}
	return stackHead;
}
