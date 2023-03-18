#include <iostream>

    template<typename T>
    class Mvector {
    protected:
        size_t current_size;
        size_t number_of_elements;
        T *main_buffer;

        void expand_twice_the_size();
        T *copy_array(T *pointer_to_array_that_should_be_copied, size_t size_of_array, bool double_size);

        //Check if buffer have enough space to take "x" elements
        bool enough_buffer_space(size_t space_to_add);

    public:
        Mvector();
        ~Mvector();

        //Returning references to allow chained calls
        Mvector& push_back(T user_value);
        Mvector& push_back(T user_arr[], size_t size_of_user_arr);
        Mvector& push_back(Mvector &user_vector);

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

        Mstring(char user_mstring[]) : Mvector<char>() {
            add_ms(user_mstring);
        }

        Mstring &add_ms(const char user_char[]) {
            int element = 0;

            while (user_char[element] != '\0') {
                if (number_of_elements == current_size) expand_twice_the_size();
                *(main_buffer + element) = user_char[element];
                element++;
                number_of_elements++;
            }

            return *this;
        }

        void print() {

            for (int i = 0; i < number_of_elements; i++) {
                std::cout << (char) *(main_buffer + i);
            }
        }
    };
