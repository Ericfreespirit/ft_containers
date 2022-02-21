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

template <class T>
struct is_integral {static const bool value = false;};
template<>
struct is_integral<bool> {static const bool value = true;};
template<>
struct is_integral<char> {static const bool value = true;};
template<>
struct is_integral<char32_t> {static const bool value = true;};
template<>
struct is_integral<char16_t> {static const bool value = true;};
template<>
struct is_integral<wchar_t> {static const bool value = true;};
template<>
struct is_integral<signed char> {static const bool value = true;};
template<>
struct is_integral<short int> {static const bool value = true;};
template<>
struct is_integral<int> {static const bool value = true;};
template<>
struct is_integral<long int> {static const bool value = true;};
template<>
struct is_integral<long long int> {static const bool value = true;};
template<>
struct is_integral<unsigned char> {static const bool value = true;};
template<>
struct is_integral<unsigned short int> {static const bool value = true;};
template<>
struct is_integral<unsigned int> {static const bool value = true;};
template<>
struct is_integral<unsigned long int> {static const bool value = true;};
template<>
struct is_integral<unsigned long long int> {static const bool value = true;};

} // end of namespace ft

#endif