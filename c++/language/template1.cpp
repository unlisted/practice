template <typename T> class Foo
{
public:
    using type = T;

public:
    virtual void Handle(T* thing) = 0;

private:
};

using TestFoo = Foo<int>;

class Bar : public TestFoo {
    virtual void Handle(int* thing) { }
};

int main(int argc, char *argv[]) {

    Bar ttt;
    return 0;
}
