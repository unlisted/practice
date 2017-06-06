#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

void merge(int arr[], int left, int m, int right)
{

    // copy to temp arrays
    auto sz_left = m - left + 1;
    auto sz_right = right - m;
    int temp_left[sz_left], temp_right[sz_right];
    std::copy(&arr[left], &arr[left] + sz_left, temp_left);
    std::copy(&arr[m + 1], &arr[m + 1] + sz_right, temp_right);

    // TODO: modernize
    int i = 0;
    int j = 0;
    int k = left;
    while (i < sz_left && j < sz_right) {
        if (temp_left[i] <= temp_right[j]) {
            arr[k] = temp_left[i];
            ++i;
        } else {
            arr[k] = temp_right[j];
            ++j;
        }
        ++k;
    }

    while (i < sz_left) {
        arr[k] = temp_left[i];
        ++k;
        ++i;
    }

    while (j < sz_right) {
        arr[k] = temp_right[j];
        ++k;
        ++j;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {

        // find the middlefte
        auto m = left + (right - left) / 2;

        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);

        merge(arr, left, m, right);
    }
}

TEST(IsortTest, TestTest)
{
    int arr[] = { 5, 2, 4, 3, 1, 6, 7 };
    mergeSort(arr, 0, 6);
    ASSERT_THAT(arr, ::testing::ElementsAre(1, 2, 3, 4, 5, 6, 7));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
