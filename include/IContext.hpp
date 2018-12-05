#pragma once

#include "IMovement.hpp"
#include "IStack.hpp"
#include "IGrid.hpp"

namespace befunge
{

struct IContext
{
    virtual bool isRunning() = 0;
    virtual void halt() = 0;
    virtual IMovement& getMovement() = 0;
    virtual IStack& getStack() = 0;
    virtual IGrid& getGrid() = 0;
    virtual ~IContext() = default;
};
}//namespace befunge
