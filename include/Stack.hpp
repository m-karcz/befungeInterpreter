#pragma once

#include "IStack.hpp"
#include <stack>

namespace befunge
{
struct Stack : IStack
{
    void push(number_t p_value) override
    {
        m_stack.push(p_value);
    }
    number_t pop() override
    {
        number_t l_value = m_stack.top();
        m_stack.pop();
        return l_value;
    }

private:
    std::stack<number_t> m_stack;
};
}//namespace befunge
