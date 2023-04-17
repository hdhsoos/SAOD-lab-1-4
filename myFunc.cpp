#include "Stack.h"
#include <iostream>
using namespace std;

void newStack(Stack& s) {
	s.top = nullptr;
}

bool isEmpty(Stack& s) {
	return s.top == nullptr;
}

void push(Stack& s, int data) {
	Node* newNode = new Node; //выделение памяти под новый узел стека
	newNode->data = data; // запись данных в узел
	newNode->next = s.top; // установка связи между новым узлом и пред вершиной
	s.top = newNode; // обновление указателя вершины на новый узел
}

void pop(Stack& s) {
	if (isEmpty(s)) {
		cout << "Стек пуст" << endl;

	}
	else {
		Node* temp = s.top; // создание временного указателя 
		s.top = s.top->next; // обновление указателя вершины
		delete temp; // освобождение памяти
	}
}

void display(Stack& s) {
	if (isEmpty(s)) {
		cout << "Стек пуст" << endl;
	}
	else {
		Node* currNode = s.top;
		while (currNode != nullptr) {
			cout << currNode->data << " ";
			currNode = currNode->next;
		}
		cout << "\n";
	}
}

void move(Stack& s, Stack& extraStack) {
	Node* cur;
	if (not isEmpty(s)) {
		int data = s.top->data;
		cur = s.top;
		s.top = s.top->next;
		cur->next = extraStack.top;
		extraStack.top = cur;
		cout << "Элемент " << cur->data << " перемещен в вспомогательный стек" << endl;
	}
	else {
		cout << "Основной стек пуст" << endl;
	}

}

void take(Stack& extraStack, Stack& s) {
	Node* cur;
	if (not isEmpty(extraStack)) {
		cur = extraStack.top;
		extraStack.top = extraStack.top->next;
		cur->next = s.top;
		s.top = cur;
		cout << "Элемент " << cur->data << " перемещен в основной стек" << endl;
	}
	else {
		cout << "Вспомогательный стек пуст" << endl;
	}
}