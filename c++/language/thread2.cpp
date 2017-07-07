#include <array>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool flag;


void func() {
    unique_lock<mutex> lk(mtx);
    cout << "waiting.." << endl;
    cv.wait(lk, []{return flag;});
    cout << "unlocked." << endl;
}

int main(int argc, char *argv[]) {
    
    {
        lock_guard<mutex> lk(mtx);
        flag = false;
    }
    thread t1(func);

    this_thread::sleep_for(2s);

    cout << "signaling." << endl;
    cv.notify_all();

    this_thread::sleep_for(2s);

    {
        cout << "set flag" << endl;
        lock_guard<mutex> lk(mtx);
        flag = true;
    }

    cout << "signaling" << endl;
    cv.notify_all();

    
    t1.join();
    return 0;
}
