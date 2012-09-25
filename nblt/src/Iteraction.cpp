
#include <Iteraction.hpp>

#include <istream>

std::istream& operator>>(std::istream &infile, Iteraction it)
{
    infile >> it.id;

    for(int i = 0; i < 6; i++)
        infile >> it.responses[i];

    infile >> it.date;

    return infile;
}
