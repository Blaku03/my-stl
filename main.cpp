#include <iostream>
#include "mstl.h"

int main()
{

    Mvector<int> x;
    x.push_back(1);
    std::cout << x[0];

    return 0;
}