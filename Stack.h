#pragma once
#include <iostream>
#include <cstdlib> // для функций rand и srand
#include <ctime> // для функции time

// определяю структуру узла стека
struct Node {
	int data; // данные узла
	Node* next; // указатель на след узел в стеке
};

// определяю структуру стека
struct Stack {
	Node* top; // указатель на вершину списка
};

void createStack(Stack& s); // функция для создания пустого стека
bool isEmpty(Stack& s); // функция для проверки на пустоту стека
void push(Stack& s, int data); // функция добавления элемента в вершину стека
void pop(Stack& s); // функция удаления элемента из вершины стека
void display(Stack& s); // функция для вывода текущего состояния стека
void move(Stack& s, Stack& extraStack); // функция перемещения в дополнительный стек
void take(Stack& extraStack, Stack& s); // функция перемещения из дополнительного стека