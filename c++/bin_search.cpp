#include <iostream>
#include <array>


template<size_t N>
int bin_search(std::array<int, N> arr, int left, int right, int value) {

    // split array in two
    // recursively divide array and search
    
    auto mid = left + (right-left) / 2;

    if (arr[mid] == value)
        return mid;

    if (value < arr[mid])
        return bin_search(arr, left, mid-1, value);

    return bin_search(arr, mid+1, right, value);

}

int main(int argc, char** argv) {

    std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};
    std::cout << bin_search(arr, 0, 9, 6) << std::endl;
    return 0;
}
