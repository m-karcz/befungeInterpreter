#include "Interpreter.hpp"


int main()
{
    befunge::Interpreter interpreter{"hello_world.bfg"};

    interpreter.run();

    return 0;
}
