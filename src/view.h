#ifndef VIEW_H
#define VIEW_H

#include "list.h"
#include "queue.h"
#include "set.h"
#include "stack.h"
#include <iostream>

class View {
public:
  void showMenu() {
    std::cout << "Выберите тип структуры данных:" << std::endl;
    std::cout << "1. Стек" << std::endl;
    std::cout << "2. Очередь" << std::endl;
    std::cout << "3. Список" << std::endl;
    std::cout << "4. Множество" << std::endl;
    std::cout << "5. Выход" << std::endl;
  }

  void inputData(Stack &stack) {
    int choice;
    while (true) {
      std::cout << "Выберите операцию для стека:" << std::endl;
      std::cout << "1. Push" << std::endl;
      std::cout << "2. Pop" << std::endl;
      std::cout << "3. Last" << std::endl;
      std::cout << "4. isEmpty" << std::endl;
      std::cout << "5. Print" << std::endl;
      std::cout << "6. Назад" << std::endl;
      std::cin >> choice;

      switch (choice) {
      case 1: {
        int value;
        std::cout << "Введите значение для push:" << std::endl;
        std::cin >> value;
        stack.push(value);
        break;
      }
      case 2: {
        stack.pop();
        break;
      }
      case 3: {
        std::cout << "Последний элемент: " << stack.last() << std::endl;
        break;
      }
      case 4: {
        std::cout << "Пуст ли стек? " << (stack.isEmpty() ? "Да" : "Нет")
                  << std::endl;
        break;
      }
      case 5: {
        stack.print();
        break;
      }
      case 6: {
        return;
      }
      default: {
        std::cout << "Недопустимый выбор" << std::endl;
      }
      }
    }
  }

  void inputData(Queue &queue) {
    int choice;
    while (true) {
      std::cout << "Выберите операцию для очереди:" << std::endl;
      std::cout << "1. Enqueue" << std::endl;
      std::cout << "2. Dequeue" << std::endl;
      std::cout << "3. First" << std::endl;
      std::cout << "4. isEmpty" << std::endl;
      std::cout << "5. Print" << std::endl;
      std::cout << "6. Назад" << std::endl;
      std::cin >> choice;

      switch (choice) {
      case 1: {
        int value;
        std::cout << "Введите значение для enqueue:" << std::endl;
        std::cin >> value;
        queue.enqueue(value);
        break;
      }
      case 2: {
        queue.dequeue();
        break;
      }
      case 3: {
        std::cout << "Первый элемент: " << queue.first() << std::endl;
        break;
      }
      case 4: {
        std::cout << "Пуста ли очередь? " << (queue.isEmpty() ? "Да" : "Нет")
                  << std::endl;
        break;
      }
      case 5: {
        queue.print();
        break;
      }
      case 6: {
        return;
      }
      default: {
        std::cout << "Недопустимый выбор" << std::endl;
      }
      }
    }
  }

  void inputData(List &list) {
    int choice;
    while (true) {
      std::cout << "Выберите операцию для списка:" << std::endl;
      std::cout << "1. Add" << std::endl;
      std::cout << "2. Remove" << std::endl;
      std::cout << "3. Get" << std::endl;
      std::cout << "4. isEmpty" << std::endl;
      std::cout << "5. Print" << std::endl;
      std::cout << "6. Назад" << std::endl;
      std::cin >> choice;

      switch (choice) {
      case 1: {
        int value, index;
        std::cout << "Введите значение и индекс для add:" << std::endl;
        std::cin >> value >> index;
        list.add(index, value);
        break;
      }
      case 2: {
        int index;
        std::cout << "Введите индекс для remove:" << std::endl;
        std::cin >> index;
        list.remove(index);
        break;
      }
      case 3: {
        int index;
        std::cout << "Введите индекс для get:" << std::endl;
        std::cin >> index;
        std::cout << "Элемент по индексу: " << list.get(index) << std::endl;
        break;
      }
      case 4: {
        std::cout << "Пуст ли список? " << (list.isEmpty() ? "Да" : "Нет")
                  << std::endl;
        break;
      }
      case 5: {
        list.print();
        break;
      }
      case 6: {
        return;
      }
      default: {
        std::cout << "Недопустимый выбор" << std::endl;
      }
      }
    }
  }

  void inputData(Set &set) {
    int choice;
    while (true) {
      std::cout << "Выберите операцию для множества:" << std::endl;
      std::cout << "1. Add" << std::endl;
      std::cout << "2. Remove" << std::endl;
      std::cout << "3. Contains" << std::endl;
      std::cout << "4. isEmpty" << std::endl;
      std::cout << "5. Print" << std::endl;
      std::cout << "6. Назад" << std::endl;
      std::cin >> choice;

      switch (choice) {
      case 1: {
        int value;
        std::cout << "Введите значение для add:" << std::endl;
        std::cin >> value;
        set.add(value);
        break;
      }
      case 2: {
        int value;
        std::cout << "Введите значение для remove:" << std::endl;
        std::cin >> value;
        set.remove(value);
        break;
      }
      case 3: {
        int value;
        std::cout << "Введите значение для contains:" << std::endl;
        std::cin >> value;
        std::cout << "Содержит ли множество значение? "
                  << (set.contains(value) ? "Да" : "Нет") << std::endl;
        break;
      }
      case 4: {
        std::cout << "Пусто ли множество? " << (set.isEmpty() ? "Да" : "Нет")
                  << std::endl;
        break;
      }
      case 5: {
        set.print();
        break;
      }
      case 6: {
        return;
      }
      default: {
        std::cout << "Недопустимый выбор" << std::endl;
      }
      }
    }
  }
};

#endif // VIEW_H