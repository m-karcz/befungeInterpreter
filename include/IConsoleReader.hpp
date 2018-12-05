#pragma once

#include "defines.hpp"

namespace befunge
{
struct IConsoleReader
{
    virtual char readASCII() = 0;
    virtual number_t readNumber() = 0;
    virtual ~IConsoleReader() = default;
};
}//namespace befunge
