#pragma once

#include "IConsoleReader.hpp"
#include <istream>

namespace befunge
{
struct ConsoleReader : IConsoleReader
{
    explicit ConsoleReader(std::istream& p_istream) :
        m_istream{p_istream}
    {}
    char readASCII() override
    {
        return readT<char>();
    }
    number_t readNumber() override
    {
        return readT<number_t>();
    }
private:
    std::istream& m_istream;
    template<typename T>
    inline T readT()
    {
        T l_value;
        m_istream >> l_value;
        return l_value;
    }
};
}//namespace befunge
