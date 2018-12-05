#pragma once

#include "Tagged.hpp"
#include "IInstruction.hpp"

namespace befunge
{
struct SkipInstruction : Tagged<'#'>,
                         IInstruction
{
    void execute(IContext& p_context) override
    {
        p_context.getMovement().makeStep(); 
    }
};
}//namespace befunge
