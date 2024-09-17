#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

class Queue {
private:
  int *arr;
  int capacity;
  int front;
  int rear;
  int size;

public:
  // Конструктор класса Queue
  Queue(int capacity) {
    this->capacity = capacity;
    this->front = 0;
    this->rear = 0;
    this->size = 0;
    this->arr = new int[capacity];
  }

  // Деструктор класса Queue
  ~Queue() { delete[] arr; }

  // Операция enqueue() - добавляет элемент в очередь
  void enqueue(int value) {
    if (size < capacity) {
      arr[rear] = value;
      rear = (rear + 1) % capacity; // Сдвигаем rear по кругу
      size++;
    } else {
      std::cout << "Очередь заполнена. Cannot enqueue " << value << std::endl;
    }
  }

  // Операция dequeue() - удаляет элемент из очереди
  int dequeue() {
    if (isEmpty()) {
      std::cout << "Очередь пуста" << std::endl;
      return -1; // Возвращаем -1, если очередь пуста
    }
    int value = arr[front];
    arr[front] = 0;                 // Очищаем элемент
    front = (front + 1) % capacity; // Сдвигаем front по кругу
    size--;
    return value;
  }

  // Операция first() - возвращает первый элемент очереди
  int first() {
    if (isEmpty()) {
      std::cout << "Очередь пуста" << std::endl;
      return -1; // Возвращаем -1, если очередь пуста
    }
    return arr[front];
  }

  // Операция isEmpty() - проверяет, пуста ли очередь
  bool isEmpty() { return size == 0; }

  // Вспомогательная функция print() - выводит элементы очереди
  void print() {
    if (isEmpty()) {
      std::cout << "Очередь пуста" << std::endl;
      return;
    }

    int tempFront = front;
    std::cout << "Элементы очереди: ";
    for (int i = 0; i < size; i++) {
      std::cout << arr[tempFront] << " ";
      tempFront = (tempFront + 1) % capacity; // Сдвигаем по кругу
    }
    std::cout << std::endl;
  }
};
#endif // QUEUE_H
