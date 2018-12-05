#pragma once

#include "IConsoleWriter.hpp"
#include <ostream>

namespace befunge
{
struct ConsoleWriter : IConsoleWriter
{
    explicit ConsoleWriter(std::ostream& p_ostream) :
        m_ostream{p_ostream}
    {}
    void writeASCII(char p_value) override
    {
        m_ostream << p_value;
    }
    void writeNumber(number_t p_value) override
    {
        m_ostream << p_value;
    }
private:
    std::ostream& m_ostream;
};
}//namespace befunge
