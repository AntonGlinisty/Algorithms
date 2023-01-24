#include <iostream>

void BinSearch(int64_t*& arr, int left, int right, int64_t search) {
  int mid = 0;
  while (right - left > 1) {
    mid = (right + left) / 2;
    if (search < arr[mid]) {
      right = mid;
    } else if (arr[mid] < search) {
      left = mid;
    } else if (search == arr[mid]) {
      left = mid;
      break;
    }
  }
  if (search == arr[left] || search == arr[right]) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}

int64_t* ArrInput() {
  int count = 0;
  std::cin >> count;
  int64_t* arr = new int64_t[count];
  for (int i = 0; i < count; ++i) {
    std::cin >> arr[i];
  }
  return arr;
}

void SearchInput(int64_t*& arr) {
  int callscnt = 0;
  std::cin >> callscnt;
  int left = 0;
  int right = 0;
  int64_t search = 0;
  for (int i = 0; i < callscnt; ++i) {
    std::cin >> left >> right >> search;
    BinSearch(arr, left, right - 1, search);
  }
}

int main() {
  int64_t* arr = ArrInput();
  SearchInput(arr);
  delete[] arr;
}