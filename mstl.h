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
        Mvector &push_back(T* user_arr, size_t size_of_user_arr);
        Mvector &push_back(const Mvector &user_vector);
        Mvector &push_back(Mvector&& user_vector);

        T pop();
        T pop_front();

        //Chaining methods below doesn't make much sense
        void shrink_to_fit();

        //Returns the value of i element of main buffer
        T i_element(size_t index_of_element);
        T operator[](size_t index_of_element);
        T i_element(size_t index_of_element) const;
        T operator[](size_t index_of_element) const;
        Mvector& operator=(const Mvector& user_vector);
        size_t size() const;

    };

    class Mstring : public Mvector<char> {
    public:
        using Mvector::Mvector;

        Mstring(const char* user_mstring);
        Mstring(char user_string[]);
        Mstring(const Mstring& user_mstring);
        Mstring(Mstring&& user_mstring) noexcept;

        Mstring& add_ms(const char* user_char);

        Mstring& operator=(const Mstring& user_mstring);
        Mstring& operator=(const char* user_char);
        Mstring& operator=(Mstring&& user_mstring) noexcept;

        Mstring& operator+(const char* user_char);
        Mstring& operator+(const Mstring& user_mstring);
        Mstring& operator+=(const Mstring& user_mstring);
        Mstring& operator+=(const char* user_char);
    };

    template <typename T>
    class LinkedList {
        LinkedList* next;
        LinkedList* previous;
        T data;
        size_t number_of_elements;

    public:
        explicit LinkedList(T init_data);
        LinkedList* add_item(const T& input_data);
        LinkedList* add_item(T&& input_data);

        LinkedList* remove_item(size_t position);
        T print_index();
        LinkedList* get_last();
        LinkedList* get_first();
        LinkedList* get_position(size_t position);
        const T& get_data();
        void set_data(T new_data);
        size_t size() const;
        LinkedList<T>* operator[](size_t index);
    };
}