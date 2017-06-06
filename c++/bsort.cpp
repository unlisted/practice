#include <array>
#include <iostream>

template <size_t SIZE> void bsort(std::array<int, SIZE>& arr)
{
    auto sz = arr.size();
    auto flag = true;
    while (flag) {
        flag = false;
        for (auto iter = std::begin(arr); iter != std::end(arr) - 1; iter++) {
            if (*iter > *(iter + 1)) {
                std::iter_swap(iter, iter + 1);
                flag = true;
            }
        }
    }
}

int main(int argc, char** argv)
{
    std::array<int, 10> arr = { 4, 3, 2, 5, 6, 3, 10, 20, 13, 0 };
    bsort(arr);
    for (auto& el : arr) {
        std::cout << el << std::endl;
    }
}
