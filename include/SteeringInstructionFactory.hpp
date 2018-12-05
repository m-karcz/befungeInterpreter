#pragma once

#include "ISteeringInstructionFactory.hpp"

namespace befunge
{
struct SteeringInstructionFactory : ISteeringInstructionFactory
{
    std::unique_ptr<IInstruction> makeInstruction(IContext& p_context) override;
};
}//namespace befunge
