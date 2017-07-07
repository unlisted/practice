#include <iostream>
#include <string>


using namespace std;

class StringWrapper {
public:
    StringWrapper() = default;
    StringWrapper(string str) :_str(str) {};

    void Print() {cout << _str << endl; }

    StringWrapper &operator++() { 
        auto carry = true;
        auto riter = rbegin(_str);

        for (;riter != rend(_str); ++riter) {
            if (carry) {
                if (++(*riter) > 'z') {
                    *riter = 'a';
                    carry = true;
                } else
                    carry = false;
            } else 
                break;
        }

        if (carry)
            _str.resize(_str.size()  + 1, 'a');

        return *this;
    }
    StringWrapper operator++(int) { cout << "ss++" << endl; return *this; }
private:
    string _str;
};

int main(int argc, char* argv[]) {

    StringWrapper ss {"z"};
    ss.Print();
    ++ss;
    //ss++;
    ss.Print();
    return 0;
}
