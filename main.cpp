#include <iostream>
#include "mstl.hxx"

using namespace mstl;

int main()
{
    Mstring test;
    std::cin >> test;
    test += " ";
    std::cin>>test;
    std::cout << test << std::endl;

    return 0;
}