
#include <Date.hpp>

#include <string>

std::istream& operator>>(std::istream &infile, Date date)
{
    std::string str;
    infile >> str;

    const char * c = str.c_str();

    date.year = std::atoi(c + 6);
    date.month = std::atoi(c + 3);
    date.day = std::atoi(c );

    return infile;
}
