#include <iostream>
#include "mstl.hxx"

using namespace mstl;

int main()
{
    LinkedList<Mstring> list("HELLO");
    list.add_item("WORLD");
    //print contents of list
    for(int i = 0; i < list.size(); i++)
        std::cout << list[i]->get_data() << std::endl;
    return 0;
}