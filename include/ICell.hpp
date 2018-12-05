#pragma once

#include "ICell.hpp"

namespace befunge
{
struct ICell
{
    virtual char get() const = 0;
    virtual void set(char p_value) = 0;
    virtual ~ICell() = default;
};
}//namespace befunge
