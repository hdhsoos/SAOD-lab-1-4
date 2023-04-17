#pragma once
#include <iostream>
#include <cstdlib> // для функций rand и srand
#include <ctime> // для функции time

struct Node {
	int data;
	Node* next; // указатель на след узел в стеке
};

struct Stack {
	Node* top; // указатель на вершину списка
};

void newStack(Stack& s); // функция для создания пустого стека
bool isEmpty(Stack& s); // функция для проверки на пустоту стека
void push(Stack& s, int data); // функция добавления элемента в вершину стека
void pop(Stack& s); // функция удаления элемента из вершины стека
void display(Stack& s); // функция для вывода текущего состояния стека
void move(Stack& s, Stack& extraStack); // функция перемещения в дополнительный стек
void take(Stack& extraStack, Stack& s); // функция перемещения из дополнительного стека