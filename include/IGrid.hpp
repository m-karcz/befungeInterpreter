#pragma once

#include "ICell.hpp"
#include "Position.hpp"

namespace befunge
{
struct IGrid
{
    virtual ICell& getCell(const Position& p_position) = 0;
    virtual const ICell& getCell(const Position& p_position) const = 0;
    virtual ~IGrid() = default;
};
}//namespace befunge
