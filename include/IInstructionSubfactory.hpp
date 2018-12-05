#pragma once

#include "IInstruction.hpp"
#include <memory>

namespace befunge
{
struct IInstructionSubfactory
{
    virtual std::unique_ptr<IInstruction> makeInstruction(char p_tag) = 0;
    virtual ~IInstructionSubfactory() = default;
};
}//namespace befunge
