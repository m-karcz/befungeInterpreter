#pragma once

#include <fstream>
#include <algorithm>
#include "Cell.hpp"
#include "Grid.hpp"
#include "InstructionFactory.hpp"
#include "Stack.hpp"
#include "Context.hpp"
#include <memory>
#include "Movement.hpp"
#include "MakeTaggedInstructionSubfactory.hpp"
#include "ConsoleReader.hpp"
#include "ConsoleWriter.hpp"
#include "IOInstructionSubfactory.hpp"

namespace befunge
{
struct Interpreter
{
    explicit Interpreter(const char* p_fileName)
    {
        //straightforward initialization
        std::ifstream file{p_fileName};
        std::string line;
        std::vector<std::vector<Cell>> cells;
        while(std::getline(file, line))
        {
            std::vector<Cell> cellsLine;
            std::transform(line.begin(),
                           line.end(),
                           std::back_inserter(cellsLine),
                           [](char c){return Cell{c};});
            cells.push_back(std::move(cellsLine));
        }

        m_context = std::make_unique<Context>(
                        std::make_unique<Stack>(),
                        std::make_unique<Movement>(),
                        std::make_unique<Grid>(std::move(cells)));

        std::vector<std::unique_ptr<IInstructionSubfactory>> subfactories;
        subfactories.push_back(makeTaggedInstructionSubfactory());
        subfactories.push_back(std::make_unique<IOInstructionSubfactory>(std::make_unique<ConsoleReader>(std::cin),
                                                                         std::make_unique<ConsoleWriter>(std::cout)));
        m_instructionFactory = std::make_unique<InstructionFactory>(std::move(subfactories));
    }
    void run()
    {
        while(m_context->isRunning())
        {
            Position actualPos = m_context->getMovement().getPosition();
            char tag = m_context->getGrid().getCell(actualPos).get();

            auto instruction = m_instructionFactory->makeInstruction(tag);

            instruction->execute(*m_context);

            m_context->getMovement().makeStep();
        }
    }
    std::unique_ptr<IContext> m_context;
    std::unique_ptr<IInstructionFactory> m_instructionFactory;
};
}//namespace befunge
