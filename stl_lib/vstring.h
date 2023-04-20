#ifndef MY_STL_VSTRING_H
#define MY_STL_VSTRING_H

#include "vector.hxx"

namespace my_stl {
    class vstring : public vector<char> {
    public:
        using vector::vector;

        explicit vstring(const char *user_string);

        explicit vstring(char user_char[]);

        vstring &add_ms(const char *user_char);

        void remove_last_char();

        void remove_white_space_end();

        vstring &operator=(const char *user_char);

        bool operator==(const char *user_char);

        vstring &operator+(const char *user_char);

        vstring &operator+=(const char *user_char);

        bool operator==(const vstring &user_vstring);

        friend std::istream &operator>>(std::istream &is, vstring &vstring);

        friend std::ostream &operator<<(std::ostream &os, const vstring &vstring);
    };
}
#endif //MY_STL_VSTRING_H
