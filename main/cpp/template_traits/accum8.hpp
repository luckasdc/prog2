#pragma once
/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "accumtraits4.hpp"
#include "sumpolicy2.hpp"

template <typename T, template <typename, typename> class Policy = SumPolicy, typename Traits = AccumulationTraits<T>>
class Accum
{
public:
        using AccT = typename Traits::type;

public:
        static AccT accum(T const* beg, T const* end)
        {
                AccT total = Traits::zero();
                while (beg != end) {
                        Policy<AccT, T>::accumulate(total, *beg);
                        ++beg;
                }
                return total;
        }
};
