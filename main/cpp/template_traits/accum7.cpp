/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accum6.hpp"
#include <iostream>

class MultPolicy
{
public:
        template <typename T1, typename T2>
        static void accumulate(T1& total, T2 const& value)
        {
                total *= value;
        }
};

int main()
{
        // create array of 5 integer values
        int num[] = {1, 2, 3, 4, 5};

        // print product of all values
        std::cout << "the product of the integer values is " << Accum<int, MultPolicy>::accum(&num[0], &num[5]) << '\n';
        return 0;
}
