#include <iostream>
#include "mstl.h"

using namespace mstl;

int main() {
    Mvector<int> my_vector;
    Mvector<int> test_vector;

    my_vector.push(1).push(2).push(3);
    test_vector.push(8).push(9);

    my_vector.push_mvector(test_vector);

     for(int i = 0; i < my_vector.size(); i++){
         std::cout<<my_vector.i_element(i);
     }

    return 0;
}