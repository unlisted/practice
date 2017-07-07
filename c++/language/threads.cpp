#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int flag = true;

void printOdds(int low, int high) {

    int current = low;
    while(current <= high) {
        unique_lock<mutex> lk(mtx);

        if(flag) {
            if (current % 2 == 1) {
                cv.wait(lk);
                cout << current << endl;;
            }

            current++;
            flag = false;
        }
        cv.notify_one();

    }

}

void printEvens(int low, int high) {

    auto current = low;
    while(current != high ) {
        unique_lock<mutex> lk(mtx);
        if (!flag) {

            if (current % 2 == 0) {
                cv.wait(lk);
                cout << current << endl;;
            }

            current++;
            flag = true;
        }
        cv.notify_one();

    }

}

int main() {
    thread t1(printOdds, 1, 10);
    thread t2(printEvens, 1, 10);

    cv.notify_one();

    t1.join();
    t2.join();
    return 0;
}
