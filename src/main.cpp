#include "view.h"

int main() {
  View view;
  int choice;
  int size;

  while (true) {
    view.showMenu();
    std::cin >> choice;

    if (choice >= 1 && choice <= 4) {
      std::cout << "Введите размер структуры данных: ";
      std::cin >> size;

      switch (choice) {
      case 1: {
        Stack stack(size);
        view.inputData(stack);
        break;
      }
      case 2: {
        Queue queue(size);
        view.inputData(queue);
        break;
      }
      case 3: {
        List list(size);
        view.inputData(list);
        break;
      }
      case 4: {
        Set set(size);
        view.inputData(set);
        break;
      }
      }
    } else if (choice == 5) {
      return 0;
    } else {
      std::cout << "Недопустимый выбор" << std::endl;
    }
  }

  return 0;
}