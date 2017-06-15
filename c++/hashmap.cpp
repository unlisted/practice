#include <iostream>
#include <array>
#include <vector>
#include <memory>
#include <string>

using namespace std;

constexpr int SIZE = 10;

template <class  K>
struct HashNode {
    HashNode(K key, string value) : _key(key), _value(value) {}
    K _key;
    string _value;
};

template <class K>
class HashMap {
public:
    using Table = array<vector<unique_ptr<HashNode<K>>>, SIZE>;
    HashMap() {
        cout << "HashMap()" << endl;
    }

    void Put(const K& key, const string& value) {
        int idx = hashFunc(key);

        auto &row = _table[idx];
        auto node = make_unique<HashNode<K>>(key, value);

        row.push_back(move(node));
    }

    string Get(K key) {
        auto idx = hashFunc(key);
        return GetValue(idx, key);
    }

    void Get(K key, string *ret) {
        auto idx = hashFunc(key);
        return GetValue(idx, key, ret);
    }

    string GetValue(int idx, K key) {
        const auto &row = _table[idx];
        for (const auto &node : row) {
            if (node->_key == key) {
                // returns lvalue ref
                return node->_value;
            }
        }
        // potentially two copies in c++03
        // 1. temporary to be returned
        // 2. temporary to be assigned
        //
        // c++11
        // identical to return std::move(string(""))
        return string("");
    }

    void GetValue(int idx, K key, string *ret) {
        const auto &row = _table[idx];
        for (const auto &node : row) {
            if (node->_key == key) {
                *ret = node->_value;
                break;
            }
        }
    }

    void Test() {
        for (auto &row : _table) {
            cout << "row" << endl;
            cout << row.size() << endl;
        }
    }
    
private:
    Table _table;
    size_t hashFunc(const K& value) { return 0; }
};

int main(int argc, char *argv[]) {

    HashMap<string> hm;
    //hm.Test();
    string key("kk");
    string value("foo");
    hm.Put(key, value);
    auto res = hm.Get(key);
    cout << res << endl;
    string ret2;
    hm.Get(key, &ret2);
    cout << ret2 << endl;;
    return 0;
}
