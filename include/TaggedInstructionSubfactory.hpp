#pragma once

#include "IInstructionSubfactory.hpp"
#include <map>
#include <utility>

#include <iostream>

namespace befunge
{
typedef std::unique_ptr<IInstruction> (*instructionPtrFunc)();

template<typename TaggedInstructionType>
auto makeMaker()
{
    return std::make_pair(TaggedInstructionType::tag, []()->std::unique_ptr<IInstruction>{return std::make_unique<TaggedInstructionType>();});
}

template<typename... TaggedInstructions>
struct TaggedInstructionSubfactory : IInstructionSubfactory
{
    std::unique_ptr<IInstruction> makeInstruction(char p_tag) override
    {
        auto it = m_makers.find(p_tag);
        if(it != m_makers.end())
        {
            return it->second();
        }

        return nullptr;
    }
private:
    std::map<char, instructionPtrFunc> m_makers{{makeMaker<TaggedInstructions>()...}};
};
}//namespace befunge
