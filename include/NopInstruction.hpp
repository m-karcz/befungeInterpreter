#pragma once

#include "Tagged.hpp"
#include "IInstruction.hpp"

namespace befunge
{
struct NopInstruction : Tagged<' '>,
                        IInstruction
{
    void execute(IContext&) override
    {}
}; 
}//namespace befunge
