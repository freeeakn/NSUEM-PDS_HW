#ifndef SET_H
#define SET_H
#include <iostream>

class Set {
private:
  int *arr;
  bool *flags;
  int capacity;
  int size;

public:
  // Конструктор класса Set
  Set(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];
    this->flags = new bool[capacity];
    for (int i = 0; i < capacity; i++) {
      flags[i] = false;
    }
  }

  // Деструктор класса Set
  ~Set() {
    delete[] arr;
    delete[] flags;
  }

  // Операция add() - добавляет элемент в множество
  void add(int value) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == value) {
        std::cout << "Элемент уже существует в множестве" << std::endl;
        return;
      }
    }

    if (size < capacity) {
      arr[size] = value;
      flags[size] = true;
      size++;
    } else {
      std::cout << "Множество заполнено" << std::endl;
    }
  }

  // Операция remove() - удаляет элемент из множества
  void remove(int value) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == value) {
        flags[i] = false;
        size--;
        for (int j = i; j < size; j++) {
          arr[j] = arr[j + 1];
          flags[j] = flags[j + 1];
        }
        return;
      }
    }

    std::cout << "Элемент не найден в множестве" << std::endl;
  }

  // Операция contains() - проверяет, содержит ли множество элемент
  bool contains(int value) {
    for (int i = 0; i < size; i++) {
      if (arr[i] == value && flags[i]) {
        return true;
      }
    }

    return false;
  }

  // Операция isEmpty() - проверяет, пусто ли множество
  bool isEmpty() { return size == 0; }

  // Вспомогательная функция print() - выводит элементы множества
  void print() {
    if (isEmpty()) {
      std::cout << "Множество пусто" << std::endl;
      return;
    }

    std::cout << "Элементы множества: ";
    for (int i = 0; i < size; i++) {
      if (flags[i]) {
        std::cout << arr[i] << " ";
      }
    }
    std::cout << std::endl;
  }
};
#endif // SET_H
