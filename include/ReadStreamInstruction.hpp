#pragma once

#include "IInstruction.hpp"
#include "Tagged.hpp"

namespace befunge
{
struct ReadStreamInstruction : Tagged<'"'>,
                               IInstruction
{
    void execute(IContext& p_context) override
    {
        IMovement& l_movement = p_context.getMovement();
        IGrid& l_grid = p_context.getGrid();
        IStack& l_stack = p_context.getStack();

        l_movement.makeStep();
        char l_readValue = l_grid.getCell(l_movement.getPosition()).get();

        while(l_readValue != tag)
        {
            l_stack.push(l_readValue);
            l_movement.makeStep();
            l_readValue = l_grid.getCell(l_movement.getPosition()).get();
        }
    }
};
                               
}//namespace befunge
