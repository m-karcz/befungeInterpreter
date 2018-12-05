#pragma once

#include "Position.hpp"
#include "Direction.hpp"

namespace befunge
{
struct IMovement
{
    virtual void setDirection(Direction p_direction) = 0;
    virtual void makeStep() = 0;
    virtual Position getPosition() = 0;
    virtual ~IMovement() = default;
};
}//namespace befunge
