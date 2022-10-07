#include <iostream>

template <typename T>
class Mvector{
private:
    int current_size;
    int number_of_elements;
    T* main_buffer;
    
public:
    Mvector(){
        current_size = 10;
        main_buffer = new T[current_size];
        number_of_elements = 0;
    }

    ~Mvector(){
        delete main_buffer;
    }
};


int main() {
    Mvector<int> test;
    return 0;
}