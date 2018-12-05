#pragma once

#include "Tagged.hpp"
#include "IInstruction.hpp"

namespace befunge
{
struct HaltInstruction : Tagged<'@'>,
                         IInstruction
{
    void execute(IContext& p_context) override
    {
        p_context.halt();
    }
};
}//namespace befugne
