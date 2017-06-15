#include <string>
#include <iostream>
#include <memory>

using namespace std;

struct HashNode {
    HashNode(int key, string value) : _key(key), _value(value) {}
    int _key;
    string _value;
};

string getName ()
{
        return "Morgan";
}

// takes all non-mutable rvalue/lvalue because of presence of overload below
void PrintMe(const std::string& val) {
    cout << "non-mutable lvalue/rvalue ref" << endl;
    cout << val << endl;
}

// takes mutable rvalue ref
void PrintMe(std::string &&val) {
    cout << "mutable rvalue ref" << endl;
    cout << val << endl;
}

int main(int argc, char *argv[]) {

    string ss("test");
    //PrintMe(ss);
    PrintMe(string("hello"));


    auto node = make_unique<HashNode>(1, "test");

    // should be lvalue
    //PrintMe(node->_value);

    // casts to mutable rvalue ref
    //PrintMe(move(node->_value));
    return 0;
}
