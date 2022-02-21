#ifndef _IS_H
#define _IS_H

namespace ft{

template <bool Cond, class T = void>
struct is_iterator {

}; // end of class is_iterator

/*
bool
char
char16_t
char32_t
wchar_t
signed char
short int
int
long int
long long int
unsigned char
unsigned short int
unsigned int
unsigned long int
unsigned long long int
*/

 template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

    /*
    ** @brief default template of the structure is_integral_type.
    ** If the type given in argument is from the list, the structure
    ** will be overide by nexts, in according to it type.
    ** If the type given is argument isn't in the list, 
    ** stocked value will be false. So it's not a integral type.
    */
    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

    /* @brief is_integral_type for bool. "value is true".*/
    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    /* @brief is_integral_type for char. "value is true".*/
    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    /* @brief is_integral_type for signed char. "value is true".*/
    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    /* @brief is_integral_type for short int. "value is true".*/
    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    /* @brief is_integral_type for int. "value is true".*/
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    /* @brief is_integral_type for long int. "value is true".*/
    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    /* @brief is_integral_type for long long int. "value is true".*/
    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    /* @brief is_integral_type for unsigned char. "value is true".*/
    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    /* @brief is_integral_type for unsigned short int. "value is true".*/
    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    /* @brief is_integral_type for unsigned int. "value is true".*/
    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    /* @brief is_integral_type for unsigned long int. "value is true".*/
    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    /* @brief is_integral_type for unsigned long long int. "value is true".*/
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    /*
    ** @brief Give a structure who contain is the
    ** typename given in template is integral or not,
    ** stocked in "value".
    */
    template <typename T>
        struct is_integral : public is_integral_type<T> { };

    /*  End of is_integral. */

// template <class T>
// struct is_integral {static const bool value = false;};
// template<>
// struct is_integral<bool> {static const bool value = true;};
// template<>
// struct is_integral<char> {static const bool value = true;};
// template<>
// struct is_integral<char32_t> {static const bool value = true;};
// template<>
// struct is_integral<char16_t> {static const bool value = true;};
// template<>
// struct is_integral<wchar_t> {static const bool value = true;};
// template<>
// struct is_integral<signed char> {static const bool value = true;};
// template<>
// struct is_integral<short int> {static const bool value = true;};
// template<>
// struct is_integral<int> {static const bool value = true;};
// template<>
// struct is_integral<long int> {static const bool value = true;};
// template<>
// struct is_integral<long long int> {static const bool value = true;};
// template<>
// struct is_integral<unsigned char> {static const bool value = true;};
// template<>
// struct is_integral<unsigned short int> {static const bool value = true;};
// template<>
// struct is_integral<unsigned int> {static const bool value = true;};
// template<>
// struct is_integral<unsigned long int> {static const bool value = true;};
// template<>
// struct is_integral<unsigned long long int> {static const bool value = true;};

} // end of namespace ft

#endif