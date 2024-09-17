#ifndef LIST_H
#define LIST_H
#include <iostream>

class List {
private:
  int *arr;
  int capacity;
  int size;

public:
  // Конструктор класса List
  List(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];
  }

  // Деструктор класса List
  ~List() { delete[] arr; }

  // Операция add() - добавляет элемент в список
  void add(int index, int value) {
    if (index < 0 || index > size) {
      std::cout << "Недопустимый индекс" << std::endl;
      return;
    }

    if (size == capacity) {
      std::cout << "Список заполнен" << std::endl;
      return;
    }

    for (int i = size; i > index; i--) {
      arr[i] = arr[i - 1]; // Сдвигаем элементы вправо
    }

    arr[index] = value;
    size++;
  }

  // Операция remove() - удаляет элемент из списка
  void remove(int index) {
    if (index < 0 || index >= size) {
      std::cout << "Недопустимый индекс" << std::endl;
      return;
    }

    for (int i = index; i < size - 1; i++) {
      arr[i] = arr[i + 1]; // Сдвигаем элементы влево
    }

    size--;
  }

  // Операция get() - возвращает элемент из списка
  int get(int index) {
    if (index < 0 || index >= size) {
      std::cout << "Недопустимый индекс" << std::endl;
      return -1; // Возвращаем -1, если индекс недопустим
    }

    return arr[index];
  }

  // Операция isEmpty() - проверяет, пуст ли список
  bool isEmpty() { return size == 0; }

  // Вспомогательная функция print() - выводит элементы списка
  void print() {
    if (isEmpty()) {
      std::cout << "Список пуст" << std::endl;
      return;
    }

    std::cout << "Элементы списка: ";
    for (int i = 0; i < size; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};
#endif // LIST_H
