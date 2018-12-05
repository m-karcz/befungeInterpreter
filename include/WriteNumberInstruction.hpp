#pragma once

#include "IInstruction.hpp"
#include "IConsoleWriter.hpp"

namespace befunge
{
struct WriteNumberInstruction : IInstruction
{
    explicit WriteNumberInstruction(IConsoleWriter& p_consoleWriter) :
        m_consoleWriter{p_consoleWriter}
    {}
    void execute(IContext& p_context) override
    {
        number_t l_value = p_context.getStack().pop();
        m_consoleWriter.writeNumber(l_value);
    }
private:
    IConsoleWriter& m_consoleWriter;
};
}//namespace befunge
