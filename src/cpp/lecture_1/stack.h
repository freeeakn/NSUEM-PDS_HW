#ifndef STACK_H
#define STACK_H
#include <iostream>

class Stack {
private:
  int *arr;
  int capacity;
  int size;

public:
  // Конструктор класса Stack
  Stack(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];
  }

  // Деструктор класса Stack
  ~Stack() { delete[] arr; }

  // Операция push() - добавляет элемент в стек
  void push(int value) {
    if (size < capacity) {
      arr[size] = value;
      size++;
    } else {
      std::cout << "Стек заполнен. Cannot push " << value << std::endl;
    }
  }

  // Операция pop() - удаляет элемент из стека
  int pop() {
    if (isEmpty()) {
      std::cout << "Стек пуст" << std::endl;
      return -1; // Возвращаем -1, если стек пуст
    }
    size--;
    return arr[size];
  }

  // Операция last() - возвращает последний элемент стека
  int last() {
    if (isEmpty()) {
      std::cout << "Стек пуст" << std::endl;
      return -1; // Возвращаем -1, если стек пуст
    }
    return arr[size - 1];
  }

  // Операция isEmpty() - проверяет, пуст ли стек
  bool isEmpty() { return size == 0; }

  // Вспомогательная функция print() - выводит элементы стека
  void print() {
    std::cout << "Элементы стека: ";
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};
#endif // STACK_H
