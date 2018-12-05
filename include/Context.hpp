#pragma once

#include <memory>
#include "IContext.hpp"
#include "IMovement.hpp"

namespace befunge
{
struct Context : IContext
{
    explicit Context(std::unique_ptr<IStack> p_stack,
                     std::unique_ptr<IMovement> p_movement,
                     std::unique_ptr<IGrid> p_grid) :
        m_stack{std::move(p_stack)},
        m_movement{std::move(p_movement)},
        m_grid{std::move(p_grid)}
    {}
    IMovement& getMovement() override
    {
        return *m_movement;
    }
    IStack& getStack() override
    {
        return *m_stack;
    }
    IGrid& getGrid() override
    {
        return *m_grid;
    }
    void halt() override
    {
        m_isRunning = false;
    }
    bool isRunning() override
    {
        return m_isRunning;
    }
private:
    std::unique_ptr<IStack> m_stack;
    std::unique_ptr<IMovement> m_movement;
    std::unique_ptr<IGrid> m_grid;
    bool m_isRunning = true;
};
}//namespace befunge
