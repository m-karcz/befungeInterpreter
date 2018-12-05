#pragma once

#include "Tagged.hpp"
#include "IInstruction.hpp"
#include "IContext.hpp"
#include <functional>

namespace befunge
{
template<typename UnaryOp>
struct UnaryOpInstruction : IInstruction
{
    void execute(IContext& p_context)
    {
        IStack& l_stack = p_context.getStack();
        number_t l_value = l_stack.pop();

        number_t l_result = UnaryOp{}(l_value);

        l_stack.push(l_result);
    }
};

template<char Code, typename UnaryOp>
struct TaggedUnaryOpInstruction : Tagged<Code>,
                                  UnaryOpInstruction<UnaryOp>
{};

struct MultiplyByTwo
{
    constexpr number_t operator()(number_t value) const
    {
        return 2 * value;
    }
};

using NotInstruction = TaggedUnaryOpInstruction<'!', std::logical_not<number_t>>;
using TwiceInstruction = TaggedUnaryOpInstruction<':', MultiplyByTwo>;
}//namespace befunge
