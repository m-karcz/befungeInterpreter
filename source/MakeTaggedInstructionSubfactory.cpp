#include "MakeTaggedInstructionSubfactory.hpp"
#include "TaggedInstructionSubfactory.hpp"
#include "BinaryOpInstruction.hpp"
#include "UnaryOpInstruction.hpp"
#include "ChangeMovementInstruction.hpp"
#include "NopInstruction.hpp"
#include "SkipInstruction.hpp"
#include "HaltInstruction.hpp"
#include "ReadStreamInstruction.hpp"

namespace befunge
{
std::unique_ptr<IInstructionSubfactory> makeTaggedInstructionSubfactory()
{
    return std::make_unique<TaggedInstructionSubfactory<AddInstruction,
                                                        SubInstruction,
                                                        MulInstruction,
                                                        DivInstruction,
                                                        ModInstruction,
                                                        CmpInstruction,
                                                        NotInstruction,
                                                        TwiceInstruction,
                                                        TurnLeftInstruction,
                                                        TurnRightInstruction,
                                                        TurnUpInstruction,
                                                        TurnDownInstruction,
                                                        NopInstruction,
                                                        SkipInstruction,
                                                        HaltInstruction,
                                                        ReadStreamInstruction>>();
                                                                
}
}//namespace
