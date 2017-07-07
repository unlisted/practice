#include <iostream>
#include <array>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

template <size_t SIZE> void print(const std::array<int, SIZE>& arr)
{
    for (auto& el : arr)
        std::cout << el << std::endl;
}

// places all values lower than partion the left of partition
// and all values higher than partition to the right of partition
// selects high value as partition
template <size_t SIZE> int partition(std::array<int, SIZE>& arr, int low, int high)
{
    auto pi = high;
    --high;

    // TODO: this could be improved
    while (true) {
        while (arr[low] < arr[pi] && low != high)
            ++low;
        while (arr[high] > arr[pi] && low != high)
            --high;

        if (low == high)
            break;

        std::swap(arr[low], arr[high]);
    }

    if (arr[low] < arr[pi])
        ++low;

    if (low != pi)
        std::swap(arr[low], arr[pi]);

    return low;
}

// sort by partitioning and recursively calling qsort
template <size_t SIZE> void qsort(std::array<int, SIZE>& arr, int low, int high)
{
    if (low < high) {
        // get the new partition index
        auto pi = partition(arr, low, high);

        qsort(arr, low, pi - 1);
        qsort(arr, pi + 1, high);
    }
}

TEST(QqsortTest, UnsortedSort_5)
{
    std::array<int, 5> arr = { 5, 8, 9, 4, 6 };
    qsort(arr, 0, 4);
    ASSERT_THAT(arr, ::testing::ElementsAre(4, 5, 6, 8, 9));
}

TEST(QqsortTest, UnsortedSort_7)
{
    std::array<int, 7> arr = { 10, 80, 30, 90, 40, 50, 70 };
    qsort(arr, 0, 6);
    ASSERT_THAT(arr, ::testing::ElementsAre(10, 30, 40, 50, 70, 80, 90));
}

TEST(QsortTest, LastSwapGreaterThanPivot)
{
    std::array<int, 5> arr = { 5, 8, 9, 4, 6 };
    partition(arr, 0, 4);
    ASSERT_THAT(arr, ::testing::ElementsAre(5, 4, 6, 8, 9));
}

TEST(QsortTest, LastSwapLessThanPivot)
{
    std::array<int, 5> arr = { 5, 8, 3, 4, 6 };
    partition(arr, 0, 4);
    ASSERT_THAT(arr, ::testing::ElementsAre(5, 4, 3, 6, 8));
}

TEST(QsortTest, AlreadyPartitioned)
{
    std::array<int, 5> arr = { 5, 8, 10, 14, 26 };
    partition(arr, 0, 4);
    ASSERT_THAT(arr, ::testing::ElementsAre(5, 8, 10, 14, 26));
}

TEST(QsortTest, AllGreaterThanPivot)
{
    std::array<int, 5> arr = { 5, 8, 10, 14, 0 };
    partition(arr, 0, 4);
    ASSERT_THAT(arr, ::testing::ElementsAre(0, 8, 10, 14, 5));
}

TEST(QsortTest, AllLessThanPivot)
{
    std::array<int, 5> arr = { 5, 8, 10, 14, 20 };
    partition(arr, 0, 4);
    ASSERT_THAT(arr, ::testing::ElementsAre(5, 8, 10, 14, 20));
}

TEST(QsortTest, PartialPivot)
{
    std::array<int, 10> arr = { 10, 5, 20, 40, 15, 100, 200, 300, 400, 500 };
    partition(arr, 0, 4);
    ASSERT_THAT(arr, ::testing::ElementsAre(10, 5, 15, 40, 20, 100, 200, 300, 400, 500));
}
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
