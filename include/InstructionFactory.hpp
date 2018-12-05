#pragma once

#include "IInstructionFactory.hpp"
#include <iostream>

namespace befunge
{
struct InstructionFactory : IInstructionFactory
{
    explicit InstructionFactory(std::vector<std::unique_ptr<IInstructionSubfactory>> p_subfactories) :
        m_subfactories{std::move(p_subfactories)}
    {}
    std::unique_ptr<IInstruction> makeInstruction(char p_tag) override
    {
        for(auto& l_subfactory : m_subfactories)
        {
            auto l_instruction = l_subfactory->makeInstruction(p_tag);
            if(l_instruction)
            {
                return l_instruction;
            }
        }
        throw std::logic_error{std::string{"Non-existent instruction: "} + p_tag};
    }
private:
    std::vector<std::unique_ptr<IInstructionSubfactory>> m_subfactories;
};
}//namespace befugne
