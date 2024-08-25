#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <vector>
#include <iterator>

template<typename T>
void print_vector(const T& t, std::string seperator = " ") {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, seperator.c_str()));
    std::cout << "\n";
}

// Write inline? function to execution time countdown
// Write function to check other functions with n range data + time
// Rewrite print_vector to avoid last char print

#endif // UTILS_H_INCLUDED
