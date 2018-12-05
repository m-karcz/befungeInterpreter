#pragma once

#include "defines.hpp"

namespace befunge
{

struct IStack
{
    virtual void push(number_t p_value) = 0;
    virtual number_t pop() = 0;
    virtual ~IStack() = default;
};

}//namespace befunge
