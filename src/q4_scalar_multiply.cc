#include <iostream>

int CheckInput () {
  int value;
  std::cin >> value;
  if (value <= 0 || std::cin.good() == false) {
    std::cout << "n/a" << std::endl;
    exit(0);
  }
  return value;
}

void InputArray (int rows, int cols, int **arr) {
  std::cout << "Заполните элементами вашу матрицу: " << std::endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cin >> arr[i][j];
      if (std::cin.good() == false) {
        std::cout << "n/a" << std::endl;
        exit(0);
      }
    }
  }
}

void Multiplication (int k, int **arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = arr[i][j] * k;
    }
  }
}

void PrintArray(int rows, int cols, int **arr) {
  std::cout << "Процесс завершен.Матрица готова: " << std::endl;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << arr[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}
// Функция для освобождения памяти двумерного массива
void FreeMatrix(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
  std::cout << "Введите параметры матрицы: " << std::endl;
  int rows;
  rows = CheckInput();
  int cols;
  cols = CheckInput();
  int k;
  std::cout << "Введите скаляр: " << std::endl;
  std::cin >> k;
  if (std::cin.good() == false) {
    std::cout << "n/a" << std::endl;
    exit(0);
  }
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
      arr[i] = new int[cols];
    }
  InputArray(rows,cols,arr);
  Multiplication(k,arr,rows,cols);
  PrintArray(rows,cols,arr);
  FreeMatrix(arr,rows);
}