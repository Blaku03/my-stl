#include <iostream>
namespace mstl {
    template<typename T>
    class Mvector {
    protected:
        size_t current_size;
        size_t number_of_elements;

        void expand_twice_the_size();

        T *copy_array(T *pointer_to_array_that_should_be_copied, size_t size_of_array, bool double_size);

        //Check if buffer have enough space to take "x" elements
        bool enough_buffer_space(size_t space_to_add);

    public:
        T *main_buffer;

        Mvector();

        ~Mvector();

        //Returning references to allow chained calls
        Mvector &push_back(T user_value);

        Mvector &push_back(T user_arr[], size_t size_of_user_arr);

        Mvector &push_back(Mvector &user_vector);

        T pop();

        T pop_front();

        //Chaining methods below doesn't make much sense
        void shrink_to_fit();

        //Returns the value of i element of main buffer
        T i_element(size_t index_of_element);

        T operator[](size_t index_of_element);

        size_t size();

    };

    class Mstring : public Mvector<char> {
    public:
        using Mvector::Mvector;

        Mstring(char user_mstring[]);

        Mstring& add_ms(char user_char[]);

        Mstring& operator=(char user_char[]);
        Mstring& operator+(char user_char[]);
        Mstring& operator+(Mstring& user_mstring);
        Mstring& operator+=(Mstring& user_mstring);
        Mstring& operator+=(char user_char[]);
    };
}