#pragma once

#include "IMovement.hpp"
#include <stdexcept>

namespace befunge
{
struct Movement : IMovement
{
    void setDirection(Direction p_direction) override
    {
        m_direction = p_direction;
    }
    void makeStep()
    {
        switch(m_direction)
        {
            case Direction::Right:
            {
                m_position.x++;
                return;
            }
            case Direction::Left:
            {
                m_position.x--;
                return;
            }
            case Direction::Up:
            {
                m_position.y--;
                return;
            }
            case Direction::Down:
            {
                m_position.y++;
                return;
            }
            default:
            {
                throw std::logic_error{"Nonexistent direction"};
            }
        }
    }
    Position getPosition() override
    {
        return m_position;
    }
private:
    Position m_position{0,0};
    Direction m_direction{Direction::Right};
};
}//namespace befunge
