#include "mstl.h"

using namespace mstl;

template<typename T>
void Mvector<T>::expand_twice_the_size() {
    T *helper_buffer = copy_array(main_buffer, current_size, false);
    delete[] main_buffer;

    //Doubling the size of main buffer
    main_buffer = copy_array(helper_buffer, current_size, true);
    current_size *= 2;

    delete[] helper_buffer;
}

template<typename T>
T* Mvector<T>::copy_array(T *pointer_to_array_that_should_be_copied, size_t size_of_array, bool double_size) {
    T *copied_array = new T[double_size ? size_of_array * 2 : size_of_array];

    for (int i = 0; i < size_of_array; i++) {
        *(copied_array + i) = *(pointer_to_array_that_should_be_copied + i);
    }

    return copied_array;
}

template<typename T>
bool Mvector<T>::enough_buffer_space(size_t space_to_add) {
    return space_to_add + number_of_elements < current_size;
}

template<typename T>
Mvector<T>::Mvector() {
    current_size = 11;
    main_buffer = new T[current_size];
    number_of_elements = 0;
}

template<typename T>
Mvector<T>::~Mvector(){
    if(main_buffer != nullptr){
        delete [] main_buffer;
    }
}

template<typename T>
Mvector<T>& Mvector<T>::push_back(T user_value) {
    //Check if array isn't too small
    if (current_size <= number_of_elements) expand_twice_the_size();

    //Add user's value to array
    *(main_buffer + number_of_elements) = user_value;
    number_of_elements++;
    return *this;
}

template<typename T>
Mvector<T>& Mvector<T>::push_back(T *user_arr, size_t size_of_user_arr) {
    while (!enough_buffer_space(size_of_user_arr)) expand_twice_the_size();

    for (int i = 0; i < size_of_user_arr; i++) {
        *(main_buffer + number_of_elements) = *(user_arr + i);
        number_of_elements++;
    }

    return *this;
}

template<typename T>
Mvector<T>& Mvector<T>::push_back(Mvector<T> &user_vector) {
    //Add it to variable to not call method all the time
    size_t user_vector_size = user_vector.size();

    while (!enough_buffer_space(user_vector_size)) expand_twice_the_size();

    for (int i = 0; i < user_vector_size; i++) {
        *(main_buffer + number_of_elements) = user_vector.i_element(i);
        number_of_elements++;
    }

    return *this;
}

template<typename T>
T Mvector<T>::pop() {
    if (number_of_elements > 0) number_of_elements--;
    return main_buffer[number_of_elements];
}

template<typename T>
T Mvector<T>::pop_front() {
    if(number_of_elements == 0) return 0;

    T *helper_buffer = new T[current_size];
    T popped_element = main_buffer[0];

    for (int i = 1; i < number_of_elements; i++) {
        *(helper_buffer + i - 1) = *(main_buffer + i);
    }

    number_of_elements--;
    delete[] main_buffer;
    main_buffer = helper_buffer;
    return popped_element;
}

template<typename T>
void Mvector<T>::shrink_to_fit() {
    T *helper_buffer = copy_array(main_buffer, number_of_elements, false);
    delete[] main_buffer;

    main_buffer = helper_buffer;
    current_size = number_of_elements;
}

template<typename T>
T Mvector<T>::i_element(size_t index) {
    if (index < number_of_elements) return main_buffer[index];
    std::cout << "ERROR: INDEX GIVEN IS NOT WITHIN THE VECTOR\n";
    exit(99);
}

template<typename T>
T Mvector<T>::operator[](size_t index) {
    return i_element(index);
}

template<typename T>
Mvector<T>& Mvector<T>::operator=(const Mvector& user_vector) {
    delete[] main_buffer;

    main_buffer = copy_array(user_vector.main_buffer, user_vector.current_size, false);
    number_of_elements = user_vector.number_of_elements;
    current_size = user_vector.current_size;

    return *this;
}

template<typename T>
size_t Mvector<T>::size() const {
    return number_of_elements;
}

Mstring::Mstring(char user_char[]) : Mvector<char>() {
    add_ms(user_char);
}

Mstring::Mstring(const Mstring& user_mstring) : Mvector<char>() {
    main_buffer = copy_array(user_mstring.main_buffer, user_mstring.current_size, false);
    number_of_elements = user_mstring.number_of_elements;
    current_size = user_mstring.current_size;
}

Mstring::Mstring(Mstring&& user_mstring) noexcept : Mvector<char>() {
    main_buffer = user_mstring.main_buffer;
    user_mstring.main_buffer = nullptr;

    number_of_elements = user_mstring.number_of_elements;
    current_size = user_mstring.current_size;
}

Mstring& Mstring::add_ms(char user_char[]) {
    int element = 0;

    while (user_char[element] != '\0') {
        if (number_of_elements >= current_size) expand_twice_the_size();
        *(main_buffer + number_of_elements) = user_char[element];
        element++;
        number_of_elements++;
    }

    return *this;
}

Mstring& Mstring::operator=(const Mstring& user_mstring){
    delete[] main_buffer;

    main_buffer = copy_array(user_mstring.main_buffer, user_mstring.current_size, false);
    number_of_elements = user_mstring.number_of_elements;
    current_size = user_mstring.current_size;

    return *this;
}

Mstring& Mstring::operator=(char user_char[]){
    int element = 0;

    while (user_char[element] != '\0') {
        if (number_of_elements >= current_size) expand_twice_the_size();
        *(main_buffer + element) = user_char[element];
        element++;
        number_of_elements++;
    }

    *(main_buffer + element) = '\0';
    number_of_elements++;

    return *this;
}

Mstring& Mstring::operator+(char user_char[]){
    add_ms(user_char);

    return *this;
}

Mstring& Mstring::operator+(Mstring& user_mstring){
    Mstring *new_mstring = new Mstring();

    new_mstring->add_ms(main_buffer);
    new_mstring->add_ms(user_mstring.main_buffer);

    return *new_mstring;
}

Mstring& Mstring::operator+=(char user_char[]){
    add_ms(user_char);

    return *this;
}

Mstring& Mstring::operator+=(Mstring& user_mstring){
    add_ms(user_mstring.main_buffer);

    return *this;
}

std::ostream& operator<<(std::ostream &os, const Mstring &mstring){

    for (int i = 0; i < mstring.size(); i++) {
        os << mstring.main_buffer[i];
    }

    return os;
}

std::istream& operator>>(std::istream &is, Mstring &mstring){
    char *user_input = new char[1024];
    std::cin >> user_input;

    mstring.add_ms(user_input);

    delete [] user_input;
    return is;
}

template<typename T>
LinkedList<T>::LinkedList(T init_data) {
    previous = NULL;
    next = NULL;
    data = init_data;
    number_of_elements = 1;
}

template<typename T>
LinkedList<T>* LinkedList<T>::add_item(const T& input_data) {
    LinkedList<T>* new_item = new LinkedList<T>(input_data);
    new_item->previous = this;
    this->next = new_item;
    number_of_elements++;
    return new_item;
}

template<typename T>
T LinkedList<T>::print_index() {
    return data;
}

template<typename T>
LinkedList<T> *LinkedList<T>::get_first() {
    LinkedList<T> *first_item = this;

    while (first_item->previous != NULL) {
        first_item = first_item->previous;
    }

    return first_item;
}

template<typename T>
LinkedList<T> *LinkedList<T>::get_last() {
    LinkedList<T> *last_item = this;

    while (last_item->next != NULL) {
        last_item = last_item->next;
    }

    return last_item;
}

template<typename T>
LinkedList<T>* LinkedList<T>::get_position(size_t position) {
    if (position >= number_of_elements) return NULL;
    LinkedList<T>* item_to_return = get_first();

    for (int i = 0; i < position; i++) {
        item_to_return = item_to_return->next;
    }

    return item_to_return;
}

template<typename T>
const T& LinkedList<T>::get_data() {
    return data;
}

template<typename T>
void LinkedList<T>::set_data(T new_data) {
    data = new_data;
}

template<typename T>
LinkedList<T>* LinkedList<T>::remove_item(size_t position) {
    LinkedList<T>* item_to_remove = get_position(position);
    LinkedList<T>* previous_item = item_to_remove->previous;
    LinkedList<T>* next_item = item_to_remove->next;

    previous_item->next = next_item;
    next_item->previous = previous_item;

    delete item_to_remove;
    number_of_elements--;
    return previous_item;
}

template<typename T>
size_t LinkedList<T>::size() const {
    return number_of_elements;
}

template<typename T>
LinkedList<T>* LinkedList<T>::operator[](size_t index) {
    return get_position(index);
}