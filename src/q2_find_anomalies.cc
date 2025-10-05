#include <iostream>

void InputArray(int len1, int len2, int** arr) {
  std::cout << " Введите элементы матрицы: " << std::endl;
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      std::cin >> arr[i][j];
      if (std::cin.good() == false) {
        std::cout << "n/a" << std::endl;
        exit(0);
      }
    }
  }
}

void Check(int len1, int len2, int** arr, int k) {
  bool find = false;
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      if (arr[i][j] > k) {
        std::cout << '(' << i << ',' << j << ')' << ':' << ' ' << arr[i][j] << std::endl;
        find = true;
      }
    }
  }
  if (find == false) {
    std::cout << "NAD" << std::endl;
  }
}

int main() {
  int k;
  std::cout << "Введите число аномалию: " << std::endl;
  std::cin >> k;
  if (std::cin.good() == false || k <= 0 || std::cin.peek() != '\n') {
    std::cout << "n/a" << std::endl;
    exit(0);
  }
  std::cout << "Введите параметры матрицы: " << std::endl;
  int n, m;
  std::cin >> n >> m;
  if (std::cin.good() == false || n <= 0 || m <= 0 || std::cin.peek() != '\n') {
    std::cout << "n/a" << std::endl;
    exit(0);
  }
  int** arr = new int*[n];
  for (int i = 0; i < m; i++) {
    arr[i] = new int[m];
  }
  InputArray(n, m, arr);
  Check(n, m, arr, k);
  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}