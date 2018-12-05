#pragma once

#include "Tagged.hpp"

namespace befunge
{
template<Direction DirectionValue>
struct ChangeMovementInstruction : IInstruction
{
    void execute(IContext& p_context) override
    {
        p_context.getMovement().setDirection(DirectionValue);
    }
};

template<char Code, Direction DirectionValue>
struct TaggedChangeMovementInstruction : Tagged<Code>,
                                         ChangeMovementInstruction<DirectionValue>
{};

using TurnLeftInstruction = TaggedChangeMovementInstruction<'<', Direction::Left>;
using TurnRightInstruction = TaggedChangeMovementInstruction<'>', Direction::Right>;
using TurnUpInstruction = TaggedChangeMovementInstruction<'^', Direction::Up>;
using TurnDownInstruction = TaggedChangeMovementInstruction<'v', Direction::Down>;

}//namespace befunge
