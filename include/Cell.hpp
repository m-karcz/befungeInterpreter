#pragma once

#include "ICell.hpp"

namespace befunge
{
struct Cell : ICell
{
    explicit Cell(char p_value) :
        m_value{p_value}
    {}
    char get() const override
    {
        return m_value;
    }
    void set(char p_value) override
    {
        p_value = m_value;
    }
private:
    char m_value;
};
}//namespace befunge
