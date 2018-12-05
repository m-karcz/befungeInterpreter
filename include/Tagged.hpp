#pragma once


namespace befunge
{
template<char Code>
struct Tagged
{
    constexpr static char tag = Code;
};

}//namespace befunge
