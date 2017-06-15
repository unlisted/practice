#include <iostream>
#include  <memory>


template<size_t SIZE>
void csort(std::array<int, SIZE> &arr, int k) {
    int count[k];

    memset(count, 0, k);

    for (auto &el : arr) {
        count[el] += 1;
    }

    int sorted[k];

    for (int i = 0;i < k; k++)
    {
        auto ccount = count[i];
        for (j = i; j < ccount; j++,i++) {
            sorted[j] = 
        } 
    }
}



int main(int argc, char *argv[]) {

    return 0;
}
