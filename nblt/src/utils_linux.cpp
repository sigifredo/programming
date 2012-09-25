
#ifdef linux

// Own
#include <utils.hpp>

// POSIX
#include <sys/ioctl.h>

void getTermSize(int& iRows, int& iCols)
{
    struct winsize ws;

    ioctl(1, TIOCGWINSZ, &ws);
    iCols = ws.ws_col;
    iRows = ws.ws_row;
}

#endif
