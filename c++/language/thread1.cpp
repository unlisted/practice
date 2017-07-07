#include <array>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

struct Counter {
    void Reset() { _count = 0; }
    Counter &operator++() { 
        ++_count; 
        return *this; 
    }
    void Print() { cout << _count << endl; }

    int _count = 0;
};

void func(Counter &counter, int n) {
    for (int i = 0; i < n; ++i) {
        lock_guard<mutex> guard(mtx);
        ++counter;
    }
}


int main(int argc, char *argv[]) {

    Counter counter;
    counter.Print();

    array<thread, 5> threads {
        thread {func, ref(counter), 500},
        thread {func, ref(counter), 500},
        thread {func, ref(counter), 500},
        thread {func, ref(counter), 500},
        thread {func, ref(counter), 500}
    };

    for (auto &thr : threads) {
        thr.join();
    }
    counter.Print();
    return 0;
}
