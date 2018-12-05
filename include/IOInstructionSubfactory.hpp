#pragma once

#include "IInstructionSubfactory.hpp"
#include "IConsoleWriter.hpp"
#include "IConsoleReader.hpp"

namespace befunge
{
struct IOInstructionSubfactory : IInstructionSubfactory
{
    explicit IOInstructionSubfactory(std::unique_ptr<IConsoleReader> p_consoleReader,
                                     std::unique_ptr<IConsoleWriter> p_consoleWriter) :
        m_consoleReader{std::move(p_consoleReader)},
        m_consoleWriter{std::move(p_consoleWriter)}
    {}
    std::unique_ptr<IInstruction> makeInstruction(char p_tag) override;
private:
    std::unique_ptr<IConsoleReader> m_consoleReader;
    std::unique_ptr<IConsoleWriter> m_consoleWriter;
};
}//namespace befunge
