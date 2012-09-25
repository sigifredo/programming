
// Own
#include <utils.hpp>

// C
#include <cstdio>

void horizontalLine()
{
    int iCols, iRows;
    getTermSize(iRows, iCols);

    for(int i = 0; i < iCols; i++)
        std::printf("\x2d");

    std::printf("\n");
}
