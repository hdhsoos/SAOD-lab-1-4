#include "Stack.h"
#include <iostream>
using namespace std;

// функция для создания пустого стека
void createStack(Stack& s) {
	s.top = nullptr;
}

// функция для проверки на пустоту стека
bool isEmpty(Stack& s) {
	return s.top == nullptr;
}

// функция добавления элемента в вершину стека
void push(Stack& s, int data) {
	Node* newNode = new Node; //выделение памяти под новый узел стека
	newNode->data = data; // запись данных в узел
	newNode->next = s.top; // установка связи между новым узлом и пред вершиной
	s.top = newNode; // обновление указателя вершины на новый узел
}

// функция удаления элемента из вершины стека
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

// функция для вывода текущего состояния стека
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

// функция перемещения в дополнительный стек
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

// функция перемещения из дополнительного стека
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