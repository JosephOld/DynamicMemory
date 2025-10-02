#include <iostream>

int main() {
  std::cout << "Введите количество строк и столбцов: " << std::endl;
  int n1, n2;
  std::cin >> n1 >> n2;
  
  int arr[n1][n2];
  std::cout << "Введите элементы: " << std::endl;
  for (int i = 0; i < n1; i++) {
  
    for (int j = 0; j < n2; ++j) {
      std::cin >> arr[i][j];
    }
  }
  std::cout << "Матрица по вашим параметрам готова:" << std::endl;
  for (int i = 0; i < n1; i++) {
  
    for (int j = 0; j < n2; ++j) {
      std::cout << arr[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}