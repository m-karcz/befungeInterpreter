#pragma once

#include "defines.hpp"

namespace befunge
{
struct IConsoleWriter
{
    virtual void writeASCII(char p_value) = 0;
    virtual void writeNumber(number_t p_value) = 0;
    virtual ~IConsoleWriter() = default;
};
}//namespace befunge
