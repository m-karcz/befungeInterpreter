#include "IOInstructionSubfactory.hpp"
#include "ReadASCIIInstruction.hpp"
#include "ReadNumberInstruction.hpp"
#include "WriteASCIIInstruction.hpp"
#include "WriteNumberInstruction.hpp"

namespace befunge
{

std::unique_ptr<IInstruction> IOInstructionSubfactory::makeInstruction(char p_tag)
{
    switch(p_tag)
    {
        case '.':
        {
            return std::make_unique<WriteNumberInstruction>(*m_consoleWriter);
        }
        case ',':
        {
            return std::make_unique<WriteASCIIInstruction>(*m_consoleWriter);
        }
        case '&':
        {
            return std::make_unique<ReadNumberInstruction>(*m_consoleReader);
        }
        case '~':
        {
            return std::make_unique<ReadASCIIInstruction>(*m_consoleReader);
        }
        default:
        {
            return nullptr;
        }
    }
}
}//namespace befunge
