/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#ifndef INC_TRAITS_ACCUM1_HPP
#define INC_TRAITS_ACCUM1_HPP

#include "accum1.hpp"
#include <iostream>

int main()
{
        int num[] = {1, 2, 3, 4, 5};
        std::cout << "the average value of the integer values is " << accum(&num[0], &num[5]) / 5 << '\n';
        char name[] = "templates";
        int length = sizeof(name) - 1;
        std::cout << "the average value of the characters in \"" << name << "\" is "
                  << accum(&name[0], &name[length]) / length << '\n';
        return 0;
}

#endif // INC_TRAITS_ACCUM1_HPP
