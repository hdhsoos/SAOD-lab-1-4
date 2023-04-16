#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Stack s;
	createStack(s);
	Stack extraStack;
	createStack(extraStack);
	char choice;
	int data, n;
	int dop_choice;
	while (true) {
		cout << "1. Добавить элемент на вершину стека" << endl;
		cout << "2. Удалить элемент из вершины стека" << endl;
		cout << "3. Вывести стек на экран" << endl;
		cout << "4. Проверка заполненности стека" << endl;
		cout << "5. Добавить несколько элементов" << endl;
		cout << "6. Вывести вспомогательный стек на экран" << endl;
		cout << "7. Выход" << endl;
		cout << "Выберите действие: ";
		cin >> choice;
		cout << "\n";
		switch (choice) {
		case '1':
			cout << "1. Добавить новый элемент на вершину" << endl;
			cout << "2. Добавить элемент с вершины вспомогательного стека" << endl;
			cout << "Выберите действие: ";
			cin >> dop_choice;
			if (dop_choice == 1) {
				cout << "Введите значение нового элемента: ";
				cin >> data;
				push(s, data);
			}
			else {
				if (dop_choice == 2) {
					take(extraStack, s);
				}
				else {
				cout << "Ошибка ввода" << endl;
				}
			}
			cout << "\n";
			break;
		case '2':
			cout << "1. Удалить элемент с освобождением памяти" << endl;
			cout << "2. Удалить элемент и добавить его на вершину вспомогательного стека" << endl;
			cin >> dop_choice;
			if (dop_choice == 1) {
				pop(s);
			}
			else {
				move(s, extraStack);
			}
			cout << "\n";
			break;
		case '3':
			display(s);
			cout << "\n";
			break;
		case '4':
			if (isEmpty(s)) { cout << "Стек пуст" << endl; }
			else { cout << "Стек не пуст" << endl; }
			cout << "\n";
			break;
		case '5':
			cout << "Введите, сколько элементов добавить в стек: ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				int data = rand() & 100;
				push(s, data);
			}
			cout << "\n";
			break;
		case '6':
			display(extraStack);
			cout << "\n";
			break;
		case '7':
			return 0;
		default:
			cout << "Ошибка ввода" << endl;
			cout << "\n";
		}
	}
}