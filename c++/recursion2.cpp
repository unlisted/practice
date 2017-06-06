#include <iostream>

long factorial(long value)
{
    if (value == 1)
        return 1;

    // std::cout << counter <<  std::endl;
    return value * factorial(value - 1);
    // std::cout << counter << std::endl;
}

int main(int argc, char** argv)
{
    auto value = factorial(20);
    std::cout << value << std::endl;

    return 0;
}
