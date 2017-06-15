#include <iostream>
#include <array>
#include <limits>

using namespace std;

template<size_t SIZE>
int MaxTriplet(const array<int, SIZE>& arr) {
   array<int, 3> maxs = {numeric_limits<int>::min(), numeric_limits<int>::min(), numeric_limits<int>::min()};
   array<int, 2> mins = {numeric_limits<int>::max(), numeric_limits<int>::max(), numeric_limits<int>::max()};

   for (auto &el : arr) {
       auto tmp = maxs[2];

       if (el > maxs[2]) {
           maxs[2] = el;

           if (tmp > maxs[2]) {
           }
       }

    }
}

int main(int argc, char *argv[]) {
    return 0;
}
