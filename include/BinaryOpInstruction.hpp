#pragma once

#include "Tagged.hpp"
#include "IInstruction.hpp"
#include "IContext.hpp"
#include <functional>

namespace befunge
{
template<typename BinaryOp>
struct BinaryOpInstruction : IInstruction
{
    void execute(IContext& p_context)
    {
        IStack& l_stack = p_context.getStack();
        number_t l_rhs = l_stack.pop();
        number_t l_lhs = l_stack.pop();

        number_t l_result = BinaryOp{}(l_lhs, l_rhs);

        l_stack.push(l_result);
    }
};

template<char Code, typename BinaryOp>
struct TaggedBinaryOpInstruction : Tagged<Code>,
                                   BinaryOpInstruction<BinaryOp>
{};

using AddInstruction = TaggedBinaryOpInstruction<'+', std::plus<number_t>>;
using SubInstruction = TaggedBinaryOpInstruction<'-', std::minus<number_t>>;
using MulInstruction = TaggedBinaryOpInstruction<'*', std::multiplies<number_t>>;
using DivInstruction = TaggedBinaryOpInstruction<'/', std::divides<number_t>>;
using ModInstruction = TaggedBinaryOpInstruction<'%', std::modulus<number_t>>;
using CmpInstruction = TaggedBinaryOpInstruction<'`', std::greater<number_t>>;
}//namespace befunge
