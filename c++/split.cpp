#include <iostream>
#include <sstream>
#include <vector>


class Foo {
    public:
        Foo(std::string s) : _s(s) { std::cout << _s << std::endl; }
        std::vector<std::string> Parse() {
            char token;
            std::string word;
            std::stringstream strm(_s);
            std::vector<std::string> ret;
            while(strm >> token) {
                std::cout << token << std::endl;
                if (token == ',') {
                    ret.push_back(word);
                    word.clear();
                } else
                    word += token;
            }
            return ret;
        }


    private:
        std::string _s;
        friend std::ostream& operator<<(std::ostream& lh, Foo& rh) { lh << rh._s; }
};



int main(int argc, char** argv) {

    Foo f("hello,this,is,a,test.");
    std::cout << f << std::endl;
    auto vals = f.Parse();
    std::cout << vals.size() << std::endl;
    for (auto& token : vals) {
        std::cout << token << std::endl;
    }

    return 0;
}
