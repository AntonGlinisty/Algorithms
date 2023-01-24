#include <iostream>

std::pair<int64_t*, int> ArrInput() {
  int count = 0;
  std::cin >> count;
  int64_t* arr = new int64_t[count];
  for (int i = 0; i < count; ++i) {
    std::cin >> arr[i];
  }
  return std::pair<int64_t*, int>(arr, count);
}

void BinSearch(int64_t*& arr, int count) {
  int left = 0;
  int right = count - 1;
  int mid = 0;
  while (right - left > 1) {
    mid = (right + left) / 2;
    if (arr[left] > arr[mid]) {
      right = mid;
    } else if (arr[left] < arr[mid]) {
      if (arr[left] < arr[right]) {
        break;
      }
      left = mid;
    }
  }
  if (arr[left] < arr[right]) {
    std::cout << left << std::endl;
  } else {
    std::cout << right << std::endl;
  }
}

int main() {
  std::pair<int64_t*, int> pair = ArrInput();
  BinSearch(pair.first, pair.second);
  delete[] pair.first;
}