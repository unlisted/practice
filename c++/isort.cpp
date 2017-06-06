#include <array>
#include <iostream>

template <size_t SIZE> void isort(std::array<int, SIZE> &arr) {
  // sorted contains single element
  auto sz = arr.size();
  for (auto i = 0; i < sz - 1; i++) {
    // compare with unsorted and insert

    // working backwards compare arr[j] with each membor of unsorted

    auto j = i + 1;
    while (arr[j] < arr[j - 1] && j >= 1) {
      // swap
      auto tmp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - i] = tmp;

      --j;
    }
  }
}

int main(int argc, char **argv) {
  std::array<int, 5> arr = {5, 8, 9, 7, 6};
  isort(arr);

  for (auto& el : arr) {
      std::cout << el << std::endl;
  }
}
