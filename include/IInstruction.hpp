#pragma once

#include "IContext.hpp"

namespace befunge
{


struct IInstruction
{
    virtual void execute(IContext& p_context) = 0;
    virtual ~IInstruction() = default;
};

}//namespace befunge
