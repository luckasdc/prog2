#pragma once
/**
 * @file
 * Predefined policies for handling a cell count violation.
 * @author  Jan Broeckhove, CoMP/UA
 * @remark (c) Jan Broeckhove, 2011.
 */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

namespace UA_CoMP {
namespace Num {

/**
 * Policy throws a std::runtime_error exception when condition is violated.
 */
class OnViolationThrow
{
public:
        /** Checks and throws iff condition is violated, otherwise return true. */
        static bool check(bool b)
        {
                if (!b) {
                        throw std::runtime_error("Cellcount violation in AdaptiveQuadrature");
                }
                return b;
        }
};

/**
 * Policy just returns whatever the condition, after writing a message to
 * standard error.
 */
class OnViolationReturn
{
public:
        /** Checks but goes on in any case. */
        static bool check(bool b) { return b; }
};

/**
 * Policy that exits, after writing a message to standard error.
 */
class OnViolationExit
{
public:
        static bool check(bool b)
        {
                if (!b) {
                        exit(EXIT_FAILURE);
                }
                return b;
        }
};

} // namespace Num
} // namespace UA_CoMP
