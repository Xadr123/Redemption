#include <iostream>

#include "core.h"
#include "board.h"
#include "bitboards.h"
#include "magics.h"

using namespace Redemption;

int main()
{
    Bitboards::initBitboards();
    Magics::initMagics();

    return 0;
}
