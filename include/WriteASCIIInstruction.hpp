#pragma once

#include "IInstruction.hpp"
#include "IConsoleWriter.hpp"
#include <limits>

namespace befunge
{
struct WriteASCIIInstruction : IInstruction
{
    explicit WriteASCIIInstruction(IConsoleWriter& p_consoleWriter) :
        m_consoleWriter{p_consoleWriter}
    {}
    void execute(IContext& p_context) override
    {
        number_t l_value = p_context.getStack().pop();
        if(l_value > std::numeric_limits<char>::max())
        {
            std::logic_error{std::string{"Tried to print nonASCII value: "} + std::to_string(l_value)};
        }
        m_consoleWriter.writeASCII(static_cast<char>(l_value));
    }
private:
    IConsoleWriter& m_consoleWriter;
};
}//namespace befunge
