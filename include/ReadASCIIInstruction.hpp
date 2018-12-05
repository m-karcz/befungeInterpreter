#pragma once

#include "IInstruction.hpp"
#include "IConsoleReader.hpp"

namespace befunge
{
struct ReadASCIIInstruction : IInstruction
{
    explicit ReadASCIIInstruction(IConsoleReader& p_consoleReader) :
        m_consoleReader{p_consoleReader}
    {}
    void execute(IContext& p_context) override
    {
        char l_value = m_consoleReader.readASCII();
        p_context.getStack().push(l_value);
    }
private:
    IConsoleReader& m_consoleReader;
};
}//namespace befunge
