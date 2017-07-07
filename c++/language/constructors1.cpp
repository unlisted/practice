#include <iostream>
#include <array>
#include <initializer_list>
#include <string>

using namespace std;

class A {
public:
    explicit A(int val) : _val(val) { cout << "A(" << val << ")" << endl; }
    //A() : _val(900) { cout << "A(" << _val << ")" << endl; }
    A() = default;
    A(const A &a) : _val(a._val) { cout << "A(const A &a) " << _val << endl; } 
    A(initializer_list<int> vals) { for (auto &val : vals) { cout << val << endl; } }

    ~A() { cout << "~A()" << endl; }

    void Print() { cout << _foo << ": " << _val << endl; }
private:
    int _val = 0;
    string _foo = "bar";
};

void func(A a) {
    a.Print();
}

int main(int argc, char *argv[]) {
    /*
    A a1 {123};

    auto a2 = new A{456};

    array<A, 3> arr1 {A(8), A(9), A(10)};
    array<A, 1> arr2;

    copy(begin(arr1), begin(arr1) + 1, begin(arr2));

    A a3(*a2);

    A a4 {1, 2, 3, 4};
    //a4.Print();
*/
    A a5(65);
    a5.Print();
//    func(70);
 //   delete a2;
    
 
    return 0;
}
