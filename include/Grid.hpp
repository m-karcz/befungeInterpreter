#pragma once

#include "IGrid.hpp"
#include "Cell.hpp"
#include <vector>

namespace befunge
{
struct Grid : IGrid
{
    explicit Grid(std::vector<std::vector<Cell>> p_cells) :
        m_cells{std::move(p_cells)}
    {}
    const ICell& getCell(const Position& p_position) const override
    {
        return m_cells[p_position.y][p_position.x];
    }
    ICell& getCell(const Position& p_position) override
    {
        return const_cast<ICell&>(static_cast<const Grid&>(*this).getCell(p_position));
    }
private:
    std::vector<std::vector<Cell>> m_cells;
};
}//namespace befunge
