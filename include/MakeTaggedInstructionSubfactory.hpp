#pragma once

#include "IInstructionSubfactory.hpp"

namespace befunge
{
std::unique_ptr<IInstructionSubfactory> makeTaggedInstructionSubfactory();
}//namespace befunge
