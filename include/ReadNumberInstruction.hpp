#pragma once

#include "IInstruction.hpp"
#include "IConsoleReader.hpp"

namespace befunge
{
struct ReadNumberInstruction : IInstruction
{
    explicit ReadNumberInstruction(IConsoleReader& p_consoleReader) :
        m_consoleReader{p_consoleReader}
    {}
    void execute(IContext& p_context) override
    {
        number_t l_value = m_consoleReader.readNumber();
        p_context.getStack().push(l_value);
    }
private:
    IConsoleReader& m_consoleReader;
};
}//namespace befunge
