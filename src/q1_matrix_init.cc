#include <iostream>

void PrintArray(int len1, int len2, int** arr) {
  std::cout << "Ваш массив: " << std::endl;
  for (int i = 0; i < len1; ++i) {
    for (int j = 0; j < len2; ++j) {
      arr[i][j] = i + j;
      std::cout << arr[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

int main() {
  std::cout << "Введите параметры вашего многомерного массива: " << std::endl;
  int n, m;
  std::cin >> n >> m;
  if (std::cin.good() == false || n <= 0 || m <= 0) {
    std::cout << "n/a" << std::endl;
    exit(0);
  }
  int** arr = new int*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[m];
  }
  PrintArray(n, m, arr);
  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
}