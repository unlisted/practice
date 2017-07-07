#include <array>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

template <size_t SIZE> void print(const std::array<int, SIZE>& arr)
{
    for (auto& el : arr) {
        std::cout << el << std::endl;
    }
}

template <size_t SIZE> void isort(std::array<int, SIZE>& arr)
{
    // sorted contains single element
    auto sz = arr.size();
    for (auto i = 0; i < sz - 1; i++) {
        auto j = i + 1;
        while (arr[j] < arr[j - 1] && j >= 1) {
            std::swap(arr[j - 1], arr[j]);

            --j;
        }
    }
}

TEST(IsortTest, UnsortedPositive)
{
    std::array<int, 5> arr = { 10, 8, 9, 7, 6 };
    isort(arr);
    ASSERT_THAT(arr, ::testing::ElementsAre( 6, 7, 8, 9, 10));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
