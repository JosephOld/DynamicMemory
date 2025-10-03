#include <iostream>

int CheckInput1 () {
  int value;
  std::cin >> value;
  if (value <= 0 || std::cin.good() == false) {
    std::cout << "n/a" << std::endl;
    exit(0);
  }
  return value;
}

void CompareParameters (int rows, int cols, int rows1,int cols1) {
  if (rows != rows1 || cols != cols1) {
    std::cout << "MSM" << std::endl;
    exit(0);
  }
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

void Sum (int rows, int cols, int **arr, int **arr2, int **arrSum) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; ++j) {
      arrSum[i][j] = arr[i][j] + arr2[i][j];
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
  std::cout << "Введите параметры первой матрицы: " << std::endl;
  int rows;
  rows = CheckInput1();
  int cols;
  cols = CheckInput1();
  std::cout << "Введите параметры второй матрицы: " << std::endl;
  int rows1;
  rows1 = CheckInput1();
  int cols1;
  cols1 = CheckInput1();
  CompareParameters(rows,cols,rows1,cols1);
  int** arr1 = new int*[rows];
  for (int i = 0; i < rows; i++) {
    arr1[i] = new int[cols];
  }
  int** arr2 = new int*[rows1];
  for (int i = 0; i < rows1; i++) {
    arr2[i] = new int[cols1];
  }
  int** arrSum = new int*[rows];
  for (int i = 0; i < rows; i++) {
    arrSum[i] = new int[cols];
  }
  InputArray(rows, cols, arr1);
  InputArray(rows1,cols1,arr2);
  Sum(rows,cols,arr1,arr2, arrSum);
  PrintArray(rows, cols, arrSum);
  FreeMatrix(arr1, rows);
  FreeMatrix(arr2, rows);
  FreeMatrix(arrSum, rows);
}
