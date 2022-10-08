#ifndef MY_LIBRARY_MSTL_H
#define MY_LIBRARY_MSTL_H
namespace mstl{
template <typename T>
class Mvector{
protected:
    int current_size;
    int number_of_elements;
    T* main_buffer;

    void expand_twice_the_size(){
        T* helper_buffer = copy_array(main_buffer, current_size,false);
        delete [] main_buffer;

        //Doubling the size of main buffer
        main_buffer = copy_array(helper_buffer,current_size,true);
        current_size *=2;

        delete [] helper_buffer;
    }

    T* copy_array(T* pointer_to_array_that_should_be_copied, int size_of_array, bool double_size){
        T* copied_array = new T[double_size ? size_of_array * 2 : size_of_array];

        for(int i = 0; i < size_of_array; i++){
            *(copied_array + i) = *(pointer_to_array_that_should_be_copied + i);
        }

        return copied_array;
    }

    //Check if buffer have enough space to take "x" elements
    bool enough_buffer_space(int space_to_add){
        return space_to_add + number_of_elements <= current_size;
    }

public:
    Mvector(){
        current_size = 11;
        main_buffer = new T[current_size];
        number_of_elements = 0;
    }

    ~Mvector(){
        delete [] main_buffer;
    }

    //Returning references to allow chained calls
    Mvector& push(T user_value){
        //Check if array isn't too small
        if(current_size == number_of_elements) expand_twice_the_size();

        //Add user's value to array
        *(main_buffer + number_of_elements) = user_value;
        number_of_elements++;
        return *this;
    }

    Mvector& push(T user_arr[], int size_of_user_arr){
        //Make sure that main buffer have the proper size
        while(!enough_buffer_space(size_of_user_arr)) expand_twice_the_size();


        for(int i = 0; i < size_of_user_arr; i++){
            *(main_buffer + number_of_elements) = user_arr[i];
            number_of_elements++;
        }

        return *this;
    }

    Mvector& push(Mvector& user_vector){

        //Add it to variable to not call method all the time
         int user_vector_size = user_vector.size();

        while(!enough_buffer_space(user_vector_size)) expand_twice_the_size();

        for(int i = 0; i < user_vector_size; i++){
            *(main_buffer + number_of_elements) = user_vector.i_element(i);
            number_of_elements++;
        }

        return *this;
    }

    T pop(){
        if(number_of_elements > 0) number_of_elements--;
        return main_buffer[number_of_elements];
    }

    //Chaining methods below doesn't make much sense
    void shrink_to_fit() {
        if (current_size == number_of_elements) return;

        //Just copy the array but size of the copied array will be number of elements instead of current size
        T* helper_buffer = copy_array(main_buffer, number_of_elements, false);
        delete [] main_buffer;

        main_buffer = helper_buffer;

        //Effect of this function
        current_size = number_of_elements;
        //Note not to delete helper buffer because that will result in deleting main buffer (they point to the same address now)
    }

    //Returns the value of i element of main buffer
    T i_element(int index_of_element) {
        if (index_of_element < number_of_elements) return main_buffer[index_of_element];
        std::cout<<"ERROR: INDEX GIVEN IS NOT WITHIN THE VECTOR"<<std::endl;
        exit(99);
    }

    int size() {
        return number_of_elements;
    }
};

class Mstring : public Mvector<char>{
public:
    using Mvector::Mvector;

    Mstring(char user_mstring[]) : Mvector<char>(){
        add_ms(user_mstring);
    }

    Mstring& add_ms(const char user_char[]){
        int element = 0;

        while(user_char[element] != '\0'){
            if(number_of_elements == current_size) expand_twice_the_size();
            *(main_buffer + element) = user_char[element];
            element++;
            number_of_elements++;
        }

        return *this;
    }

    void print(){

        for(int i = 0; i < number_of_elements; i++){
            std::cout<<(char)*(main_buffer + i);
        }

    }
};
}
#endif //MY_LIBRARY_MSTL_H