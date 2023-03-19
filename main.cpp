#include <iostream>
#include "mstl.hxx"

using namespace mstl;

int main()
{
    LinkedList<Mstring> test("HI");
    Mstring jol = "JOL";
//    std::cout<<jol;
    test.add_item("YOU");
//    Mstring xd = "PR";
//    std::cout<<xd;
    std::cout<<test[0]->get_data()<<std::endl;
    std::cout<<test[1]->get_data()<<std::endl;
    return 0;
}