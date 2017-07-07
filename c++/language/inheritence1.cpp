#include <iostream>

using namespace std;


/* since Base contains a virtual function it also contains a hidden vptr which
 * points to Base's vtable. vptr is inherited publicly by all of base's derived
 * classes.
 *
 * And objects vtable contains contains pointers to the most objects most derived
 * virtual functions
 *
 * When Base object is created vptr is set to point to Base's vtable
 */

class Base {
public:
    Base() { cout << "Base()" << endl; }
    void func1() { cout << "Base::func1()" << endl; }
    virtual void func2() { cout << "Base::func2()" << endl; }
    virtual void func4() { cout << "Base::func4()" << endl; }
};

/* When D1 object is created it's vptr (inherited from Base) is pointed to D1's 
 * vtable. D1's vtable contains three entries;
 *  func2 -> D1::func2()
 *  func4 -> Base::func4()
 *
 */
struct D1 : Base {
    D1() { cout << "D1()" << endl; }
    void func3() { cout << "D1::func3" << endl; }
    virtual void func2() override { cout << "D1::func2" << endl; }
};

int main(int argc, char *argv[]) {

    Base *b1 = new D1();

    auto b2 = dynamic_cast<D1*>(b1);
    b2->func3();

    /*
    Base b1;
    b1.func2();
    D1 d1;
    d1.func4();
    Base *b = &d1;
    b->func2();
    b->func4();
    */
    return 0;
}

