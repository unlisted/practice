#include <iostream>

void f(int counter)
{
    if (counter <= 0)
        return;

    std::cout << counter << std::endl;
    f(counter - 1);
    // std::cout << counter << std::endl;
}

int main(int argc, char** argv)
{
    f(3);

    return 0;
}
