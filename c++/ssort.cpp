#include <iostream>
#include <array>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

template<size_t SIZE>
void print(const std::array<int, SIZE> &arr) {
    for (auto &el : arr) 
        std::cout << el << std::endl;
}

template<size_t SIZE>
void ssort(std::array<int, SIZE>& arr) {
    auto sz = arr.size();
    // find the index of the smallest number
    for (auto i = 0; i < sz - 1; ++i) {
        int smallest = i;
        for (auto j = i + 1; j < sz; ++j) {
            if (arr[j] < arr[smallest])
                smallest = j;
        }
        if (smallest != i)
            std::swap(arr[smallest], arr[i]);
    }
}

TEST(SsortTest, UnsortedPositive) {
    std::array<int, 5> arr = {5, 8, 9, 7, 6};
    ssort(arr);
    ASSERT_THAT(arr, ::testing::ElementsAre(5,6,7,8,9));
}
TEST(SsortTest, SortedPositive) {
    std::array<int, 5> arr = {10,20,30,40,50};
    ssort(arr);
    ASSERT_THAT(arr, ::testing::ElementsAre(10,20,30,40,50));
}

TEST(SsortTest, UnsortedMixed) {
    std::array<int, 7> arr = {-1,-20,10,12,-40,-5,3};
    ssort(arr);
    ASSERT_THAT(arr, ::testing::ElementsAre(-40,-20,-5,-1,3,10,12));
}

TEST(SsortTest, OneElement) {
    std::array<int, 1> arr = {10};
    ssort(arr);
    ASSERT_THAT(arr, ::testing::ElementsAre(10));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}
