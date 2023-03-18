#include <iostream>
#include "mstl.hxx"

using namespace mstl;

int main()
{
    Mstring test("Hello");
    Mstring test2;
    test2 = "World";
    test = test + " " + test2;
    std::cout << test << std::endl;

    return 0;
}